library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity GATING_ADDRESS_DECODER is 

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
		  
end GATING_ADDRESS_DECODER; 

architecture Decoder of GATING_ADDRESS_DECODER is
		
	signal CARRIER_INIT_ENn_reg				: 	std_logic  := '1';									-- 
	signal SM1_INIT_ENn_reg						: 	std_logic  := '1';									-- 
	signal SM2_INIT_ENn_reg						: 	std_logic  := '1';									-- 
	signal SM3_INIT_ENn_reg						: 	std_logic  := '1';									-- 
	signal SM4_INIT_ENn_reg						: 	std_logic  := '1';									-- 
	signal SM5_INIT_ENn_reg						: 	std_logic  := '1';									-- 
	signal SM6_INIT_ENn_reg						: 	std_logic  := '1';									-- 

	
begin 

	Carrier : process(OP_CLK, EMIF_ADDR, EM1CS2n, EM1WEn, ADC_ALL_CV_reg)
	begin
		
		CARRIER_INIT_ENn <= CARRIER_INIT_ENn_reg;
		
		if OP_CLK'event and OP_CLK = '1' then
			if EMIF_ADDR = "000001000000" and EM1CS2n = '0' and EM1WEn = '0' then
				ADC_ALL_CV_reg <= '0';
			elsif EMIF_ADDR = "000001000001" and EM1CS2n = '0' and EM1WEn = '0' then
				ADC_ALL_CV_reg <= '1';
			end if;
		end if;
		
	end process;
	
end Decoder;
