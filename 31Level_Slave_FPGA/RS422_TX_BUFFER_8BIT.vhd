library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity RS422_TX_BUFFER_8BIT is 
	
	port(
			OP_CLK			: 	in std_logic;
			EMIF_ADDR		:	in std_logic_vector(11 downto 0);
			EM1CS2n			:	in std_logic;
			EM1WEn			: 	in std_logic;
			EMIF_DATA		:  in std_logic_vector(15 downto 0);	
			
			
--			DATA_OUT			:  out std_logic_vector(7 downto 0)
			DATA_OUT			:  out std_logic_vector(37900 downto 0)
		);
		
end RS422_TX_BUFFER_8BIT;

 
architecture TX_BUFFER of RS422_TX_BUFFER_8BIT is
	
	signal Num_reg				: std_logic_vector(9 downto 0) := (others => '0');
	signal Fau_reg				: std_logic_vector(9 downto 0) := (others => '0');

	signal Data_reg			: std_logic_vector(379 downto 0) := (others => '0');
--	signal Data_reg			: std_logic_vector(7 downto 0) := (others => '0');
	
	type TEMP_MEM is array (0 to 11) of std_logic_vector(9 downto 0);
	signal Tem_MSB_reg 			: TEMP_MEM;
	signal Tem_LSB_reg			: TEMP_MEM;
	
	type VOL_MEM is array (0 to 5) of std_logic_vector(9 downto 0);
	signal Vol_MSB_reg				: VOL_MEM;
	signal Vol_LSB_reg				: VOL_MEM;

