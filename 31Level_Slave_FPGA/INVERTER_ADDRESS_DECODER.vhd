library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity INVERTER_ADDRESS_DECODER is 

	port(
			OP_CLK					:	in std_logic;
			EMIF_ADDR				:	in std_logic_vector(11 downto 0);
						
			EM1CS2n					:	in std_logic;
			EM1WEn					: 	in std_logic;
			EM1OEn					:	in std_logic;
			
			CARRIER_INIT_ENn		:  out std_logic;
			SM1_INIT_ENn			:  out std_logic;
			SM2_INIT_ENn			:  out std_logic;
			SM3_INIT_ENn			:  out std_logic;
			SM4_INIT_ENn			:  out std_logic;
			SM5_INIT_ENn			:  out std_logic;
			SM6_INIT_ENn			:  out std_logic
	);
		  
end INVERTER_ADDRESS_DECODER; 

architecture Decoder of INVERTER_ADDRESS_DECODER is
		
	signal ADC_ALL_CV_reg				: 	std_logic  := '1';									-- 
	signal ADC_ALL_WR_reg				:	std_logic  := '1';									-- 
	signal ADC_ALL_CS_reg				:	std_logic  := '1';
	signal ADC0_CS_reg					:	std_logic  := '1';									-- 		
	signal ADC1_CS_reg					:	std_logic  := '1';									-- 	
	signal ADC2_CS_reg					:	std_logic  := '1';									-- 	
	signal ADC3_CS_reg					:	std_logic  := '1';									-- 		
	signal ADC4_CS_reg					:	std_logic  := '1';									-- 	
	signal ADC0_RD_reg					:	std_logic  := '1';									-- 		
	signal ADC1_RD_reg					:	std_logic  := '1';									-- 		
	signal ADC2_RD_reg					:	std_logic  := '1';									-- 		
	signal ADC3_RD_reg					:	std_logic  := '1';									-- 		
	signal ADC4_RD_reg					:	std_logic  := '1';	

	begin 

	ADC_CONVERSTION : process(OP_CLK, EMIF_ADDR, EM1CS2n, EM1WEn, ADC_ALL_CV_reg)
	begin
		
		ADC_ALL_CVn <= ADC_ALL_CV_reg;
		
		if OP_CLK'event and OP_CLK = '1' then
			if EMIF_ADDR = "000001000000" and EM1CS2n = '0' and EM1WEn = '0' then
				ADC_ALL_CV_reg <= '0';
			elsif EMIF_ADDR = "000001000001" and EM1CS2n = '0' and EM1WEn = '0' then
				ADC_ALL_CV_reg <= '1';
			end if;
		end if;
		
	end process;
	
	ADC_WRITE : process(OP_CLK, EMIF_ADDR, EM1CS2n, EM1WEn, ADC_ALL_WR_reg)
	begin
		 
		ADC_ALL_WRn <= ADC_ALL_WR_reg;
		
		if OP_CLK'event and OP_CLK = '1' then
			if EMIF_ADDR = "000001000010" and EM1CS2n = '0' and EM1WEn = '0' then
				ADC_ALL_WR_reg <= '0';
			elsif EMIF_ADDR = "000001000011" and EM1CS2n = '0' and EM1WEn = '0' then
				ADC_ALL_WR_reg <= '1';
			end if;
		end if;
		
	end process;
	
	ADC_CHIP_SELETION : process(OP_CLK, EMIF_ADDR, EM1CS2n, EM1WEn, ADC0_CS_reg, ADC1_CS_reg, ADC2_CS_reg, ADC3_CS_reg, ADC4_CS_reg)
	begin
		 
		ADC0_CSn <= ADC0_CS_reg;
		ADC1_CSn <= ADC1_CS_reg;
		ADC2_CSn <= ADC2_CS_reg;
		ADC3_CSn <= ADC3_CS_reg;
		ADC4_CSn <= ADC4_CS_reg;
		
		if OP_CLK'event and OP_CLK = '1' then
			if EMIF_ADDR = "000001000100" and EM1CS2n = '0' and EM1WEn = '0' then
				ADC0_CS_reg <= '0';
				ADC1_CS_reg <= '0';
				ADC2_CS_reg <= '0';
				ADC3_CS_reg <= '0';
				ADC4_CS_reg <= '0';
			elsif EMIF_ADDR = "000001000101" and EM1CS2n = '0' and EM1WEn = '0' then
				ADC0_CS_reg <= '1';
				ADC1_CS_reg <= '1';
				ADC2_CS_reg <= '1';
				ADC3_CS_reg <= '1';
				ADC4_CS_reg <= '1';				
			else
				if EMIF_ADDR = "000001000110" and EM1CS2n = '0' and EM1WEn = '0' then
					ADC0_CS_reg <= '0';
				elsif EMIF_ADDR = "000001000111" and EM1CS2n = '0' and EM1WEn = '0' then
					ADC0_CS_reg <= '1';
				end if;
				
				if EMIF_ADDR = "000001001000" and EM1CS2n = '0' and EM1WEn = '0' then
					ADC1_CS_reg <= '0';
				elsif EMIF_ADDR = "000001001001" and EM1CS2n = '0' and EM1WEn = '0' then
					ADC1_CS_reg <= '1';
				end if;
				
				if EMIF_ADDR = "000001001010" and EM1CS2n = '0' and EM1WEn = '0' then
					ADC2_CS_reg <= '0';
				elsif EMIF_ADDR = "000001001011" and EM1CS2n = '0' and EM1WEn = '0' then
					ADC2_CS_reg <= '1';
				end if;
				
				if EMIF_ADDR = "000001001100" and EM1CS2n = '0' and EM1WEn = '0' then
					ADC3_CS_reg <= '0';
				elsif EMIF_ADDR = "000001001101" and EM1CS2n = '0' and EM1WEn = '0' then
					ADC3_CS_reg <= '1';
				end if;
				
				if EMIF_ADDR = "000001001110" and EM1CS2n = '0' and EM1WEn = '0' then
					ADC4_CS_reg <= '0';
				elsif EMIF_ADDR = "000001001111" and EM1CS2n = '0' and EM1WEn = '0' then
					ADC4_CS_reg <= '1';
				end if;				
			end if;
		end if;
	end process;
		
	ADC_READ : process(OP_CLK, EMIF_ADDR, EM1CS2n, EM1OEn, ADC0_RD_reg, ADC1_RD_reg, ADC2_RD_reg, ADC3_RD_reg, ADC4_RD_reg)
	begin
		 
		ADC0_RDn <= ADC0_RD_reg;
		ADC1_RDn <= ADC1_RD_reg;
		ADC2_RDn <= ADC2_RD_reg;
		ADC3_RDn <= ADC3_RD_reg;
		ADC4_RDn <= ADC4_RD_reg;

		if OP_CLK'event and OP_CLK = '1' then
			--ADC0  ADDR : 
			if EMIF_ADDR = "000001110000" and EM1CS2n = '0' and EM1OEn = '0' then
				ADC0_RD_reg <= '0';
			else
				ADC0_RD_reg <= '1';
			end if;
			--ADC1
			if EMIF_ADDR = "000001110001" and EM1CS2n = '0' and EM1OEn = '0' then
				ADC1_RD_reg <= '0';
			else
				ADC1_RD_reg <= '1';
			end if;
			--ADC2
			if EMIF_ADDR = "000001110010" and EM1CS2n = '0' and EM1OEn = '0' then
				ADC2_RD_reg <= '0';
			else
				ADC2_RD_reg <= '1';
			end if;
			--ADC3
			if EMIF_ADDR = "000001110011" and EM1CS2n = '0' and EM1OEn = '0' then
				ADC3_RD_reg <= '0';
			else
				ADC3_RD_reg <= '1';
			end if;
			--ADC4
			if EMIF_ADDR = "000001110100" and EM1CS2n = '0' and EM1OEn = '0' then
				ADC4_RD_reg <= '0';
			else
				ADC4_RD_reg <= '1';
			end if;
		end if;
		
	end process;

end Decoder;
