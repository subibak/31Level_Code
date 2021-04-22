library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity BUFFER_74F240 is 
	
	port(
			OP_CLK					:	in std_logic;
			
			EMIF_ADDR				:	in std_logic_vector(11 downto 0);
			EM1CS2n					:	in std_logic;
			EM1WEn					: 	in std_logic;
			EMIF_DATA				:	in std_logic_vector(15 downto 0);
			
			BUFFER_OUT				:	out std_logic_vector(3 downto 0)
	);

end BUFFER_74F240;


architecture arch of BUFFER_74F240 is 
	
	signal BUFFER_OP_reg	 : std_logic_vector(3 downto 0) := "0000";
	signal BUFFER_OUT_reg : std_logic_vector(3 downto 0) := "0000";

begin

	BUFFER_DECODER: process(OP_CLK, EMIF_ADDR, EM1CS2n, EM1WEn, EMIF_DATA)
	begin
		if OP_CLK'event and OP_CLK = '1' then
			if EMIF_ADDR = "000010110001" and EM1CS2n = '0' and EM1WEn = '0' then
				BUFFER_OP_reg <= EMIF_DATA(3 downto 0);
			end if;
		end if;
	end process;

	BUFFER_OPERATION: process(OP_CLK, BUFFER_OP_reg, BUFFER_OUT_reg)
	begin
		if OP_CLK'event and OP_CLK = '1' then
			BUFFER_OUT_reg <= not(BUFFER_OP_reg) ;
		end if;
		BUFFER_OUT <= BUFFER_OUT_reg;
	end process;
	
end arch;