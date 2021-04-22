library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity RS422_TX_8BIT_VER3 is
	port(
			OP_CLK			: 	in std_logic;
			EMIF_ADDR		:	in std_logic_vector(11 downto 0);
			EM1CS2n			:	in std_logic;
			EM1WEn			: 	in std_logic;
			EMIF_DATA		:  in std_logic_vector(15 downto 0);	

			SENDING_CLK		: in std_logic; 										-- Sending Clock 5 MHz
			SETn				: in std_logic;
			
			TX_SERIAL_OUT	: out std_logic;
			TX_INDICATOR	: out std_logic
	);
	
end RS422_TX_8BIT_VER3;

architecture arch of RS422_TX_8BIT_VER3 is

	
	------ buffer
	signal DAQ_TX_IND   		: integer range 0 to 4100 := 0;
	signal MEM_CPY 			: integer range 0 to 700 := 0;

	signal Num_reg				: std_logic_vector(9 downto 0) := (others => '0');
	signal Fau_reg				: std_logic_vector(9 downto 0) := (others => '0');

	signal Data_reg			: std_logic_vector(19 downto 0) := (others => '0');
	
	signal TX_INDICATOR_reg : std_logic := '0';
	
	type TX_VOL_MEM is array (0 to 667) of std_logic_vector(19 downto 0);
	signal TX_VOL1_reg			: TX_VOL_MEM;
	signal TX_VOL2_reg			: TX_VOL_MEM;
	signal TX_VOL3_reg			: TX_VOL_MEM;
	signal TX_VOL4_reg			: TX_VOL_MEM;
	signal TX_VOL5_reg			: TX_VOL_MEM;
	signal TX_VOL6_reg			: TX_VOL_MEM;
	
	type TX_EX_MEM is array (0 to 21) of std_logic_vector(19 downto 0);
	signal TX_EX_reg				: TX_EX_MEM;
	
	------ sending
	signal Flag_shift 				: std_logic := '0';
	signal Flag_clr  					: std_logic := '0';
	signal Flag_index_inc1			: std_logic := '0';
	signal Flag_index_inc2			: std_logic := '0';

	signal TX_out_buffer				: std_logic := '1';
	signal TX_reg_in					: std_logic_vector(439 downto 0) := (others => '1');
	signal TX_reg_out					: std_logic_vector(439 downto 0) := (others => '1');
	
	signal SEND_cnt 					: integer := 0;
	signal SET_cnt_MAX				: integer := 0;
	signal TX_INDEX					: integer := 0;
	signal TINDEX1						: integer range 0 to 400 := 0;
	signal TINDEX2						: integer range 0 to 400 := 0;
	
	type STATETYPE is (IDLE, REQUEST, STORE, SENDING);
	signal State 						: STATETYPE := IDLE;
	signal Next_State  				: STATETYPE := IDLE;
	
