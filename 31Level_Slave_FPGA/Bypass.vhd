library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity Bypass is
	port(
			OP_CLK					:	in std_logic;
			
			EMIF_ADDR				:	in std_logic_vector(11 downto 0);
			EM1CS2n					:	in std_logic;
			EM1WEn					: 	in std_logic;
			EMIF_DATA				:	in std_logic_vector(15 downto 0);

			RELAY_OUT				:	out std_logic_vector(5 downto 0);
			IGBT_OUT					:	out std_logic_vector(5 downto 0)
	);
end Bypass;

architecture arch of Bypass is 

	signal RELAY_OP_reg	 : std_logic_vector(5 downto 0) := "000000";
	signal RELAY_OUT_reg  : std_logic_vector(5 downto 0) := "000000";
	signal IGBT_OP_reg	 : std_logic_vector(5 downto 0) := "000000";
	signal IGBT_OUT_reg 	 : std_logic_vector(5 downto 0) := "000000";

begin

	RELAY_DECODER: process(OP_CLK, EMIF_ADDR, EM1CS2n, EM1WEn, EMIF_DATA)
	begin
		if OP_CLK'event and OP_CLK = '1' then
			if EMIF_ADDR = "000011010000" and EM1CS2n = '0' and EM1WEn = '0' then
				RELAY_OP_reg <= EMIF_DATA(5 downto 0);
			end if;
		end if;
	end process;

	RELAY_OPERATION: process(OP_CLK, RELAY_OP_reg, RELAY_OUT_reg)
	begin
		if OP_CLK'event and OP_CLK = '1' then
			RELAY_OUT_reg <= RELAY_OP_reg;
		end if;
		RELAY_OUT <= RELAY_OUT_reg;
	end process;
	
	IGBT_DECODER: process(OP_CLK, EMIF_ADDR, EM1CS2n, EM1WEn, EMIF_DATA)
	begin
		if OP_CLK'event and OP_CLK = '1' then
			if EMIF_ADDR = "000011000000" and EM1CS2n = '0' and EM1WEn = '0' then
				IGBT_OP_reg <= EMIF_DATA(5 downto 0);
			end if;
		end if;
	end process;

	IGBT_OPERATION: process(OP_CLK, IGBT_OP_reg, IGBT_OUT_reg)
	begin
		if OP_CLK'event and OP_CLK = '1' then
			IGBT_OUT_reg <= IGBT_OP_reg;
		end if;
		IGBT_OUT <= IGBT_OUT_reg;
	end process;
		
end arch;

