library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity FAN_TEST_BLCOK is 

	port(
			OP_CLK					:	in std_logic;
			EMIF_ADDR				:	in std_logic_vector(11 downto 0);
						
			EM1CS2n					:	in std_logic;
			EM1WEn					: 	in std_logic;
			
			FAN_OP					:	out std_logic
	 );
		  
end FAN_TEST_BLCOK; 

architecture Decoder of FAN_TEST_BLCOK is
	
	signal FAN_OP_reg : std_logic := '0';
begin 

	DECODING : process(OP_CLK, EMIF_ADDR, EM1CS2n, EM1WEn)
	begin
		if OP_CLK'event and OP_CLK = '1' then
			if EMIF_ADDR = "000011100000" and EM1CS2n = '0' and EM1WEn = '0' then
				FAN_OP_reg <= '1';
			elsif  EMIF_ADDR = "000011100001" and EM1CS2n = '0' and EM1WEn = '0' then
				FAN_OP_reg <= '0';
			end if;
		end if;
		
		FAN_OP <= FAN_OP_reg;
	
	end process;
	
end Decoder;
