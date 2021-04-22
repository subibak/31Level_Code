library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity LEG_MASTER_SYNC is 

	port(
			OP_CLK					:	in std_logic;
			GPMC_ADDR				:	in std_logic_vector(11 downto 0);
						
			GPMC_CSn					:	in std_logic;
			GPMC_WEn					: 	in std_logic;
			GPMC_OEn					:	in std_logic;
			
			SYNC						:	out std_logic									
	);
		  
end LEG_MASTER_SYNC; 

architecture arch of LEG_MASTER_SYNC is
		
	signal SYNC_reg				: 	std_logic  := '0';									-- 

	begin 
	-- Active high sync generator
	SYNC_GENERATOR : process(OP_CLK, GPMC_ADDR, GPMC_CSn, GPMC_WEn, SYNC_reg)
	begin
		
		SYNC <= SYNC_reg;
		
		if OP_CLK'event and OP_CLK = '1' then
			if GPMC_ADDR = "000000000010" and GPMC_CSn = '0' and GPMC_WEn = '0' then
				SYNC_reg <= '1';
			elsif GPMC_ADDR = "000000000100" and GPMC_CSn = '0' and GPMC_WEn = '0' then
				SYNC_reg <= '0';
			end if;
		end if;
		
	end process;

end arch;
