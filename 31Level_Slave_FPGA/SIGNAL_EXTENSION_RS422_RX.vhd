library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

entity SIGNAL_EXTENSION_RS422_RX is
	port(
			OP_CLK				: in std_logic; 										
			SETn					: in std_logic;
			DATA_IN				: in std_logic;
					
			DATA_OUT				: out std_logic 
	);
	
end SIGNAL_EXTENSION_RS422_RX;

architecture EXTENSION of SIGNAL_EXTENSION_RS422_RX is

	signal Flag_DATAin_clear			: std_logic := '0';
	signal Flag_DATAin_cnt				: std_logic := '0';
	signal DATAin_re						: std_logic := '1';
	signal DATAin_cnt						: integer range 0 to 11700  := 0;
			
	type STATETYPE is (IDLE, COUNT, STOP);
	signal State			: STATETYPE	:= IDLE;
	signal Next_State		: STATETYPE := IDLE;
	
begin
	
	DATA_OUT <= DATAin_re;
	
	SINGAL_EXTENSION_OP : process(OP_CLK, SETn)
	begin
		if SETn = '0' then
		
			DATAin_cnt <= 0;
			DATAin_re <= '1';
			State <= IDLE;
			
		elsif OP_CLK'event and OP_CLK = '1' then
			
			State <= Next_State;			
			
			if Flag_DATAin_cnt = '1' then
				DATAin_cnt <= DATAin_cnt + 1;
				DATAin_re <= '0';
				State <= Next_State;		
			end if;
			if Flag_DATAin_clear = '1' then
				DATAin_cnt <= 0;
				DATAin_re <= '1';
			end if;
			
		end if;
	end process;
		
	STATE_SWITCH : process(State, DATA_IN, DATAin_cnt)
	begin
		
		Flag_DATAin_clear  <= '0';
		Flag_DATAin_cnt	 <= '0';
		
		case State is 
			when IDLE =>
				if DATA_IN = '0' then
					Next_State <= COUNT;
				else
					Next_State <= IDLE;
				end if;
			when COUNT =>
				--RX_CLK 0.192 MHz  -> 5.208 us (signal extension 530 counts)
				--RX_CLK 1.152 MHz  -> 0.8685 us (signal extension 100 counts)
				--RX_CLK 2.3042 MHz -> 0.4340277 us (signal extension 50 counts)
				--RX_CLK 36.864 MHz -> 0.02712 us (signal extension 4 counts)
				--RX_CLK 18.432 MHz -> 0.05425 us (signal extension 7 counts)
				if DATAin_cnt < 50 then
					Flag_DATAin_cnt <= '1';
					Next_State <= COUNT;
				else
					Flag_DATAin_clear <= '1';
					Next_State <= IDLE;
				end if;
			when others =>
				Next_State <= IDLE;
		end case;
	end process;
		
end EXTENSION;
