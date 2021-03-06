library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.all;

entity RS422_TX_BUFFER_8BIT_VER3 is 
	
	port(
			OP_CLK			: 	in std_logic;
			EMIF_ADDR		:	in std_logic_vector(11 downto 0);
			EM1CS2n			:	in std_logic;
			EM1WEn			: 	in std_logic;
			EMIF_DATA		:  in std_logic_vector(15 downto 0);
			Flag_call 		:  in std_logic;
			MEM_INDEX		:	in std_logic_vector(15 downto 0);
			
			Flag_ackout		: 	out std_logic;
			DATA_OUT			:  out std_logic_vector(19 downto 0)
		);
		
end RS422_TX_BUFFER_8BIT_VER3;

 
architecture TX_BUFFER of RS422_TX_BUFFER_8BIT_VER3 is
	
	signal DAQ_TX_IND   		: integer range 0 to 4100 := 0;
	signal MEM_INDEX_reg 	: integer range 0 to 4100 := 0;

	signal Num_reg				: std_logic_vector(9 downto 0) := (others => '0');
	signal Fau_reg				: std_logic_vector(9 downto 0) := (others => '0');

	signal Flag_ack			: std_logic := '0';
	signal Data_reg			: std_logic_vector(19 downto 0) := (others => '0');
	
	type TX_MEM is array (0 to 4029) of std_logic_vector(19 downto 0);
	signal TX_reg					: TX_MEM;
	signal TX_LSB_reg				: TX_MEM;

begin
	MEM_STORE : process(OP_CLK, EMIF_ADDR, EM1CS2n, EM1WEn)
	begin
		if OP_CLK'event and OP_CLK = '1' then
			--DAQ_TX_INDEX	
			if EMIF_ADDR = "000000110111" and EM1CS2n = '0' and EM1WEn = '0' then
				DAQ_TX_IND <= conv_integer(EMIF_DATA(15 downto 0));
			end if;	
			--Group_moudle number
			if EMIF_ADDR = "000000000100" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_reg(0) <= '1' & "00000000" & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;	
			--SM Volatge 1(A1)
			if EMIF_ADDR = "000001100000" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_reg(6*DAQ_TX_IND+1) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
			--SM Volatge 2(A2)
			if EMIF_ADDR = "000001100001" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_reg(6*DAQ_TX_IND+2) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
			--SM Volatge 3(A3)		
			if EMIF_ADDR = "000001100010" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_reg(6*DAQ_TX_IND+3) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
			--SM Volatge 4(B1)
			if EMIF_ADDR = "000001100011" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_reg(6*DAQ_TX_IND+4) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
			--SM Volatge 5(B2)
			if EMIF_ADDR = "000001100100" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_reg(6*DAQ_TX_IND+5) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
			--SM Volatge 6(B3)	
			if EMIF_ADDR = "000001100101" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_reg(6*DAQ_TX_IND+6) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;	
			
			--TMPERATURE 1_UPPER(A1)
			if EMIF_ADDR = "000001010000" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_reg(4009) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;		
			--TMPERATURE 1_LOWER(A1)
			if EMIF_ADDR = "000001010001" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_reg(4010) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;					
			--TMPERATURE 2_UPPER(A2)
			if EMIF_ADDR = "000001010010" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_reg(4011) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;		
			--TMPERATURE 2_LOWER(A2)
			if EMIF_ADDR = "000001010011" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_reg(4012) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
			--TMPERATURE 3_UPPER(A3)
			if EMIF_ADDR = "000001010100" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_reg(4013) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
		   --TMPERATURE 3_LOWER(A3)	
			if EMIF_ADDR = "000001010101" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_reg(4014) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
			--TMPERATURE 1_UPPER(B1)
			if EMIF_ADDR = "000001010110" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_reg(4015) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
			--TMPERATURE 1_LOWER(B1)
			if EMIF_ADDR = "000001010111" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_reg(4016) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;			
			--TMPERATURE 2_UPPER(B2)
			if EMIF_ADDR = "000001011000" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_reg(4017) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;	
			--TMPERATURE 2_LOWER(B2)
			if EMIF_ADDR = "000001011001" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_reg(4018) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;	
			--TMPERATURE 3_UPPER(B3)
			if EMIF_ADDR = "000001011010" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_reg(4019) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;	
			--TMPERATURE 3_LOWER(B3)
			if EMIF_ADDR = "000001011011" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_reg(4020) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;	

			--FAULT
			if EMIF_ADDR = "000000000101" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_reg(4021) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;	
			
			--EX1
			if EMIF_ADDR = "000001100110" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_reg(4022) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
			--EX2
			if EMIF_ADDR = "000000000111" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_reg(4023) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
			--EX3
			if EMIF_ADDR = "000000001000" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_reg(4024) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
			--EX4
			if EMIF_ADDR = "000000001001" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_reg(4025) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
			--EX5
			if EMIF_ADDR = "000000001010" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_reg(4026) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
			--EX6
			if EMIF_ADDR = "000000001011" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_reg(4027) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
			--EX7
			if EMIF_ADDR = "000000001100" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_reg(4028) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
			--EX8
			if EMIF_ADDR = "000000001101" and EM1CS2n = '0' and EM1WEn = '0' then
				TX_reg(4029) <= '1' & EMIF_DATA(15 downto 8) & '0' & '1' & EMIF_DATA(7 downto 0) & '0';
			end if;
	
		end if;
	end process;
	
	MEM_ACCESS : process(OP_CLK, EMIF_ADDR, EM1CS2n, EM1WEn)
	begin
		if OP_CLK'event and OP_CLK = '1' then
			if Flag_call = '1' then
				MEM_INDEX_reg <= conv_integer(MEM_INDEX);
				Data_reg <= TX_reg(MEM_INDEX_reg);
				Flag_ack <= '1';
			else
				Flag_ack <= '0';
			end if;
		end if;
	end process;
	
	Flag_ackout <= Flag_ack;
	DATA_OUT <= Data_reg;

end TX_BUFFER;
	
