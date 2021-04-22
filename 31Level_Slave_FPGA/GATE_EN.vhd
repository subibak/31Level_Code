library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity GATE_EN is 
	
	port(
				OP_CLK	 				:	in std_logic;
				
				EMIF_ADDR				:	in std_logic_vector(11 downto 0);
				EM1CS2n					:	in std_logic;
				EM1WEn					: 	in std_logic;	
				
				ENABLEn					: 	out std_logic
	);
	
end GATE_EN;


architecture GATE_ENABLE of GATE_EN is 
	
	signal ENABLE_reg			:	std_logic := '1';
begin

	ENABLE_OP : process(OP_CLK, EMIF_ADDR, EM1CS2n, EM1WEn, ENABLE_reg)
	begin
		if OP_CLK'event and OP_CLK = '1' then
			if EMIF_ADDR = "000010110001" and EM1CS2n = '0' and EM1WEn = '0' then
				ENABLE_reg <= '0';
			elsif EMIF_ADDR = "000010110010" and EM1CS2n = '0' and EM1WEn = '0' then
				ENABLE_reg <= '1'; 
			end if;	
		end if;
			ENABLEn <= ENABLE_reg;
	end process;
end GATE_ENABLE;