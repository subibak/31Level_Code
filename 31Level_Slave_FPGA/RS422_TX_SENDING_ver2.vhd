library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

entity RS422_TX_SENDING_ver2 is
	port(
			OP_CLK				: in std_logic; 										-- Sending Clock 5 MHz
			RSTn					: in std_logic;
			READY_ENn			: in std_logic;
		
			DATA_IN 				: in std_logic_vector(303 downto 0);
			
			TX_SERIAL_OUT		: out std_logic 
	);
	
end RS422_TX_SENDING_ver2;

architecture SENDING of RS422_TX_SENDING_ver2 is

	signal Flag_start 				: std_logic := '0';
	signal Flag_shift 				: std_logic := '0';
	signal Flag_stop 					: std_logic := '0';
	signal Flag_clr  					: std_logic := '0';

	signal TX_out_buffer				: std_logic := '1';
	signal TX_reg 						: std_logic_vector(303 downto 0) := (others => '1');
	
	signal SEND_cnt 					: integer range 0 to 304 := 0;
			
	type STATETYPE is (IDLE, START, SENDING, STOP);
	signal State 						: STATETYPE := IDLE;
	signal Next_State  				: STATETYPE := IDLE;
	
begin
	
	TX_SERIAL_OUT <= TX_out_buffer;
	
	SENDING_OPERATION : process(RSTn, OP_CLK, DATA_IN)
	begin
		if RSTn = '0' then
			
			TX_reg <= DATA_IN;
			TX_out_buffer <= '1';
			SEND_cnt <= 0;
			State <= IDLE;
			
		elsif OP_CLK'event and OP_CLK = '1' then
			
			State <= Next_State;
			
			if Flag_start = '1' then
				Tx_out_buffer <= '0';
			end if;
			if Flag_shift = '1' then
				TX_out_buffer <= TX_reg(0);
				TX_reg <= '1' & TX_reg(303 downto 1);
				SEND_cnt <= SEND_cnt + 1;
			elsif Flag_clr = '1' then
				SEND_cnt <= 0;
			end if;
			if Flag_stop = '1' then
				TX_out_buffer <= '1';
				SEND_cnt <= 0;
			end if;
		end if;
	
	end process;
		
	
	NEXT_STATE_SWITCH : process(State, READY_ENn, SEND_cnt)
	begin
		
		Flag_start <= '0';
		Flag_shift <= '0';
		Flag_stop <= '0';
		Flag_clr <= '0';
		
		case State is
			when IDLE =>
				if READY_ENn = '0' then
					Next_State <= START;
				else
					Next_State <= IDLE;
				end if;
			when START =>
				Flag_start <= '1';
				Next_State <= SENDING;
			when SENDING =>
				if SEND_cnt < 304 then
					Flag_shift <= '1';
					Next_State <= SENDING;
				else
					Flag_clr	<= '1';
					Next_State <= STOP;
				end if;
			when STOP =>
				Flag_stop <= '1';
				Next_State <= IDLE;
			when others =>
				Next_State <= IDLE;
		end case;
	
	end process;
	
end SENDING;