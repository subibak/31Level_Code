library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.all;

entity RS422_TX_SENDING_8BIT_VER3 is
	port(
			OP_CLK				: in std_logic; 										-- Sending Clock 5 MHz
			SETn					: in std_logic;
			
			Flag_ACK				: in std_logic;
			DATA_IN 				: in std_logic_vector(19 downto 0);
			
			TX_SERIAL_OUT		: out std_logic; 
			Flag_callout		: out std_logic;
			MEM_ACCESS_INDEX	: out std_logic_vector(15 downto 0)
	);
	
end RS422_TX_SENDING_8BIT_VER3;

architecture SENDING of RS422_TX_SENDING_8BIT_VER3 is

	signal Flag_start 				: std_logic := '0';
	signal Flag_shift 				: std_logic := '0';
	signal Flag_stop 					: std_logic := '0';
	signal Flag_clr  					: std_logic := '0';
	signal Flag_index_inc			: std_logic := '0';
	signal Flag_call					: std_logic := '0';

	signal TX_out_buffer				: std_logic := '1';
	signal TX_reg 						: std_logic_vector(19 downto 0) := (others => '1');
	
	signal SEND_cnt 					: integer range 0 to 100 := 0;
	signal TX_INDEX					: std_logic_vector(15 downto 0) := (others => '0');
			
	type STATETYPE is (IDLE, REQUEST, STORE, SENDING);
	signal State 						: STATETYPE := IDLE;
	signal Next_State  				: STATETYPE := IDLE;
	
begin
	
	Flag_callout		<= Flag_call;
	MEM_ACCESS_INDEX 	<= TX_INDEX;
	TX_SERIAL_OUT 		<= TX_out_buffer;
	
	SENDING_OPERATION : process(SETn, OP_CLK, TX_INDEX)
	begin
		if SETn = '0' then
			TX_out_buffer <= '1';
			SEND_cnt <= 0;
			TX_INDEX <= (others => '0');
			State <= REQUEST;
		elsif OP_CLK'event and OP_CLK = '1' then
			
			State <= Next_State;
			if Flag_shift = '1' then
				TX_out_buffer <= TX_reg(SEND_cnt);
				SEND_cnt <= SEND_cnt + 1;
			elsif Flag_clr = '1' then
				SEND_cnt <= 0;
				TX_out_buffer <= '1';
			elsif Flag_index_inc = '1' then
				SEND_cnt <= 0;
				TX_INDEX <= TX_INDEX + '1';
			elsif Flag_ACK = '1' then
				State <= STORE;
			end if;
			
		end if;
	 
	end process;
			
	NEXT_STATE_SWITCH : process(State, SEND_cnt, DATA_IN)
	begin
		
		Flag_shift		<= '0';
		Flag_clr 		<= '0';
		Flag_index_inc <= '0';
		
		case State is
			when IDLE =>
				Next_State <= IDLE;
			when REQUEST =>
				Flag_call <= '1';
				Next_State <= REQUEST;	
			when STORE =>
				Flag_call <= '0';
				TX_reg <= DATA_IN;
				Next_State <= SENDING;
			when SENDING =>
				if SEND_cnt < 20 then
					Flag_shift <= '1';
					Next_State <= SENDING;
				else
					if TX_INDEX < "0000111110111110" then
						Flag_index_inc <= '1';
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