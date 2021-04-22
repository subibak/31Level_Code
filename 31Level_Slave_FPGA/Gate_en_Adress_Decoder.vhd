library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;


entity Gate_en_Adress_Decoder is 

	port(
			--XINTF address
			addr_lower	:		in std_logic_vector(7 downto 0);
			--Zone select signals
			ZCS0n			:		in std_logic;
		
			GATE1_off 		: 		out std_logic ;
			GATE1_on 		: 		out std_logic ;
			GATE2_off 		: 		out std_logic ;
			GATE2_on 		: 		out std_logic ;
			GATE3_off 		: 		out std_logic ;
			GATE3_on 		: 		out std_logic ;
			GATE4_off 		: 		out std_logic ;
			GATE4_on 		: 		out std_logic ;
			GATE5_off 		: 		out std_logic ;
			GATE5_on 		: 		out std_logic 								
			);

end Gate_en_Adress_Decoder; 

architecture act of Gate_en_Adress_Decoder is

begin

----------------------------------------------- Zone 0 -----------------------------------------------
	--PWM_
	GATE1_off		<= '0' when addr_lower(7 downto 0) = "00101010" and ZCS0n = '0' else '1';	
	GATE1_on		 	<= '0' when addr_lower(7 downto 0) = "00101011" and ZCS0n = '0' else '1';	
	GATE2_off		<= '0' when addr_lower(7 downto 0) = "01000000" and ZCS0n = '0' else '1';	
	GATE2_on		 	<= '0' when addr_lower(7 downto 0) = "01000001" and ZCS0n = '0' else '1';	
	GATE3_off		<= '0' when addr_lower(7 downto 0) = "01000010" and ZCS0n = '0' else '1';	
	GATE3_on		 	<= '0' when addr_lower(7 downto 0) = "01000011" and ZCS0n = '0' else '1';	
	GATE4_off		<= '0' when addr_lower(7 downto 0) = "01000100" and ZCS0n = '0' else '1';	
	GATE4_on		 	<= '0' when addr_lower(7 downto 0) = "01000101" and ZCS0n = '0' else '1';	
	GATE5_off		<= '0' when addr_lower(7 downto 0) = "01000110" and ZCS0n = '0' else '1';	
	GATE5_on		 	<= '0' when addr_lower(7 downto 0) = "01000111" and ZCS0n = '0' else '1';		
	
end act;
