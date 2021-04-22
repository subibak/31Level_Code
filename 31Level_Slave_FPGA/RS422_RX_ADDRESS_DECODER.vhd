library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity RS422_RX_ADDRESS_DECODER is 

	port(
			OP_CLK					:	in std_logic;
			EMIF_ADDR				:	in std_logic_vector(11 downto 0);
						
			EM1CS2n					:	in std_logic;
			EM1WEn					: 	in std_logic;
			
			RX422_RX_AUX_SETn		:	out std_logic;		
			RX422_RX_SETn			:	out std_logic									--  RESET then START
							-- 			

	 );
		  
end RS422_RX_ADDRESS_DECODER; 

architecture Decoder of RS422_RX_ADDRESS_DECODER is
	
begin 

	DECODING : process(OP_CLK, EMIF_ADDR, EM1CS2n, EM1WEn)
	begin
		if OP_CLK'event and OP_CLK = '1' then
			if EMIF_ADDR = "000000110110" and EM1CS2n = '0' and EM1WEn = '0' then
				RX422_RX_AUX_SETn <= '0';
			else
				RX422_RX_AUX_SETn <= '1';
			end if;
			if EMIF_ADDR = "000000001100" and EM1CS2n = '0' and EM1WEn = '0' then
				RX422_RX_SETn <= '0';
			else
				RX422_RX_SETn <= '1';
			end if;
		end if;
	end process;
	
end Decoder;
