library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

entity SIGNAL_EXTENSION_RS422_TX_reverse is
	port(
			OP_CLK				: in std_logic; 										
			SETn					: in std_logic;
			DATA_IN				: in std_logic;
					
			DATA_OUT				: out std_logic 
	);
	
end SIGNAL_EXTENSION_RS422_TX_reverse;

architecture EXTENSION of SIGNAL_EXTENSION_RS422_TX_reverse is

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
				DATAin_re <= '1';
				State <= Next_State;		
			end if;
			if Flag_DATAin_clear = '1' then
				DATAin_cnt <= 0;
				DATAin_re <= '0';
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
			   --0.0096 MHz -> 104.166 us (signal extension 11000 counts)
				--0.0576 MHz -> 17.361 us  (signal extension 1800  counts)
				--1.8432 MHz -> 0.5425 us  (signal extension 60  counts)
				if DATAin_cnt < 11000 then
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
