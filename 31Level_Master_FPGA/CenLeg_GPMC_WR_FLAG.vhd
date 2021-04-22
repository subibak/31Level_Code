library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity CenLeg_GPMC_WR_FLAG is 

	port(
			OP_CLK					:	in std_logic;
						
			GPMC_BE1n_C				:	in std_logic;
			GPMC_BE1n_L1			: 	in std_logic;
			GPMC_BE1n_L2			:	in std_logic;
			GPMC_BE1n_L3			:	in std_logic;

			FLAG_CenLeg_WR			:	out std_logic									
	);
		  
end CenLeg_GPMC_WR_FLAG; 

architecture arch of CenLeg_GPMC_WR_FLAG is
		
	signal GPMC_BE1n_C_reg				: 	std_logic  := '0';
	signal GPMC_BE1n_L1_reg				: 	std_logic  := '0';	 
	signal GPMC_BE1n_L2_reg				: 	std_logic  := '0';	
	signal GPMC_BE1n_L3_reg				: 	std_logic  := '0';	
	signal GPMC_BE1n_L_reg				:	std_logic  := '0';
	signal GPMC_BE1n_reg					: 	std_logic_vector(1 downto 0)  := "00";
	signal FLAG_CenLeg_WR_reg			:  std_logic := '0';

begin 
	
	FLAG_GENERATOR : process(OP_CLK, GPMC_BE1n_reg)
	begin
		
		if OP_CLK'event and OP_CLK = '1' then
			
			GPMC_BE1n_C_reg  	 <= GPMC_BE1n_C;
			GPMC_BE1n_L1_reg 	 <= GPMC_BE1n_L1;
			GPMC_BE1n_L2_reg 	 <= GPMC_BE1n_L2;
			GPMC_BE1n_L3_reg 	 <= GPMC_BE1n_L3;
			GPMC_BE1n_L_reg  	 <= GPMC_BE1n_L1_reg and GPMC_BE1n_L2_reg and GPMC_BE1n_L3_reg;
			GPMC_BE1n_reg 		 <= GPMC_BE1n_C_reg & GPMC_BE1n_L_reg;
			FLAG_CenLeg_WR <= FLAG_CenLeg_WR_reg;
		
			case GPMC_BE1n_reg is
				when "00" => FLAG_CenLeg_WR_reg <= '0';
				when "10" => FLAG_CenLeg_WR_reg <= '1';
				when "11" => FLAG_CenLeg_WR_reg <= '0';
				when "01" => FLAG_CenLeg_WR_reg <= '0';				
			end case;

		end if;
		
	end process;

end arch;
