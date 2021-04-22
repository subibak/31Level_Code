library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity LED_ADDRESS_DECODER is 

	port(
			OP_CLK					:	in std_logic;
			GPMC_ADDR				:	in std_logic_vector(11 downto 0);
						
			GPMC_CSn				:	in std_logic;
			GPMC_WEn					: 	in std_logic;
			
			LED_ENn					:	out std_logic
	 );
		  
end LED_ADDRESS_DECODER; 

architecture Decoder of LED_ADDRESS_DECODER is
	
begin 
	
	DECODING : process(OP_CLK, GPMC_ADDR, GPMC_CSn, GPMC_WEn)
	begin
		if OP_CLK'event and OP_CLK = '1' then
			if GPMC_ADDR = "000000000000" and GPMC_CSn = '0' and GPMC_WEn = '0' then
				LED_ENn <= '0';
			else	
				LED_ENn <= '1';
			end if;
		end if;
	end process;

end Decoder;