begin
	DECODING : process(OP_CLK, EMIF_ADDR, EM1CS2n, EM1WEn)
	begin
		if OP_CLK'event and OP_CLK = '1' then
			if EMIF_ADDR = "000000000100" and EM1CS2n = '0' and EM1WEn = '0' then
				Num_reg <= '1' & EMIF_DATA(7 downto 0) & '0';
			end if;	

			if EMIF_ADDR = "000000000101" and EM1CS2n = '0' and EM1WEn = '0' then
				Fau_reg <= '1' & EMIF_DATA(7 downto 0) & '0';
			end if;				

			if EMIF_ADDR = "000001010000" and EM1CS2n = '0' and EM1WEn = '0' then
				Tem_LSB_reg(0) <= '1' & EMIF_DATA(7 downto 0) & '0';
				Tem_MSB_reg(0) <= '1' & EMIF_DATA(15 downto 8) & '0';
			end if;		
			if EMIF_ADDR = "000001010001" and EM1CS2n = '0' and EM1WEn = '0' then
				Tem_LSB_reg(1) <= '1' & EMIF_DATA(7 downto 0) & '0';
				Tem_MSB_reg(1) <= '1' & EMIF_DATA(15 downto 8) & '0';
			end if;					
			if EMIF_ADDR = "000001010010" and EM1CS2n = '0' and EM1WEn = '0' then
				Tem_LSB_reg(2) <= '1' & EMIF_DATA(7 downto 0) & '0';
				Tem_MSB_reg(2) <= '1' & EMIF_DATA(15 downto 8) & '0';
			end if;		
			if EMIF_ADDR = "000001010011" and EM1CS2n = '0' and EM1WEn = '0' then
				Tem_LSB_reg(3) <= '1' & EMIF_DATA(7 downto 0) & '0';
				Tem_MSB_reg(3) <= '1' & EMIF_DATA(15 downto 8) & '0';
			end if;		
			if EMIF_ADDR = "000001010100" and EM1CS2n = '0' and EM1WEn = '0' then
				Tem_LSB_reg(4) <= '1' & EMIF_DATA(7 downto 0) & '0';
				Tem_MSB_reg(4) <= '1' & EMIF_DATA(15 downto 8) & '0';
			end if;	
			if EMIF_ADDR = "000001010101" and EM1CS2n = '0' and EM1WEn = '0' then
				Tem_LSB_reg(5) <= '1' & EMIF_DATA(7 downto 0) & '0';
				Tem_MSB_reg(5) <= '1' & EMIF_DATA(15 downto 8) & '0';
			end if;		
			if EMIF_ADDR = "000001010110" and EM1CS2n = '0' and EM1WEn = '0' then
				Tem_LSB_reg(6) <= '1' & EMIF_DATA(7 downto 0) & '0';
				Tem_MSB_reg(6) <= '1' & EMIF_DATA(15 downto 8) & '0';
			end if;
			if EMIF_ADDR = "000001010111" and EM1CS2n = '0' and EM1WEn = '0' then
				Tem_LSB_reg(7) <= '1' & EMIF_DATA(7 downto 0) & '0';
				Tem_MSB_reg(7) <= '1' & EMIF_DATA(15 downto 8) & '0';
			end if;			
			if EMIF_ADDR = "000001011000" and EM1CS2n = '0' and EM1WEn = '0' then
				Tem_LSB_reg(8) <= '1' & EMIF_DATA(7 downto 0) & '0';
				Tem_MSB_reg(8) <= '1' & EMIF_DATA(15 downto 8) & '0';
			end if;	
			if EMIF_ADDR = "000001011001" and EM1CS2n = '0' and EM1WEn = '0' then
				Tem_LSB_reg(9) <= '1' & EMIF_DATA(7 downto 0) & '0';
				Tem_MSB_reg(9) <= '1' & EMIF_DATA(15 downto 8) & '0';
			end if;	
			if EMIF_ADDR = "000001011010" and EM1CS2n = '0' and EM1WEn = '0' then
				Tem_LSB_reg(10) <= '1' & EMIF_DATA(7 downto 0) & '0';
				Tem_MSB_reg(10) <= '1' & EMIF_DATA(15 downto 8) & '0';
			end if;	
			if EMIF_ADDR = "000001011011" and EM1CS2n = '0' and EM1WEn = '0' then
				Tem_LSB_reg(11) <= '1' & EMIF_DATA(7 downto 0) & '0';
				Tem_MSB_reg(11) <= '1' & EMIF_DATA(15 downto 8) & '0';
			end if;	

			if EMIF_ADDR = "000001100000" and EM1CS2n = '0' and EM1WEn = '0' then
				Vol_LSB_reg(0) <= '1' & EMIF_DATA(7 downto 0) & '0';
				Vol_MSB_reg(0) <= '1' & EMIF_DATA(15 downto 8) & '0';
			end if;	
			if EMIF_ADDR = "000001100001" and EM1CS2n = '0' and EM1WEn = '0' then
				Vol_LSB_reg(1) <= '1' & EMIF_DATA(7 downto 0) & '0';
				Vol_MSB_reg(1) <= '1' & EMIF_DATA(15 downto 8) & '0';
			end if;			
			if EMIF_ADDR = "000001100010" and EM1CS2n = '0' and EM1WEn = '0' then
				Vol_LSB_reg(2) <= '1' & EMIF_DATA(7 downto 0) & '0';
				Vol_MSB_reg(2) <= '1' & EMIF_DATA(15 downto 8) & '0';
			end if;		
			if EMIF_ADDR = "000001100011" and EM1CS2n = '0' and EM1WEn = '0' then
				Vol_LSB_reg(3) <= '1' & EMIF_DATA(7 downto 0) & '0';
				Vol_MSB_reg(3) <= '1' & EMIF_DATA(15 downto 8) & '0';
			end if;		
			if EMIF_ADDR = "000001100100" and EM1CS2n = '0' and EM1WEn = '0' then
				Vol_LSB_reg(4) <= '1' & EMIF_DATA(7 downto 0) & '0';
				Vol_MSB_reg(4) <= '1' & EMIF_DATA(15 downto 8) & '0';
			end if;	
			if EMIF_ADDR = "000001100101" and EM1CS2n = '0' and EM1WEn = '0' then
				Vol_LSB_reg(5) <= '1' & EMIF_DATA(7 downto 0) & '0';
				Vol_MSB_reg(5) <= '1' & EMIF_DATA(15 downto 8) & '0';
			end if;	
			if EMIF_ADDR = "000000001000" and EM1CS2n = '0' and EM1WEn = '0' then
				Data_reg(379 downto 0) <= --Num_reg;
								 Vol_MSB_reg(5) & Vol_LSB_reg(5) & Vol_MSB_reg(4) & Vol_LSB_reg(4) & Vol_MSB_reg(3) & Vol_LSB_reg(3) 
								& Vol_MSB_reg(2) & Vol_LSB_reg(2) & Vol_MSB_reg(1) & Vol_LSB_reg(1) & Vol_MSB_reg(0) & Vol_LSB_reg(0)
								& Tem_MSB_reg(11) & Tem_LSB_reg(11) & Tem_MSB_reg(10) & Tem_LSB_reg(10) & Tem_MSB_reg(9) & Tem_LSB_reg(9) 
								& Tem_MSB_reg(8) & Tem_LSB_reg(8) & Tem_MSB_reg(7) & Tem_LSB_reg(7) & Tem_MSB_reg(6) & Tem_LSB_reg(6)
								& Tem_MSB_reg(5) & Tem_LSB_reg(5) & Tem_MSB_reg(4) & Tem_LSB_reg(4) & Tem_MSB_reg(3) & Tem_LSB_reg(3) 
								& Tem_MSB_reg(2) & Tem_LSB_reg(2) & Tem_MSB_reg(1) & Tem_LSB_reg(1) & Tem_MSB_reg(0) & Tem_LSB_reg(0)
								& Fau_reg & Num_reg; 
			end if;
		end if;
	end process;

	DATA_OUT <= Data_reg;

end TX_BUFFER;
	
