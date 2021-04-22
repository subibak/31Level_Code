library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity FAN is 

	port(
			OP_CLK					:	in std_logic;
			
			EMIF_ADDR				:	in std_logic_vector(11 downto 0);
			EM1CS2n					:	in std_logic;
			EM1WEn					: 	in std_logic;
			EMIF_DATA				:	in std_logic_vector(15 downto 0);
			
			FAN_OUT					:	out std_logic_vector(5 downto 0)
		 );
		  
end FAN; 

architecture arch of FAN is
	
	signal FAN_OP_reg	 : std_logic_vector(5 downto 0) := "000000";
	signal FAN_OUT_reg : std_logic_vector(5 downto 0) := "000000";

begin 

	FAN_DECODER: process(OP_CLK, EMIF_ADDR, EM1CS2n, EM1WEn, EMIF_DATA)
	begin
		if OP_CLK'event and OP_CLK = '1' then
			if EMIF_ADDR = "000011100000" and EM1CS2n = '0' and EM1WEn = '0' then
				FAN_OP_reg <= EMIF_DATA(5 downto 0);
			end if;
		end if;
	end process;

	FAN_OPERATION: process(OP_CLK, FAN_OP_reg, FAN_OUT_reg)
	begin
		if OP_CLK'event and OP_CLK = '1' then
			FAN_OUT_reg <= FAN_OP_reg;
		end if;
		FAN_OUT <= FAN_OUT_reg;
	end process;

end arch;
