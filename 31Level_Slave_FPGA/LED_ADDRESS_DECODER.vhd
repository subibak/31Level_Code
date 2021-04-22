library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity LED_ADDRESS_DECODER is 

	port(
			OP_CLK					:	in std_logic;
			EMIF_ADDR				:	in std_logic_vector(11 downto 0);
						
			EM1CS2n					:	in std_logic;
			EM1WEn					: 	in std_logic;
			
			LED_ENn					:	out std_logic
	 );
		  
end LED_ADDRESS_DECODER; 

architecture Decoder of LED_ADDRESS_DECODER is
	
begin 
	
	DECODING : process(OP_CLK, EMIF_ADDR, EM1CS2n, EM1WEn)
	begin
		if OP_CLK'event and OP_CLK = '1' then
			if EMIF_ADDR = "000000000001" and EM1CS2n = '0' and EM1WEn = '0' then
				LED_ENn <= '0';
			else	
				LED_ENn <= '1';
			end if;
		end if;
	end process;

end Decoder;
