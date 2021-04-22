library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity ADC_ADDRESS_DECODER is 

	port(
			OP_CLK					:	in std_logic;
			GPMC_ADDR				:	in std_logic_vector(11 downto 0);
						
			GPMC_CSn					:	in std_logic;
			GPMC_WEn					: 	in std_logic;
			GPMC_OEn					:	in std_logic;
			
			ADC_ALL_CVn				:	out std_logic;									-- 
			ADC_ALL_WRn				:	out std_logic;									-- 
			
			ADC0_CSn					:	out std_logic;									-- 		
			ADC1_CSn					:	out std_logic;									-- 	
			ADC2_CSn					:	out std_logic;									-- 	
			ADC3_CSn					:	out std_logic;									-- 		

			ADC0_RDn					:	out std_logic;									-- 		
			ADC1_RDn					:	out std_logic;									-- 		
			ADC2_RDn					:	out std_logic;									-- 		
			ADC3_RDn					:	out std_logic									-- 		
	);
		  
end ADC_ADDRESS_DECODER; 

architecture Decoder of ADC_ADDRESS_DECODER is
		
	signal ADC_ALL_CV_reg				: 	std_logic  := '1';									-- 
	signal ADC_ALL_WR_reg				:	std_logic  := '1';									-- 
	signal ADC_ALL_CS_reg				:	std_logic  := '1';
	signal ADC0_CS_reg					:	std_logic  := '1';									-- 		
	signal ADC1_CS_reg					:	std_logic  := '1';									-- 	
	signal ADC2_CS_reg					:	std_logic  := '1';									-- 	
	signal ADC3_CS_reg					:	std_logic  := '1';									-- 		
	signal ADC0_RD_reg					:	std_logic  := '1';									-- 		
	signal ADC1_RD_reg					:	std_logic  := '1';									-- 		
	signal ADC2_RD_reg					:	std_logic  := '1';									-- 		
	signal ADC3_RD_reg					:	std_logic  := '1';									-- 		

	begin 

	ADC_CONVERSTION : process(OP_CLK, GPMC_ADDR, GPMC_CSn, GPMC_WEn, ADC_ALL_CV_reg)
	begin
		
		ADC_ALL_CVn <= ADC_ALL_CV_reg;
		
		if OP_CLK'event and OP_CLK = '1' then
			if GPMC_ADDR = "000000000010" and GPMC_CSn = '0' and GPMC_WEn = '0' then
				ADC_ALL_CV_reg <= '0';
			elsif GPMC_ADDR = "000000000100" and GPMC_CSn = '0' and GPMC_WEn = '0' then
				ADC_ALL_CV_reg <= '1';
			end if;
		end if;
		
	end process;
	
	ADC_WRITE : process(OP_CLK, GPMC_ADDR, GPMC_CSn, GPMC_WEn, ADC_ALL_WR_reg)
	begin
		 
		ADC_ALL_WRn <= ADC_ALL_WR_reg;
		
		if OP_CLK'event and OP_CLK = '1' then
			if GPMC_ADDR = "000000000110" and GPMC_CSn = '0' and GPMC_WEn = '0' then
				ADC_ALL_WR_reg <= '0';
			elsif GPMC_ADDR = "000000001000" and GPMC_CSn = '0' and GPMC_WEn = '0' then
				ADC_ALL_WR_reg <= '1';
			end if;
		end if;
		
	end process;
	
	ADC_CHIP_SELECTION : process(OP_CLK, GPMC_ADDR, GPMC_CSn, GPMC_WEn, ADC0_CS_reg, ADC1_CS_reg, ADC2_CS_reg, ADC3_CS_reg)
	begin
		 
		ADC0_CSn <= ADC0_CS_reg;
		ADC1_CSn <= ADC1_CS_reg;
		ADC2_CSn <= ADC2_CS_reg;
		ADC3_CSn <= ADC3_CS_reg;
		
		if OP_CLK'event and OP_CLK = '1' then
			if GPMC_ADDR = "000000001010" and GPMC_CSn = '0' and GPMC_WEn = '0' then
				ADC0_CS_reg <= '0';
				ADC1_CS_reg <= '0';
				ADC2_CS_reg <= '0';
				ADC3_CS_reg <= '0';
			elsif GPMC_ADDR = "000000001100" and GPMC_CSn = '0' and GPMC_WEn = '0' then
				ADC0_CS_reg <= '1';
				ADC1_CS_reg <= '1';
				ADC2_CS_reg <= '1';
				ADC3_CS_reg <= '1';
			else
				if GPMC_ADDR = "000000001110" and GPMC_CSn = '0' and GPMC_WEn = '0' then
					ADC0_CS_reg <= '0';
				elsif GPMC_ADDR = "000000010000" and GPMC_CSn = '0' and GPMC_WEn = '0' then
					ADC0_CS_reg <= '1';
				end if;
				
				if GPMC_ADDR = "000000010010" and GPMC_CSn = '0' and GPMC_WEn = '0' then
					ADC1_CS_reg <= '0';
				elsif GPMC_ADDR = "000000010100" and GPMC_CSn = '0' and GPMC_WEn = '0' then
					ADC1_CS_reg <= '1';
				end if;
				
				if GPMC_ADDR = "000000010110" and GPMC_CSn = '0' and GPMC_WEn = '0' then
					ADC2_CS_reg <= '0';
				elsif GPMC_ADDR = "000000011000" and GPMC_CSn = '0' and GPMC_WEn = '0' then
					ADC2_CS_reg <= '1';
				end if;
				
				if GPMC_ADDR = "000000011010" and GPMC_CSn = '0' and GPMC_WEn = '0' then
					ADC3_CS_reg <= '0';
				elsif GPMC_ADDR = "000000011100" and GPMC_CSn = '0' and GPMC_WEn = '0' then
					ADC3_CS_reg <= '1';
				end if;
			end if;
		end if;
	end process;
		
	ADC_READ : process(OP_CLK, GPMC_ADDR, GPMC_CSn, GPMC_OEn, ADC0_RD_reg, ADC1_RD_reg, ADC2_RD_reg, ADC3_RD_reg)
	begin
		 
		ADC0_RDn <= ADC0_RD_reg;
		ADC1_RDn <= ADC1_RD_reg;
		ADC2_RDn <= ADC2_RD_reg;
		ADC3_RDn <= ADC3_RD_reg;

		if OP_CLK'event and OP_CLK = '1' then
			--ADC0  ADDR : 
			if GPMC_ADDR = "000000011110" and GPMC_CSn = '0' and GPMC_OEn = '0' then
				ADC0_RD_reg <= '0';
			else
				ADC0_RD_reg <= '1';
			end if;
			--ADC1
			if GPMC_ADDR = "000000100000" and GPMC_CSn = '0' and GPMC_OEn = '0' then
				ADC1_RD_reg <= '0';
			else
				ADC1_RD_reg <= '1';
			end if;
			--ADC2
			if GPMC_ADDR = "000000100010" and GPMC_CSn = '0' and GPMC_OEn = '0' then
				ADC2_RD_reg <= '0';
			else
				ADC2_RD_reg <= '1';
			end if;
			--ADC3
			if GPMC_ADDR = "000000100100" and GPMC_CSn = '0' and GPMC_OEn = '0' then
				ADC3_RD_reg <= '0';
			else
				ADC3_RD_reg <= '1';
			end if;
		end if;
		
	end process;

end Decoder;
