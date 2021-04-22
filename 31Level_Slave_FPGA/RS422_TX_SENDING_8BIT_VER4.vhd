library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

entity RS422_TX_SENDING_8BIT_VER4 is
	port(
			OP_CLK				: in std_logic; 										-- Sending Clock xx MHz
			SETn					: in std_logic;
			
			DATA_IN 				: in std_logic_vector(19 downto 0);
			
			TX_SERIAL_OUT		: out std_logic;
			MEM_CALL				: out std_logic_vector(15 downto 0)
	);
	
end RS422_TX_SENDING_8BIT_VER4;

architecture SENDING of RS422_TX_SENDING_8BIT_VER4 is

	signal Flag_start 				: std_logic := '0';
	signal Flag_shift 				: std_logic := '0';
	signal Flag_stop 					: std_logic := '0';
	signal Flag_clr  					: std_logic := '0';

	signal TX_out_buffer				: std_logic := '1';
	signal TX_reg 						: std_logic_vector(19 downto 0) := (others => '1');
	
	signal SEND_cnt 					: integer range 0 to 30 := 0;
			
	type STATETYPE is (IDLE, REQUEST, STORE, SENDING);
	signal State 						: STATETYPE := IDLE;
	signal Next_State  				: STATETYPE := IDLE;
	
	signal Tx_cnt						: integer range 0 to 4100 := 0;
	signal MEM_CALL_reg				: std_logic_vector(15 downto 0) := "0000000000000000";
begin
	
	TX_SERIAL_OUT <= TX_out_buffer;
	
	SENDING_OPERATION : process(SETn, OP_CLK, DATA_IN)
	begin
		if SETn = '0' then
			TX_out_buffer <= '1';
			SEND_cnt <= 0;
			State <= REQUEST;
		elsif OP_CLK'event and OP_CLK = '1' then
			
			State <= Next_State;
			if Flag_shift = '1' then
				TX_out_buffer <= TX_reg(SEND_cnt);
				SEND_cnt <= SEND_cnt + 1;
			elsif Flag_clr = '1' then
				SEND_cnt <= 0;
				TX_out_buffer <= '1';
			end if;
		end if;
	
	end process;
	
	NEXT_STATE_SWITCH : process(State, SEND_cnt, DATA_IN, TX_cnt)
	begin
		
		Flag_shift <= '0';
		Flag_clr <= '0';
	
		case State is
			when IDLE =>
					Next_State <= IDLE;
			when REQUEST =>
					TX_cnt <= TX_cnt + 1;
					MEM_CALL <= conv_std_logic_vector(TX_cnt, 16);
					Next_State <= STORE;
			when STORE =>
					TX_reg <= DATA_IN;
					Next_State <= SENDING;
			when SENDING =>
				if SEND_cnt < 20 then
					Flag_shift <= '1';
					Next_State <= SENDING;
				else
					if TX_cnt < 4030 then
						Next_State <= REQUEST;
					else
						Flag_clr	<= '1';
						Next_State <= IDLE;
					end if;
				end if;
			when others =>
				Next_State <= IDLE;
		end case;
	
	end process;
	
end SENDING;