begin
	
	TX_SERIAL_OUT <= TX_out_buffer;
	
	--LED_INDICATOR
	TX_LED_INDICAOTR_OP : process(OP_CLK, State)
	begin
		if OP_CLK'event and OP_CLK = '1' then
			if STATE = SENDING then
				TX_INDICATOR_reg <= '1';
			else
				TX_INDICATOR_reg <= '0';
			end if;
		end if;
		
		TX_INDICATOR <= TX_INDICATOR_reg;
	end process;
	
	
	-- Buffer
	MEM_STORE : process(OP_CLK, EMIF_ADDR, EM1CS2n, EM1WEn)
	begin
		if OP_CLK'event and OP_CLK = '1' then
			--DAQ_TX_INDEX	
			if EMIF_ADDR = "000000110111" and EM1CS2n = '0' and EM1WEn = '0' then
				DAQ_TX_IND <= conv_integer(EMIF_DATA(15 downto 0));
			end if;	
			--SM Volatge 1(A1)
			if EMIF_ADDR = "000001100000" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_VOL1_reg(DAQ_TX_IND) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
			--SM Volatge 2(A2)
			if EMIF_ADDR = "000001100001" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_VOL2_reg(DAQ_TX_IND) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
			--SM Volatge 3(A3)		
			if EMIF_ADDR = "000001100010" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_VOL3_reg(DAQ_TX_IND) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
			--SM Volatge 4(B1)
			if EMIF_ADDR = "000001100011" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_VOL4_reg(DAQ_TX_IND) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
			--SM Volatge 5(B2)
			if EMIF_ADDR = "000001100100" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_VOL5_reg(DAQ_TX_IND) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
			--SM Volatge 6(B3)	
			if EMIF_ADDR = "000001100101" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_VOL6_reg(DAQ_TX_IND) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;	
			
			--TMPERATURE 1_UPPER(A1) 4008
			if EMIF_ADDR = "000001010000" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_EX_reg(0) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;		
			--TMPERATURE 1_LOWER(A1) 4009
			if EMIF_ADDR = "000001010001" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_EX_reg(1) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;					
			--TMPERATURE 2_UPPER(A2) 4010
			if EMIF_ADDR = "000001010010" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_EX_reg(2) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;		
			--TMPERATURE 2_LOWER(A2) 4011
			if EMIF_ADDR = "000001010011" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_EX_reg(3) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
			--TMPERATURE 3_UPPER(A3) 4012
			if EMIF_ADDR = "000001010100" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_EX_reg(4) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
		   --TMPERATURE 3_LOWER(A3) 4013	
			if EMIF_ADDR = "000001010101" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_EX_reg(5) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
			--TMPERATURE 1_UPPER(B1) 4014
			if EMIF_ADDR = "000001010110" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_EX_reg(6) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
			--TMPERATURE 1_LOWER(B1) 4015
			if EMIF_ADDR = "000001010111" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_EX_reg(7) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;			
			--TMPERATURE 2_UPPER(B2) 4016
			if EMIF_ADDR = "000001011000" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_EX_reg(8) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;	
			--TMPERATURE 2_LOWER(B2) 4017
			if EMIF_ADDR = "000001011001" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_EX_reg(9) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;	
			--TMPERATURE 3_UPPER(B3) 4018
			if EMIF_ADDR = "000001011010" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_EX_reg(10) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;	
			--TMPERATURE 3_LOWER(B3) 4019
			if EMIF_ADDR = "000001011011" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_EX_reg(11) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;	

			--FAULT 4020
			if EMIF_ADDR = "000000000101" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_EX_reg(12) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;	
			
			--Group_moudle number 4021
			if EMIF_ADDR = "000000000100" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_EX_reg(13) <= '1' & "00000000" & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;	
			
			--EX1 4022
			if EMIF_ADDR = "000001100110" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_EX_reg(14) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
			--EX2 4023
			if EMIF_ADDR = "000001100111" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_EX_reg(15) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
			--EX3 4024
			if EMIF_ADDR = "000001101000" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_EX_reg(16) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
			--EX4 4025
			if EMIF_ADDR = "000001101001" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_EX_reg(17) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
			--EX5 4026
			if EMIF_ADDR = "000001101010" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_EX_reg(18) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
			--EX6 4027
			if EMIF_ADDR = "000001101011" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_EX_reg(19) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
			--EX7 4028
			if EMIF_ADDR = "000001101100" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_EX_reg(20) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
			--EX8 4029
			if EMIF_ADDR = "000001101101" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_EX_reg(21) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
		end if;
	end process;
		
	-- Sending
	SENDING_OPERATION : process(SETn, SENDING_CLK, TX_INDEX)
	begin
		
		if SETn = '0' then
			TX_out_buffer <= '1';
			SEND_cnt <= 0;
			TX_INDEX <= 0;
			State <= REQUEST;
		elsif SENDING_CLK'event and SENDING_CLK = '1' then
		
			State <= Next_State;
			if Flag_shift = '1' then
				TX_out_buffer <= TX_reg_out(SEND_cnt);
				SEND_cnt <= SEND_cnt + 1;
			elsif Flag_clr = '1' then
				TX_out_buffer <= '1';
				SEND_cnt <= 0;
			end if;
			
			if Flag_index_inc1 = '1' then
				SEND_cnt <= 0;
				TX_INDEX <= TX_INDEX + 1;	
			elsif Flag_index_inc2 = '1' then
				SEND_cnt <= 0;
				TX_INDEX <= TX_INDEX + 1;	
			end if;
			
		end if;
		
	end process;
			
	SENDING_STATE : process(State, SEND_cnt, TX_INDEX, TX_reg_in, SET_cnt_MAX)
	begin
		
		Flag_shift		 <= '0';
		Flag_clr 	    <= '0';
		Flag_index_inc1 <= '0';
		Flag_index_inc2 <= '0';
		
		case State is
			when IDLE =>
				Next_State <= IDLE;
			when REQUEST =>
				if TX_INDEX < 668 then
					SET_cnt_MAX <= 120;
					TX_reg_in(119 downto 0) <= TX_VOL6_reg(TX_INDEX) & TX_VOL5_reg(TX_INDEX) & TX_VOL4_reg(TX_INDEX) &
														TX_VOL3_reg(TX_INDEX) & TX_VOL2_reg(TX_INDEX) & TX_VOL1_reg(TX_INDEX);
				--	Flag_index_inc1 <= '1';
					Next_State <= STORE;
				elsif TX_INDEX = 668 then
					SET_cnt_MAX <= 440;
					TX_reg_in(439 downto 0) <= TX_EX_reg(21) & TX_EX_reg(20) & TX_EX_reg(19) & TX_EX_reg(18) & TX_EX_reg(17) & TX_EX_reg(16) & 
														TX_EX_reg(15) & TX_EX_reg(14) & TX_EX_reg(13) & TX_EX_reg(12) & TX_EX_reg(11) & TX_EX_reg(10) & 
														TX_EX_reg(9)  & TX_EX_reg(8)  & TX_EX_reg(7)  & TX_EX_reg(6)  & TX_EX_reg(5)  & TX_EX_reg(4)  & 
														TX_EX_reg(3)  & TX_EX_reg(2)  & TX_EX_reg(1)  & TX_EX_reg(0);
				--	Flag_index_inc2 <= '1';
					Next_State <= STORE;
				else
					Next_State <= IDLE;
				end if;
				
			when STORE =>
				TX_reg_out((SET_cnt_MAX-1) downto 0) <= TX_reg_in((SET_cnt_MAX-1) downto 0);
				Next_State <= SENDING;
			when SENDING =>
				if SEND_cnt < SET_cnt_MAX then
					Flag_shift <= '1';
					Next_State <= SENDING;
				else
					if TX_INDEX < 669 then
						Flag_clr	<= '1';
						Next_State <= REQUEST;
						Flag_index_inc1 <= '1';
					else
						Flag_clr	<= '1';
						Next_State <= IDLE;
					end if;
				end if;
			when others =>
				Next_State <= IDLE;
		end case;
	
	end process;
	
end arch;