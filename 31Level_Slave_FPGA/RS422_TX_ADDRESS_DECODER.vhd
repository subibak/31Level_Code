library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity RS422_TX_ADDRESS_DECODER is 

	port(
			OP_CLK					:	in std_logic;
			EMIF_ADDR				:	in std_logic_vector(11 downto 0);
						
			EM1CS2n					:	in std_logic;
			EM1WEn					: 	in std_logic;
			
			RX422_TX_AUX_SETn		:	out std_logic;		
			RX422_TX_SETn			:	out std_logic;									--  RESET then START
			RX422_TX_BYTEREADYn	:	out std_logic;		
			RX422_TX_TBYTEn		:	out std_logic;		
			RX422_TX_LOADn			:	out std_logic		

	 );
		  
end RS422_TX_ADDRESS_DECODER; 

architecture Decoder of RS422_TX_ADDRESS_DECODER is
	
begin 

	DECODING : process(OP_CLK, EMIF_ADDR, EM1CS2n, EM1WEn)
	begin
		if OP_CLK'event and OP_CLK = '1' then
			if EMIF_ADDR = "000000001011" and EM1CS2n = '0' and EM1WEn = '0' then
				RX422_TX_AUX_SETn <= '0';
			else
				RX422_TX_AUX_SETn <= '1';
			end if;
			if EMIF_ADDR = "000000000010" and EM1CS2n = '0' and EM1WEn = '0' then
				RX422_TX_SETn <= '0';
			else
				RX422_TX_SETn <= '1';
			end if;
			if EMIF_ADDR = "000000000110" and EM1CS2n = '0' and EM1WEn = '0' then
				RX422_TX_BYTEREADYn <= '0';
			else
				RX422_TX_BYTEREADYn <= '1';
			end if;
			if EMIF_ADDR = "000000000111" and EM1CS2n = '0' and EM1WEn = '0' then
				RX422_TX_TBYTEn <= '0';
			else
				RX422_TX_TBYTEn <= '1';
			end if;
			if EMIF_ADDR = "000000001001" and EM1CS2n = '0' and EM1WEn = '0' then
				RX422_TX_LOADn <= '0';
			else
				RX422_TX_LOADn <= '1';
			end if;
		end if;
	end process;
	
end Decoder;
