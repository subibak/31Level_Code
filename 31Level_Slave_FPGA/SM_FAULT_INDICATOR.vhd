library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

entity SM_FAULT_INDICATOR is
	port(
			OP_CLK			: 	in std_logic;
			EMIF_ADDR		:	in std_logic_vector(11 downto 0);
			EM1CS2n			:	in std_logic;
			EM1WEn			: 	in std_logic;
			EMIF_DATA		:  in std_logic_vector(15 downto 0);	
			
			SMA1_FAU_INDI	:  out std_logic;
			SMA2_FAU_INDI	:  out std_logic;
			SMA3_FAU_INDI	:  out std_logic;
			SMB1_FAU_INDI	:  out std_logic;
			SMB2_FAU_INDI	:  out std_logic;
			SMB3_FAU_INDI	:  out std_logic
	);
end SM_FAULT_INDICATOR;

architecture arch of SM_FAULT_INDICATOR is

	signal SMA1_FAU_INDI_reg 	: std_logic := '0';
	signal SMA2_FAU_INDI_reg 	: std_logic := '0';
	signal SMA3_FAU_INDI_reg 	: std_logic := '0';
	signal SMB1_FAU_INDI_reg 	: std_logic := '0';
	signal SMB2_FAU_INDI_reg 	: std_logic := '0';
	signal SMB3_FAU_INDI_reg 	: std_logic := '0';

begin
	
	LED_INDICATOR_OP : process(OP_CLK, EMIF_ADDR, EM1CS2n, EM1WEn, EMIF_DATA)
	begin
			if OP_CLK'event and OP_CLK = '1' then
				if EMIF_ADDR = "000011100001" and EM1CS2n = '0' and EM1WEn = '0' then
					SMA1_FAU_INDI_reg <= EMIF_DATA(0);
					SMA2_FAU_INDI_reg <= EMIF_DATA(1);
					SMA3_FAU_INDI_reg <= EMIF_DATA(2);
					SMB1_FAU_INDI_reg <= EMIF_DATA(3);
					SMB2_FAU_INDI_reg <= EMIF_DATA(4);
					SMB3_FAU_INDI_reg <= EMIF_DATA(5);
				end if;	
			end if;
			SMA1_FAU_INDI <= SMA1_FAU_INDI_reg;
			SMA2_FAU_INDI <= SMA2_FAU_INDI_reg;
			SMA3_FAU_INDI <= SMA3_FAU_INDI_reg;
			SMB1_FAU_INDI <= SMB1_FAU_INDI_reg;
			SMB2_FAU_INDI <= SMB2_FAU_INDI_reg;
			SMB3_FAU_INDI <= SMB3_FAU_INDI_reg;
	end process;

end arch;
 