library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity DAC_ADDRESS_DECODER is 

	port(
			OP_CLK					: 	in std_logic;
			EMIF_ADDR				:	in std_logic_vector(11 downto 0);
						
			EM1CS2n					:	in std_logic;
			EM1WEn					: 	in std_logic;
			
			DAC8803_A_CH1n			:	out std_logic;									-- DAC8803_A_CH1
			DAC8803_A_CH2n			:	out std_logic;									-- DAC8803_A_CH2
			DAC8803_A_CH3n			:	out std_logic;									-- DAC8803_A_CH3
			DAC8803_A_CH4n			:	out std_logic;									-- DAC8803_A_CH4
			DAC8803_A_CH5n			:	out std_logic;									-- DAC8803_A_CH5
			DAC8803_A_CH6n			:	out std_logic;									-- DAC8803_A_CH6
			DAC8803_A_CH7n			:	out std_logic;									-- DAC8803_A_CH7
			DAC8803_A_CH8n			:	out std_logic;									-- DAC8803_A_CH8
			DAC8803_A_GENn			:	out std_logic
	 );
		  
end DAC_ADDRESS_DECODER; 

architecture Decoder of DAC_ADDRESS_DECODER is
	
begin 

	DECODING : process(OP_CLK, EMIF_ADDR, EM1CS2n, EM1WEn)
	begin
		if OP_CLK'event and OP_CLK = '1' then
			if EMIF_ADDR = "000100010010" and EM1CS2n = '0' and EM1WEn = '0' then
				DAC8803_A_CH1n <= '0';
			else
				DAC8803_A_CH1n <= '1';
			end if;
			if EMIF_ADDR = "000100100100" and EM1CS2n = '0' and EM1WEn = '0' then
				DAC8803_A_CH2n <= '0';
			else
				DAC8803_A_CH2n <= '1';
			end if;
			if EMIF_ADDR = "000100110110" and EM1CS2n = '0' and EM1WEn = '0' then
				DAC8803_A_CH3n <= '0';
			else
				DAC8803_A_CH3n <= '1';
			end if;
			if EMIF_ADDR = "000101001000" and EM1CS2n = '0' and EM1WEn = '0' then
				DAC8803_A_CH4n <= '0';
			else
				DAC8803_A_CH4n <= '1';
			end if;
			if EMIF_ADDR = "000101011010" and EM1CS2n = '0' and EM1WEn = '0' then
				DAC8803_A_CH5n <= '0';
			else
				DAC8803_A_CH5n <= '1';
			end if;
			if EMIF_ADDR = "000101101100" and EM1CS2n = '0' and EM1WEn = '0' then
				DAC8803_A_CH6n <= '0';
			else
				DAC8803_A_CH6n <= '1';
			end if;
			if EMIF_ADDR = "000101111110" and EM1CS2n = '0' and EM1WEn = '0' then
				DAC8803_A_CH7n <= '0';
			else
				DAC8803_A_CH7n <= '1';
			end if;
			if EMIF_ADDR = "000110000000" and EM1CS2n = '0' and EM1WEn = '0' then
				DAC8803_A_CH8n <= '0';
			else
				DAC8803_A_CH8n <= '1';
			end if;
			if EMIF_ADDR = "000110010010" and EM1CS2n = '0' and EM1WEn = '0' then
				DAC8803_A_GENn <= '0';
			else
				DAC8803_A_GENn <= '1';
			end if;
		end if;
	end process;

end Decoder;
