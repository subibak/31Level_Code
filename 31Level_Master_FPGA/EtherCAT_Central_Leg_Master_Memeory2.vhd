library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity EtherCAT_Central_Leg_Master_Memeory2 is
	
	port(
			OP_CLK					:	in std_logic;
			
			GPMC_ADDR_C				:	in std_logic_vector(11 downto 0);
			GPMC_DATA_C				:	in std_logic_vector(15 downto 0);			
			GPMC_CSn_C				:	in std_logic;
			GPMC_WEn_C				:  in std_logic;
			GPMC_OEn_C				: 	in std_logic;
			
			GPMC_ADDR_L1			:	in std_logic_vector(10 downto 0);
			GPMC_DATA_L1			:	in std_logic_vector(15 downto 0);			
			GPMC_CSn_L1				:	in std_logic;
			GPMC_WEn_L1				:	in std_logic;
			GPMC_OEn_L1				: 	in std_logic;

			GPMC_ADDR_L2			:	in std_logic_vector(10 downto 0);
			GPMC_DATA_L2			:	in std_logic_vector(15 downto 0);			
			GPMC_CSn_L2				:	in std_logic;
			GPMC_WEn_L2				:	in std_logic;
			GPMC_OEn_L2				: 	in std_logic;
			
			GPMC_ADDR_L3			:	in std_logic_vector(10 downto 0);
			GPMC_DATA_L3			:	in std_logic_vector(15 downto 0);			
			GPMC_CSn_L3				:	in std_logic;
			GPMC_WEn_L3				:	in std_logic;
			GPMC_OEn_L3				: 	in std_logic;			
			
			DATA_OUT_C				:  out std_logic_vector(15 downto 0);
			DATA_OUT_L1				: 	out std_logic_vector(15 downto 0);
			DATA_OUT_L2				: 	out std_logic_vector(15 downto 0);
			DATA_OUT_L3				: 	out std_logic_vector(15 downto 0)
		);
		
end EtherCAT_Central_Leg_Master_Memeory2; 

architecture arch of EtherCAT_Central_Leg_Master_Memeory2 is

	type EtherCAT_MEM is array (0 to 39) of std_logic_vector(15 downto 0);
	signal MEM_C_Comm	: EtherCAT_MEM;
	signal MEM_C_L1	: EtherCAT_MEM;
	signal MEM_C_L2	: EtherCAT_MEM;
	signal MEM_C_L3	: EtherCAT_MEM;
	signal MEM_L1_C	: EtherCAT_MEM;
	signal MEM_L2_C	: EtherCAT_MEM;
	signal MEM_L3_C	: EtherCAT_MEM;
	
begin
------------------------------------------------------------------------------------------------
----------------------------------CENTRAL MASTER1-----------------------------------------------
------------------------------------------------------------------------------------------------
	WRITE_COMMON_CENTRAL	: process(OP_CLK, GPMC_ADDR_C, GPMC_CSn_C, GPMC_WEn_C)
	begin
		if OP_CLK'event and OP_CLK = '1'  then
			
			if GPMC_CSn_C = '0' and GPMC_WEn_C = '0' then
				if 	GPMC_ADDR_C = x"000" then MEM_C_Comm(0)  <= GPMC_DATA_C; 
				elsif GPMC_ADDR_C = x"002" then MEM_C_Comm(1)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"004" then MEM_C_Comm(2)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"006" then MEM_C_Comm(3)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"008" then MEM_C_Comm(4)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"00A" then MEM_C_Comm(5)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"00C" then MEM_C_Comm(6)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"00E" then MEM_C_Comm(7)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"010" then MEM_C_Comm(8)  <= GPMC_DATA_C; 
				elsif GPMC_ADDR_C = x"012" then MEM_C_Comm(9)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"014" then MEM_C_Comm(10) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"016" then MEM_C_Comm(11) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"018" then MEM_C_Comm(12) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"01A" then MEM_C_Comm(13) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"01C" then MEM_C_Comm(14) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"01E" then MEM_C_Comm(15) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"020" then MEM_C_Comm(16) <= GPMC_DATA_C; 
				elsif GPMC_ADDR_C = x"022" then MEM_C_Comm(17) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"024" then MEM_C_Comm(18) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"026" then MEM_C_Comm(19) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"028" then MEM_C_Comm(20) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"02A" then MEM_C_Comm(21) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"02C" then MEM_C_Comm(22) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"02E" then MEM_C_Comm(23) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"030" then MEM_C_Comm(24) <= GPMC_DATA_C; 
				elsif GPMC_ADDR_C = x"032" then MEM_C_Comm(25) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"034" then MEM_C_Comm(26) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"036" then MEM_C_Comm(27) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"038" then MEM_C_Comm(28) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"03A" then MEM_C_Comm(29) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"03C" then MEM_C_Comm(30) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"03E" then MEM_C_Comm(31) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"040" then MEM_C_Comm(32) <= GPMC_DATA_C; 
				elsif GPMC_ADDR_C = x"042" then MEM_C_Comm(33) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"044" then MEM_C_Comm(34) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"046" then MEM_C_Comm(35) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"048" then MEM_C_Comm(36) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"04A" then MEM_C_Comm(37) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"04C" then MEM_C_Comm(38) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"04E" then MEM_C_Comm(39) <= GPMC_DATA_C;				
				end if;
			end if;	
		
		end if;
	
	end process;
	
	WRITE_C_L1_CENTRAL 	: process(OP_CLK, GPMC_ADDR_C, GPMC_CSn_C, GPMC_WEn_C)
	begin
		if OP_CLK'event and OP_CLK = '1'  then
			
			if GPMC_CSn_C = '0' and GPMC_WEn_C = '0' then
				if 	GPMC_ADDR_C = x"050" then MEM_C_L1(0)  <= GPMC_DATA_C; 
				elsif GPMC_ADDR_C = x"052" then MEM_C_L1(1)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"054" then MEM_C_L1(2)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"056" then MEM_C_L1(3)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"058" then MEM_C_L1(4)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"05A" then MEM_C_L1(5)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"05C" then MEM_C_L1(6)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"05E" then MEM_C_L1(7)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"060" then MEM_C_L1(8)  <= GPMC_DATA_C; 
				elsif GPMC_ADDR_C = x"062" then MEM_C_L1(9)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"064" then MEM_C_L1(10) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"066" then MEM_C_L1(11) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"068" then MEM_C_L1(12) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"06A" then MEM_C_L1(13) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"06C" then MEM_C_L1(14) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"06E" then MEM_C_L1(15) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"070" then MEM_C_L1(16) <= GPMC_DATA_C; 
				elsif GPMC_ADDR_C = x"072" then MEM_C_L1(17) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"074" then MEM_C_L1(18) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"076" then MEM_C_L1(19) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"078" then MEM_C_L1(20) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"07A" then MEM_C_L1(21) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"07C" then MEM_C_L1(22) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"07E" then MEM_C_L1(23) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"080" then MEM_C_L1(24) <= GPMC_DATA_C; 
				elsif GPMC_ADDR_C = x"082" then MEM_C_L1(25) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"084" then MEM_C_L1(26) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"086" then MEM_C_L1(27) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"088" then MEM_C_L1(28) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"08A" then MEM_C_L1(29) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"08C" then MEM_C_L1(30) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"08E" then MEM_C_L1(31) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"090" then MEM_C_L1(32) <= GPMC_DATA_C; 
				elsif GPMC_ADDR_C = x"092" then MEM_C_L1(33) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"094" then MEM_C_L1(34) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"096" then MEM_C_L1(35) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"098" then MEM_C_L1(36) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"09A" then MEM_C_L1(37) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"09C" then MEM_C_L1(38) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"09E" then MEM_C_L1(39) <= GPMC_DATA_C;	
				end if;
			end if;	
		
		end if;
	
	end process;
	
	WRITE_C_L2_CENTRAL 	: process(OP_CLK, GPMC_ADDR_C, GPMC_CSn_C, GPMC_WEn_C)
	begin
		if OP_CLK'event and OP_CLK = '1'  then
			
			if GPMC_CSn_C = '0' and GPMC_WEn_C = '0' then
				if 	GPMC_ADDR_C = x"0A0" then MEM_C_L2(0)  <= GPMC_DATA_C; 
				elsif GPMC_ADDR_C = x"0A2" then MEM_C_L2(1)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0A4" then MEM_C_L2(2)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0A6" then MEM_C_L2(3)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0A8" then MEM_C_L2(4)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0AA" then MEM_C_L2(5)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0AC" then MEM_C_L2(6)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0AE" then MEM_C_L2(7)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0B0" then MEM_C_L2(8)  <= GPMC_DATA_C; 
				elsif GPMC_ADDR_C = x"0B2" then MEM_C_L2(9)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0B4" then MEM_C_L2(10) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0B6" then MEM_C_L2(11) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0B8" then MEM_C_L2(12) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0BA" then MEM_C_L2(13) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0BC" then MEM_C_L2(14) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0BE" then MEM_C_L2(15) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0C0" then MEM_C_L2(16) <= GPMC_DATA_C; 
				elsif GPMC_ADDR_C = x"0C2" then MEM_C_L2(17) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0C4" then MEM_C_L2(18) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0C6" then MEM_C_L2(19) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0C8" then MEM_C_L2(20) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0CA" then MEM_C_L2(21) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0CC" then MEM_C_L2(22) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0CE" then MEM_C_L2(23) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0D0" then MEM_C_L2(24) <= GPMC_DATA_C; 
				elsif GPMC_ADDR_C = x"0D2" then MEM_C_L2(25) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0D4" then MEM_C_L2(26) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0D6" then MEM_C_L2(27) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0D8" then MEM_C_L2(28) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0DA" then MEM_C_L2(29) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0DC" then MEM_C_L2(30) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0DE" then MEM_C_L2(31) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0E0" then MEM_C_L2(32) <= GPMC_DATA_C; 
				elsif GPMC_ADDR_C = x"0E2" then MEM_C_L2(33) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0E4" then MEM_C_L2(34) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0E6" then MEM_C_L2(35) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0E8" then MEM_C_L2(36) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0EA" then MEM_C_L2(37) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0EC" then MEM_C_L2(38) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0EE" then MEM_C_L2(39) <= GPMC_DATA_C;	
				end if;
			end if;	
		
		end if;
	
	end process;
	
	WRITE_C_L3_CENTRAL 	: process(OP_CLK, GPMC_ADDR_C, GPMC_CSn_C, GPMC_WEn_C)
	begin
		if OP_CLK'event and OP_CLK = '1'  then
			
			if GPMC_CSn_C = '0' and GPMC_WEn_C = '0' then
				if 	GPMC_ADDR_C = x"0F0" then MEM_C_L3(0)  <= GPMC_DATA_C; 
				elsif GPMC_ADDR_C = x"0F2" then MEM_C_L3(1)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0F4" then MEM_C_L3(2)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0F6" then MEM_C_L3(3)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0F8" then MEM_C_L3(4)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0FA" then MEM_C_L3(5)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0FC" then MEM_C_L3(6)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"0FE" then MEM_C_L3(7)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"100" then MEM_C_L3(8)  <= GPMC_DATA_C; 
				elsif GPMC_ADDR_C = x"102" then MEM_C_L3(9)  <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"104" then MEM_C_L3(10) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"106" then MEM_C_L3(11) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"108" then MEM_C_L3(12) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"10A" then MEM_C_L3(13) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"10C" then MEM_C_L3(14) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"10E" then MEM_C_L3(15) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"110" then MEM_C_L3(16) <= GPMC_DATA_C; 
				elsif GPMC_ADDR_C = x"112" then MEM_C_L3(17) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"114" then MEM_C_L3(18) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"116" then MEM_C_L3(19) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"118" then MEM_C_L3(20) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"11A" then MEM_C_L3(21) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"11C" then MEM_C_L3(22) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"11E" then MEM_C_L3(23) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"120" then MEM_C_L3(24) <= GPMC_DATA_C; 
				elsif GPMC_ADDR_C = x"122" then MEM_C_L3(25) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"124" then MEM_C_L3(26) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"126" then MEM_C_L3(27) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"128" then MEM_C_L3(28) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"12A" then MEM_C_L3(29) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"12C" then MEM_C_L3(30) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"12E" then MEM_C_L3(31) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"130" then MEM_C_L3(32) <= GPMC_DATA_C; 
				elsif GPMC_ADDR_C = x"132" then MEM_C_L3(33) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"134" then MEM_C_L3(34) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"136" then MEM_C_L3(35) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"138" then MEM_C_L3(36) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"13A" then MEM_C_L3(37) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"13C" then MEM_C_L3(38) <= GPMC_DATA_C;
				elsif GPMC_ADDR_C = x"13E" then MEM_C_L3(39) <= GPMC_DATA_C;	
				end if;
			end if;	
		
		end if;
	
	end process;
	
	READ_L1_C_CENTRAL		: process(OP_CLK, GPMC_ADDR_C, GPMC_CSn_C, GPMC_OEn_C)
	begin
		if OP_CLK'event and OP_CLK = '1'  then
			
			if GPMC_CSn_C = '0' and GPMC_OEn_C = '0' then
				if 	GPMC_ADDR_C = x"640" then DATA_OUT_C <= MEM_L1_C(0);
				elsif GPMC_ADDR_C = x"642" then DATA_OUT_C <= MEM_L1_C(1);
				elsif GPMC_ADDR_C = x"644" then DATA_OUT_C <= MEM_L1_C(2);
				elsif GPMC_ADDR_C = x"646" then DATA_OUT_C <= MEM_L1_C(3);
				elsif GPMC_ADDR_C = x"648" then DATA_OUT_C <= MEM_L1_C(4);
				elsif GPMC_ADDR_C = x"64A" then DATA_OUT_C <= MEM_L1_C(5);
				elsif GPMC_ADDR_C = x"64C" then DATA_OUT_C <= MEM_L1_C(6);
				elsif GPMC_ADDR_C = x"64E" then DATA_OUT_C <= MEM_L1_C(7);
				elsif GPMC_ADDR_C = x"650" then DATA_OUT_C <= MEM_L1_C(8);
				elsif GPMC_ADDR_C = x"652" then DATA_OUT_C <= MEM_L1_C(9);
				elsif GPMC_ADDR_C = x"654" then DATA_OUT_C <= MEM_L1_C(10);
				elsif GPMC_ADDR_C = x"656" then DATA_OUT_C <= MEM_L1_C(11);
				elsif GPMC_ADDR_C = x"658" then DATA_OUT_C <= MEM_L1_C(12);
				elsif GPMC_ADDR_C = x"65A" then DATA_OUT_C <= MEM_L1_C(13);
				elsif GPMC_ADDR_C = x"65C" then DATA_OUT_C <= MEM_L1_C(14);
				elsif GPMC_ADDR_C = x"65E" then DATA_OUT_C <= MEM_L1_C(15);
				elsif GPMC_ADDR_C = x"660" then DATA_OUT_C <= MEM_L1_C(16);
				elsif GPMC_ADDR_C = x"662" then DATA_OUT_C <= MEM_L1_C(17);
				elsif GPMC_ADDR_C = x"664" then DATA_OUT_C <= MEM_L1_C(18);
				elsif GPMC_ADDR_C = x"666" then DATA_OUT_C <= MEM_L1_C(19);
				elsif GPMC_ADDR_C = x"668" then DATA_OUT_C <= MEM_L1_C(20);
				elsif GPMC_ADDR_C = x"66A" then DATA_OUT_C <= MEM_L1_C(21);
				elsif GPMC_ADDR_C = x"66C" then DATA_OUT_C <= MEM_L1_C(22);
				elsif GPMC_ADDR_C = x"66E" then DATA_OUT_C <= MEM_L1_C(23);
				elsif GPMC_ADDR_C = x"670" then DATA_OUT_C <= MEM_L1_C(24);
				elsif GPMC_ADDR_C = x"672" then DATA_OUT_C <= MEM_L1_C(25);
				elsif GPMC_ADDR_C = x"674" then DATA_OUT_C <= MEM_L1_C(26);
				elsif GPMC_ADDR_C = x"676" then DATA_OUT_C <= MEM_L1_C(27);
				elsif GPMC_ADDR_C = x"678" then DATA_OUT_C <= MEM_L1_C(28);
				elsif GPMC_ADDR_C = x"67A" then DATA_OUT_C <= MEM_L1_C(29);
				elsif GPMC_ADDR_C = x"67C" then DATA_OUT_C <= MEM_L1_C(30);
				elsif GPMC_ADDR_C = x"67E" then DATA_OUT_C <= MEM_L1_C(31);
				elsif GPMC_ADDR_C = x"680" then DATA_OUT_C <= MEM_L1_C(32);
				elsif GPMC_ADDR_C = x"682" then DATA_OUT_C <= MEM_L1_C(33);
				elsif GPMC_ADDR_C = x"684" then DATA_OUT_C <= MEM_L1_C(34);
				elsif GPMC_ADDR_C = x"686" then DATA_OUT_C <= MEM_L1_C(35);
				elsif GPMC_ADDR_C = x"688" then DATA_OUT_C <= MEM_L1_C(36);
				elsif GPMC_ADDR_C = x"68A" then DATA_OUT_C <= MEM_L1_C(37);
				elsif GPMC_ADDR_C = x"68C" then DATA_OUT_C <= MEM_L1_C(38);
				elsif GPMC_ADDR_C = x"68E" then DATA_OUT_C <= MEM_L1_C(39);		
				
				elsif	GPMC_ADDR_C = x"690" then DATA_OUT_C <= MEM_L2_C(0);
				elsif GPMC_ADDR_C = x"692" then DATA_OUT_C <= MEM_L2_C(1);
				elsif GPMC_ADDR_C = x"694" then DATA_OUT_C <= MEM_L2_C(2);
				elsif GPMC_ADDR_C = x"696" then DATA_OUT_C <= MEM_L2_C(3);
				elsif GPMC_ADDR_C = x"698" then DATA_OUT_C <= MEM_L2_C(4);
				elsif GPMC_ADDR_C = x"69A" then DATA_OUT_C <= MEM_L2_C(5);
				elsif GPMC_ADDR_C = x"69C" then DATA_OUT_C <= MEM_L2_C(6);
				elsif GPMC_ADDR_C = x"69E" then DATA_OUT_C <= MEM_L2_C(7);
				elsif GPMC_ADDR_C = x"6A0" then DATA_OUT_C <= MEM_L2_C(8);
				elsif GPMC_ADDR_C = x"6A2" then DATA_OUT_C <= MEM_L2_C(9);
				elsif GPMC_ADDR_C = x"6A4" then DATA_OUT_C <= MEM_L2_C(10);
				elsif GPMC_ADDR_C = x"6A6" then DATA_OUT_C <= MEM_L2_C(11);
				elsif GPMC_ADDR_C = x"6A8" then DATA_OUT_C <= MEM_L2_C(12);
				elsif GPMC_ADDR_C = x"6AA" then DATA_OUT_C <= MEM_L2_C(13);
				elsif GPMC_ADDR_C = x"6AC" then DATA_OUT_C <= MEM_L2_C(14);
				elsif GPMC_ADDR_C = x"6AE" then DATA_OUT_C <= MEM_L2_C(15);
				elsif GPMC_ADDR_C = x"6B0" then DATA_OUT_C <= MEM_L2_C(16);
				elsif GPMC_ADDR_C = x"6B2" then DATA_OUT_C <= MEM_L2_C(17);
				elsif GPMC_ADDR_C = x"6B4" then DATA_OUT_C <= MEM_L2_C(18);
				elsif GPMC_ADDR_C = x"6B6" then DATA_OUT_C <= MEM_L2_C(19);
				elsif GPMC_ADDR_C = x"6B8" then DATA_OUT_C <= MEM_L2_C(20);
				elsif GPMC_ADDR_C = x"6BA" then DATA_OUT_C <= MEM_L2_C(21);
				elsif GPMC_ADDR_C = x"6BC" then DATA_OUT_C <= MEM_L2_C(22);
				elsif GPMC_ADDR_C = x"6BE" then DATA_OUT_C <= MEM_L2_C(23);
				elsif GPMC_ADDR_C = x"6C0" then DATA_OUT_C <= MEM_L2_C(24);
				elsif GPMC_ADDR_C = x"6C2" then DATA_OUT_C <= MEM_L2_C(25);
				elsif GPMC_ADDR_C = x"6C4" then DATA_OUT_C <= MEM_L2_C(26);
				elsif GPMC_ADDR_C = x"6C6" then DATA_OUT_C <= MEM_L2_C(27);
				elsif GPMC_ADDR_C = x"6C8" then DATA_OUT_C <= MEM_L2_C(28);
				elsif GPMC_ADDR_C = x"6CA" then DATA_OUT_C <= MEM_L2_C(29);
				elsif GPMC_ADDR_C = x"6CC" then DATA_OUT_C <= MEM_L2_C(30);
				elsif GPMC_ADDR_C = x"6CE" then DATA_OUT_C <= MEM_L2_C(31);
				elsif GPMC_ADDR_C = x"6D0" then DATA_OUT_C <= MEM_L2_C(32);
				elsif GPMC_ADDR_C = x"6D2" then DATA_OUT_C <= MEM_L2_C(33);
				elsif GPMC_ADDR_C = x"6D4" then DATA_OUT_C <= MEM_L2_C(34);
				elsif GPMC_ADDR_C = x"6D6" then DATA_OUT_C <= MEM_L2_C(35);
				elsif GPMC_ADDR_C = x"6D8" then DATA_OUT_C <= MEM_L2_C(36);
				elsif GPMC_ADDR_C = x"6DA" then DATA_OUT_C <= MEM_L2_C(37);
				elsif GPMC_ADDR_C = x"6DC" then DATA_OUT_C <= MEM_L2_C(38);
				elsif GPMC_ADDR_C = x"6DE" then DATA_OUT_C <= MEM_L2_C(39);		
				
				elsif	GPMC_ADDR_C = x"6E0" then DATA_OUT_C <= MEM_L3_C(0);
				elsif GPMC_ADDR_C = x"6E2" then DATA_OUT_C <= MEM_L3_C(1);
				elsif GPMC_ADDR_C = x"6E4" then DATA_OUT_C <= MEM_L3_C(2);
				elsif GPMC_ADDR_C = x"6E6" then DATA_OUT_C <= MEM_L3_C(3);
				elsif GPMC_ADDR_C = x"6E8" then DATA_OUT_C <= MEM_L3_C(4);
				elsif GPMC_ADDR_C = x"6EA" then DATA_OUT_C <= MEM_L3_C(5);
				elsif GPMC_ADDR_C = x"6EC" then DATA_OUT_C <= MEM_L3_C(6);
				elsif GPMC_ADDR_C = x"6EE" then DATA_OUT_C <= MEM_L3_C(7);
				elsif GPMC_ADDR_C = x"6F0" then DATA_OUT_C <= MEM_L3_C(8);
				elsif GPMC_ADDR_C = x"6F2" then DATA_OUT_C <= MEM_L3_C(9);
				elsif GPMC_ADDR_C = x"6F4" then DATA_OUT_C <= MEM_L3_C(10);
				elsif GPMC_ADDR_C = x"6F6" then DATA_OUT_C <= MEM_L3_C(11);
				elsif GPMC_ADDR_C = x"6F8" then DATA_OUT_C <= MEM_L3_C(12);
				elsif GPMC_ADDR_C = x"6FA" then DATA_OUT_C <= MEM_L3_C(13);
				elsif GPMC_ADDR_C = x"6FC" then DATA_OUT_C <= MEM_L3_C(14);
				elsif GPMC_ADDR_C = x"6FE" then DATA_OUT_C <= MEM_L3_C(15);
				elsif GPMC_ADDR_C = x"700" then DATA_OUT_C <= MEM_L3_C(16);
				elsif GPMC_ADDR_C = x"702" then DATA_OUT_C <= MEM_L3_C(17);
				elsif GPMC_ADDR_C = x"704" then DATA_OUT_C <= MEM_L3_C(18);
				elsif GPMC_ADDR_C = x"706" then DATA_OUT_C <= MEM_L3_C(19);
				elsif GPMC_ADDR_C = x"708" then DATA_OUT_C <= MEM_L3_C(20);
				elsif GPMC_ADDR_C = x"70A" then DATA_OUT_C <= MEM_L3_C(21);
				elsif GPMC_ADDR_C = x"70C" then DATA_OUT_C <= MEM_L3_C(22);
				elsif GPMC_ADDR_C = x"70E" then DATA_OUT_C <= MEM_L3_C(23);
				elsif GPMC_ADDR_C = x"710" then DATA_OUT_C <= MEM_L3_C(24);
				elsif GPMC_ADDR_C = x"712" then DATA_OUT_C <= MEM_L3_C(25);
				elsif GPMC_ADDR_C = x"714" then DATA_OUT_C <= MEM_L3_C(26);
				elsif GPMC_ADDR_C = x"716" then DATA_OUT_C <= MEM_L3_C(27);
				elsif GPMC_ADDR_C = x"718" then DATA_OUT_C <= MEM_L3_C(28);
				elsif GPMC_ADDR_C = x"71A" then DATA_OUT_C <= MEM_L3_C(29);
				elsif GPMC_ADDR_C = x"71C" then DATA_OUT_C <= MEM_L3_C(30);
				elsif GPMC_ADDR_C = x"71E" then DATA_OUT_C <= MEM_L3_C(31);
				elsif GPMC_ADDR_C = x"720" then DATA_OUT_C <= MEM_L3_C(32);
				elsif GPMC_ADDR_C = x"722" then DATA_OUT_C <= MEM_L3_C(33);
				elsif GPMC_ADDR_C = x"724" then DATA_OUT_C <= MEM_L3_C(34);
				elsif GPMC_ADDR_C = x"726" then DATA_OUT_C <= MEM_L3_C(35);
				elsif GPMC_ADDR_C = x"728" then DATA_OUT_C <= MEM_L3_C(36);
				elsif GPMC_ADDR_C = x"72A" then DATA_OUT_C <= MEM_L3_C(37);
				elsif GPMC_ADDR_C = x"72C" then DATA_OUT_C <= MEM_L3_C(38);
				elsif GPMC_ADDR_C = x"72E" then DATA_OUT_C <= MEM_L3_C(39);						
				else									  DATA_OUT_C <= (others => 'Z');
				end if;
			end if;
		
		end if;
	end process;
------------------------------------------------------------------------------------------------
------------------------------------LEG MASTER1-------------------------------------------------
------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------
	WRITE_L1_C_LEG1 		: process(OP_CLK, GPMC_ADDR_L1, GPMC_CSn_L1, GPMC_WEn_L1)
	begin
		if OP_CLK'event and OP_CLK = '1'  then
			
			if GPMC_CSn_L1 = '0' and GPMC_WEn_L1 = '0' then
				if 	GPMC_ADDR_L1 = x"140" then MEM_L1_C(0)  <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"142" then MEM_L1_C(1)  <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"144" then MEM_L1_C(2)  <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"146" then MEM_L1_C(3)  <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"148" then MEM_L1_C(4)  <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"14A" then MEM_L1_C(5)  <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"14C" then MEM_L1_C(6)  <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"14E" then MEM_L1_C(7)  <= GPMC_DATA_L1; 
				elsif	GPMC_ADDR_L1 = x"150" then MEM_L1_C(8)  <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"152" then MEM_L1_C(9)  <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"154" then MEM_L1_C(10) <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"156" then MEM_L1_C(11) <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"158" then MEM_L1_C(12) <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"15A" then MEM_L1_C(13) <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"15C" then MEM_L1_C(14) <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"15E" then MEM_L1_C(15) <= GPMC_DATA_L1; 		
				elsif	GPMC_ADDR_L1 = x"160" then MEM_L1_C(16) <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"162" then MEM_L1_C(17) <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"164" then MEM_L1_C(18) <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"166" then MEM_L1_C(19) <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"168" then MEM_L1_C(20) <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"16A" then MEM_L1_C(21) <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"16C" then MEM_L1_C(22) <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"16E" then MEM_L1_C(23) <= GPMC_DATA_L1; 		
				elsif	GPMC_ADDR_L1 = x"170" then MEM_L1_C(24) <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"172" then MEM_L1_C(25) <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"174" then MEM_L1_C(26) <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"176" then MEM_L1_C(27) <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"178" then MEM_L1_C(28) <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"17A" then MEM_L1_C(29) <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"17C" then MEM_L1_C(30) <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"17E" then MEM_L1_C(31) <= GPMC_DATA_L1;
				elsif	GPMC_ADDR_L1 = x"180" then MEM_L1_C(32) <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"182" then MEM_L1_C(33) <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"184" then MEM_L1_C(34) <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"186" then MEM_L1_C(35) <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"188" then MEM_L1_C(36) <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"18A" then MEM_L1_C(37) <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"18C" then MEM_L1_C(38) <= GPMC_DATA_L1;
				elsif GPMC_ADDR_L1 = x"18E" then MEM_L1_C(39) <= GPMC_DATA_L1; 		 				
				end if;
			end if;	
		
		end if;
	
	end process;
	
	READ_C_L1_LEG1			: process(OP_CLK, GPMC_ADDR_L1, GPMC_CSn_L1, GPMC_OEn_L1)
	begin
		if OP_CLK'event and OP_CLK = '1'  then
			
			if GPMC_CSn_L1 = '0' and GPMC_OEn_L1 = '0' then
				if 	GPMC_ADDR_L1 = x"500" then DATA_OUT_L1 <= MEM_C_Comm(0);
				elsif GPMC_ADDR_L1 = x"502" then DATA_OUT_L1 <= MEM_C_Comm(1);
				elsif GPMC_ADDR_L1 = x"504" then DATA_OUT_L1 <= MEM_C_Comm(2);				
				elsif GPMC_ADDR_L1 = x"506" then DATA_OUT_L1 <= MEM_C_Comm(3);				
				elsif GPMC_ADDR_L1 = x"508" then DATA_OUT_L1 <= MEM_C_Comm(4);
				elsif GPMC_ADDR_L1 = x"50A" then DATA_OUT_L1 <= MEM_C_Comm(5);
				elsif GPMC_ADDR_L1 = x"50C" then DATA_OUT_L1 <= MEM_C_Comm(6);
				elsif GPMC_ADDR_L1 = x"50E" then DATA_OUT_L1 <= MEM_C_Comm(7);
				elsif	GPMC_ADDR_L1 = x"510" then DATA_OUT_L1 <= MEM_C_Comm(8);
				elsif GPMC_ADDR_L1 = x"512" then DATA_OUT_L1 <= MEM_C_Comm(9);
				elsif GPMC_ADDR_L1 = x"514" then DATA_OUT_L1 <= MEM_C_Comm(10);				
				elsif GPMC_ADDR_L1 = x"516" then DATA_OUT_L1 <= MEM_C_Comm(11);				
				elsif GPMC_ADDR_L1 = x"518" then DATA_OUT_L1 <= MEM_C_Comm(12);
				elsif GPMC_ADDR_L1 = x"51A" then DATA_OUT_L1 <= MEM_C_Comm(13);
				elsif GPMC_ADDR_L1 = x"51C" then DATA_OUT_L1 <= MEM_C_Comm(14);
				elsif GPMC_ADDR_L1 = x"51E" then DATA_OUT_L1 <= MEM_C_Comm(15);
				elsif	GPMC_ADDR_L1 = x"520" then DATA_OUT_L1 <= MEM_C_Comm(16);
				elsif GPMC_ADDR_L1 = x"522" then DATA_OUT_L1 <= MEM_C_Comm(17);
				elsif GPMC_ADDR_L1 = x"524" then DATA_OUT_L1 <= MEM_C_Comm(18);				
				elsif GPMC_ADDR_L1 = x"526" then DATA_OUT_L1 <= MEM_C_Comm(19);				
				elsif GPMC_ADDR_L1 = x"528" then DATA_OUT_L1 <= MEM_C_Comm(20);
				elsif GPMC_ADDR_L1 = x"52A" then DATA_OUT_L1 <= MEM_C_Comm(21);
				elsif GPMC_ADDR_L1 = x"52C" then DATA_OUT_L1 <= MEM_C_Comm(22);
				elsif GPMC_ADDR_L1 = x"52E" then DATA_OUT_L1 <= MEM_C_Comm(23);
				elsif	GPMC_ADDR_L1 = x"530" then DATA_OUT_L1 <= MEM_C_Comm(24);
				elsif GPMC_ADDR_L1 = x"532" then DATA_OUT_L1 <= MEM_C_Comm(25);
				elsif GPMC_ADDR_L1 = x"534" then DATA_OUT_L1 <= MEM_C_Comm(26);				
				elsif GPMC_ADDR_L1 = x"536" then DATA_OUT_L1 <= MEM_C_Comm(27);				
				elsif GPMC_ADDR_L1 = x"538" then DATA_OUT_L1 <= MEM_C_Comm(28);
				elsif GPMC_ADDR_L1 = x"53A" then DATA_OUT_L1 <= MEM_C_Comm(29);
				elsif GPMC_ADDR_L1 = x"53C" then DATA_OUT_L1 <= MEM_C_Comm(30);
				elsif GPMC_ADDR_L1 = x"53E" then DATA_OUT_L1 <= MEM_C_Comm(31);
				elsif	GPMC_ADDR_L1 = x"540" then DATA_OUT_L1 <= MEM_C_Comm(32);
				elsif GPMC_ADDR_L1 = x"542" then DATA_OUT_L1 <= MEM_C_Comm(33);
				elsif GPMC_ADDR_L1 = x"544" then DATA_OUT_L1 <= MEM_C_Comm(34);				
				elsif GPMC_ADDR_L1 = x"546" then DATA_OUT_L1 <= MEM_C_Comm(35);				
				elsif GPMC_ADDR_L1 = x"548" then DATA_OUT_L1 <= MEM_C_Comm(36);
				elsif GPMC_ADDR_L1 = x"54A" then DATA_OUT_L1 <= MEM_C_Comm(37);
				elsif GPMC_ADDR_L1 = x"54C" then DATA_OUT_L1 <= MEM_C_Comm(38);
				elsif GPMC_ADDR_L1 = x"54E" then DATA_OUT_L1 <= MEM_C_Comm(39);				
								
				elsif	GPMC_ADDR_L1 = x"550" then DATA_OUT_L1 <= MEM_C_L1(0);
				elsif GPMC_ADDR_L1 = x"552" then DATA_OUT_L1 <= MEM_C_L1(1);
				elsif GPMC_ADDR_L1 = x"554" then DATA_OUT_L1 <= MEM_C_L1(2);				
				elsif GPMC_ADDR_L1 = x"556" then DATA_OUT_L1 <= MEM_C_L1(3);				
				elsif GPMC_ADDR_L1 = x"558" then DATA_OUT_L1 <= MEM_C_L1(4);
				elsif GPMC_ADDR_L1 = x"55A" then DATA_OUT_L1 <= MEM_C_L1(5);
				elsif GPMC_ADDR_L1 = x"55C" then DATA_OUT_L1 <= MEM_C_L1(6);
				elsif GPMC_ADDR_L1 = x"55E" then DATA_OUT_L1 <= MEM_C_L1(7);
				elsif	GPMC_ADDR_L1 = x"560" then DATA_OUT_L1 <= MEM_C_L1(8);
				elsif GPMC_ADDR_L1 = x"562" then DATA_OUT_L1 <= MEM_C_L1(9);
				elsif GPMC_ADDR_L1 = x"564" then DATA_OUT_L1 <= MEM_C_L1(10);				
				elsif GPMC_ADDR_L1 = x"566" then DATA_OUT_L1 <= MEM_C_L1(11);				
				elsif GPMC_ADDR_L1 = x"568" then DATA_OUT_L1 <= MEM_C_L1(12);
				elsif GPMC_ADDR_L1 = x"56A" then DATA_OUT_L1 <= MEM_C_L1(13);
				elsif GPMC_ADDR_L1 = x"56C" then DATA_OUT_L1 <= MEM_C_L1(14);
				elsif GPMC_ADDR_L1 = x"56E" then DATA_OUT_L1 <= MEM_C_L1(15);
				elsif	GPMC_ADDR_L1 = x"570" then DATA_OUT_L1 <= MEM_C_L1(16);
				elsif GPMC_ADDR_L1 = x"572" then DATA_OUT_L1 <= MEM_C_L1(17);
				elsif GPMC_ADDR_L1 = x"574" then DATA_OUT_L1 <= MEM_C_L1(18);				
				elsif GPMC_ADDR_L1 = x"576" then DATA_OUT_L1 <= MEM_C_L1(19);				
				elsif GPMC_ADDR_L1 = x"578" then DATA_OUT_L1 <= MEM_C_L1(20);
				elsif GPMC_ADDR_L1 = x"57A" then DATA_OUT_L1 <= MEM_C_L1(21);
				elsif GPMC_ADDR_L1 = x"57C" then DATA_OUT_L1 <= MEM_C_L1(22);
				elsif GPMC_ADDR_L1 = x"57E" then DATA_OUT_L1 <= MEM_C_L1(23);
				elsif	GPMC_ADDR_L1 = x"580" then DATA_OUT_L1 <= MEM_C_L1(24);
				elsif GPMC_ADDR_L1 = x"582" then DATA_OUT_L1 <= MEM_C_L1(25);
				elsif GPMC_ADDR_L1 = x"584" then DATA_OUT_L1 <= MEM_C_L1(26);				
				elsif GPMC_ADDR_L1 = x"586" then DATA_OUT_L1 <= MEM_C_L1(27);				
				elsif GPMC_ADDR_L1 = x"588" then DATA_OUT_L1 <= MEM_C_L1(28);
				elsif GPMC_ADDR_L1 = x"58A" then DATA_OUT_L1 <= MEM_C_L1(29);
				elsif GPMC_ADDR_L1 = x"58C" then DATA_OUT_L1 <= MEM_C_L1(30);
				elsif GPMC_ADDR_L1 = x"58E" then DATA_OUT_L1 <= MEM_C_L1(31);
				elsif	GPMC_ADDR_L1 = x"590" then DATA_OUT_L1 <= MEM_C_L1(32);
				elsif GPMC_ADDR_L1 = x"592" then DATA_OUT_L1 <= MEM_C_L1(33);
				elsif GPMC_ADDR_L1 = x"594" then DATA_OUT_L1 <= MEM_C_L1(34);				
				elsif GPMC_ADDR_L1 = x"596" then DATA_OUT_L1 <= MEM_C_L1(35);				
				elsif GPMC_ADDR_L1 = x"598" then DATA_OUT_L1 <= MEM_C_L1(36);
				elsif GPMC_ADDR_L1 = x"59A" then DATA_OUT_L1 <= MEM_C_L1(37);
				elsif GPMC_ADDR_L1 = x"59C" then DATA_OUT_L1 <= MEM_C_L1(38);
				elsif GPMC_ADDR_L1 = x"59E" then DATA_OUT_L1 <= MEM_C_L1(39);	
				else									   DATA_OUT_L1 <= (others => 'Z');
				end if;
			end if;	
		
		end if;
	end process;
------------------------------------------------------------------------------------------------
------------------------------------LEG MASTER2-------------------------------------------------
------------------------------------------------------------------------------------------------
	WRITE_L2_C_LEG2 		: process(OP_CLK, GPMC_ADDR_L2, GPMC_CSn_L2, GPMC_WEn_L2)
	begin
		if OP_CLK'event and OP_CLK = '1'  then
			
			if GPMC_CSn_L2 = '0' and GPMC_WEn_L2 = '0' then
				if 	GPMC_ADDR_L2 = x"190" then MEM_L2_C(0)  <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"192" then MEM_L2_C(1)  <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"194" then MEM_L2_C(2)  <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"196" then MEM_L2_C(3)  <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"198" then MEM_L2_C(4)  <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"19A" then MEM_L2_C(5)  <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"19C" then MEM_L2_C(6)  <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"19E" then MEM_L2_C(7)  <= GPMC_DATA_L2; 
				elsif	GPMC_ADDR_L2 = x"1A0" then MEM_L2_C(8)  <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"1A2" then MEM_L2_C(9)  <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"1A4" then MEM_L2_C(10) <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"1A6" then MEM_L2_C(11) <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"1A8" then MEM_L2_C(12) <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"1AA" then MEM_L2_C(13) <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"1AC" then MEM_L2_C(14) <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"1AE" then MEM_L2_C(15) <= GPMC_DATA_L2; 		
				elsif	GPMC_ADDR_L2 = x"1B0" then MEM_L2_C(16) <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"1B2" then MEM_L2_C(17) <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"1B4" then MEM_L2_C(18) <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"1B6" then MEM_L2_C(19) <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"1B8" then MEM_L2_C(20) <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"1BA" then MEM_L2_C(21) <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"1BC" then MEM_L2_C(22) <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"1BE" then MEM_L2_C(23) <= GPMC_DATA_L2; 		
				elsif	GPMC_ADDR_L2 = x"1C0" then MEM_L2_C(24) <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"1C2" then MEM_L2_C(25) <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"1C4" then MEM_L2_C(26) <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"1C6" then MEM_L2_C(27) <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"1C8" then MEM_L2_C(28) <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"1CA" then MEM_L2_C(29) <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"1CC" then MEM_L2_C(30) <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"1CE" then MEM_L2_C(31) <= GPMC_DATA_L2;
				elsif	GPMC_ADDR_L2 = x"1D0" then MEM_L2_C(32) <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"1D2" then MEM_L2_C(33) <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"1D4" then MEM_L2_C(34) <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"1D6" then MEM_L2_C(35) <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"1D8" then MEM_L2_C(36) <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"1DA" then MEM_L2_C(37) <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"1DC" then MEM_L2_C(38) <= GPMC_DATA_L2;
				elsif GPMC_ADDR_L2 = x"1DE" then MEM_L2_C(39) <= GPMC_DATA_L2; 		 				
				end if;
			end if;	
		
		end if;
	
	end process;
	
	READ_C_L2_LEG2			: process(OP_CLK, GPMC_ADDR_L2, GPMC_CSn_L2, GPMC_OEn_L2)
	begin
		if OP_CLK'event and OP_CLK = '1'  then
			
			if GPMC_CSn_L2 = '0' and GPMC_OEn_L2 = '0' then
				if 	GPMC_ADDR_L2 = x"500" then DATA_OUT_L2 <= MEM_C_Comm(0);
				elsif GPMC_ADDR_L2 = x"502" then DATA_OUT_L2 <= MEM_C_Comm(1);
				elsif GPMC_ADDR_L2 = x"504" then DATA_OUT_L2 <= MEM_C_Comm(2);				
				elsif GPMC_ADDR_L2 = x"506" then DATA_OUT_L2 <= MEM_C_Comm(3);				
				elsif GPMC_ADDR_L2 = x"508" then DATA_OUT_L2 <= MEM_C_Comm(4);
				elsif GPMC_ADDR_L2 = x"50A" then DATA_OUT_L2 <= MEM_C_Comm(5);
				elsif GPMC_ADDR_L2 = x"50C" then DATA_OUT_L2 <= MEM_C_Comm(6);
				elsif GPMC_ADDR_L2 = x"50E" then DATA_OUT_L2 <= MEM_C_Comm(7);
				elsif	GPMC_ADDR_L2 = x"510" then DATA_OUT_L2 <= MEM_C_Comm(8);
				elsif GPMC_ADDR_L2 = x"512" then DATA_OUT_L2 <= MEM_C_Comm(9);
				elsif GPMC_ADDR_L2 = x"514" then DATA_OUT_L2 <= MEM_C_Comm(10);				
				elsif GPMC_ADDR_L2 = x"516" then DATA_OUT_L2 <= MEM_C_Comm(11);				
				elsif GPMC_ADDR_L2 = x"518" then DATA_OUT_L2 <= MEM_C_Comm(12);
				elsif GPMC_ADDR_L2 = x"51A" then DATA_OUT_L2 <= MEM_C_Comm(13);
				elsif GPMC_ADDR_L2 = x"51C" then DATA_OUT_L2 <= MEM_C_Comm(14);
				elsif GPMC_ADDR_L2 = x"51E" then DATA_OUT_L2 <= MEM_C_Comm(15);
				elsif	GPMC_ADDR_L2 = x"520" then DATA_OUT_L2 <= MEM_C_Comm(16);
				elsif GPMC_ADDR_L2 = x"522" then DATA_OUT_L2 <= MEM_C_Comm(17);
				elsif GPMC_ADDR_L2 = x"524" then DATA_OUT_L2 <= MEM_C_Comm(18);				
				elsif GPMC_ADDR_L2 = x"526" then DATA_OUT_L2 <= MEM_C_Comm(19);				
				elsif GPMC_ADDR_L2 = x"528" then DATA_OUT_L2 <= MEM_C_Comm(20);
				elsif GPMC_ADDR_L2 = x"52A" then DATA_OUT_L2 <= MEM_C_Comm(21);
				elsif GPMC_ADDR_L2 = x"52C" then DATA_OUT_L2 <= MEM_C_Comm(22);
				elsif GPMC_ADDR_L2 = x"52E" then DATA_OUT_L2 <= MEM_C_Comm(23);
				elsif	GPMC_ADDR_L2 = x"530" then DATA_OUT_L2 <= MEM_C_Comm(24);
				elsif GPMC_ADDR_L2 = x"532" then DATA_OUT_L2 <= MEM_C_Comm(25);
				elsif GPMC_ADDR_L2 = x"534" then DATA_OUT_L2 <= MEM_C_Comm(26);				
				elsif GPMC_ADDR_L2 = x"536" then DATA_OUT_L2 <= MEM_C_Comm(27);				
				elsif GPMC_ADDR_L2 = x"538" then DATA_OUT_L2 <= MEM_C_Comm(28);
				elsif GPMC_ADDR_L2 = x"53A" then DATA_OUT_L2 <= MEM_C_Comm(29);
				elsif GPMC_ADDR_L2 = x"53C" then DATA_OUT_L2 <= MEM_C_Comm(30);
				elsif GPMC_ADDR_L2 = x"53E" then DATA_OUT_L2 <= MEM_C_Comm(31);
				elsif	GPMC_ADDR_L2 = x"540" then DATA_OUT_L2 <= MEM_C_Comm(32);
				elsif GPMC_ADDR_L2 = x"542" then DATA_OUT_L2 <= MEM_C_Comm(33);
				elsif GPMC_ADDR_L2 = x"544" then DATA_OUT_L2 <= MEM_C_Comm(34);				
				elsif GPMC_ADDR_L2 = x"546" then DATA_OUT_L2 <= MEM_C_Comm(35);				
				elsif GPMC_ADDR_L2 = x"548" then DATA_OUT_L2 <= MEM_C_Comm(36);
				elsif GPMC_ADDR_L2 = x"54A" then DATA_OUT_L2 <= MEM_C_Comm(37);
				elsif GPMC_ADDR_L2 = x"54C" then DATA_OUT_L2 <= MEM_C_Comm(38);
				elsif GPMC_ADDR_L2 = x"54E" then DATA_OUT_L2 <= MEM_C_Comm(39);				
								
				elsif	GPMC_ADDR_L2 = x"5A0" then DATA_OUT_L2 <= MEM_C_L2(0);
				elsif GPMC_ADDR_L2 = x"5A2" then DATA_OUT_L2 <= MEM_C_L2(1);
				elsif GPMC_ADDR_L2 = x"5A4" then DATA_OUT_L2 <= MEM_C_L2(2);				
				elsif GPMC_ADDR_L2 = x"5A6" then DATA_OUT_L2 <= MEM_C_L2(3);				
				elsif GPMC_ADDR_L2 = x"5A8" then DATA_OUT_L2 <= MEM_C_L2(4);
				elsif GPMC_ADDR_L2 = x"5AA" then DATA_OUT_L2 <= MEM_C_L2(5);
				elsif GPMC_ADDR_L2 = x"5AC" then DATA_OUT_L2 <= MEM_C_L2(6);
				elsif GPMC_ADDR_L2 = x"5AE" then DATA_OUT_L2 <= MEM_C_L2(7);
				elsif	GPMC_ADDR_L2 = x"5B0" then DATA_OUT_L2 <= MEM_C_L2(8);
				elsif GPMC_ADDR_L2 = x"5B2" then DATA_OUT_L2 <= MEM_C_L2(9);
				elsif GPMC_ADDR_L2 = x"5B4" then DATA_OUT_L2 <= MEM_C_L2(10);				
				elsif GPMC_ADDR_L2 = x"5B6" then DATA_OUT_L2 <= MEM_C_L2(11);				
				elsif GPMC_ADDR_L2 = x"5B8" then DATA_OUT_L2 <= MEM_C_L2(12);
				elsif GPMC_ADDR_L2 = x"5BA" then DATA_OUT_L2 <= MEM_C_L2(13);
				elsif GPMC_ADDR_L2 = x"5BC" then DATA_OUT_L2 <= MEM_C_L2(14);
				elsif GPMC_ADDR_L2 = x"5BE" then DATA_OUT_L2 <= MEM_C_L2(15);
				elsif	GPMC_ADDR_L2 = x"5C0" then DATA_OUT_L2 <= MEM_C_L2(16);
				elsif GPMC_ADDR_L2 = x"5C2" then DATA_OUT_L2 <= MEM_C_L2(17);
				elsif GPMC_ADDR_L2 = x"5C4" then DATA_OUT_L2 <= MEM_C_L2(18);				
				elsif GPMC_ADDR_L2 = x"5C6" then DATA_OUT_L2 <= MEM_C_L2(19);				
				elsif GPMC_ADDR_L2 = x"5C8" then DATA_OUT_L2 <= MEM_C_L2(20);
				elsif GPMC_ADDR_L2 = x"5CA" then DATA_OUT_L2 <= MEM_C_L2(21);
				elsif GPMC_ADDR_L2 = x"5CC" then DATA_OUT_L2 <= MEM_C_L2(22);
				elsif GPMC_ADDR_L2 = x"5CE" then DATA_OUT_L2 <= MEM_C_L2(23);
				elsif	GPMC_ADDR_L2 = x"5D0" then DATA_OUT_L2 <= MEM_C_L2(24);
				elsif GPMC_ADDR_L2 = x"5D2" then DATA_OUT_L2 <= MEM_C_L2(25);
				elsif GPMC_ADDR_L2 = x"5D4" then DATA_OUT_L2 <= MEM_C_L2(26);				
				elsif GPMC_ADDR_L2 = x"5D6" then DATA_OUT_L2 <= MEM_C_L2(27);				
				elsif GPMC_ADDR_L2 = x"5D8" then DATA_OUT_L2 <= MEM_C_L2(28);
				elsif GPMC_ADDR_L2 = x"5DA" then DATA_OUT_L2 <= MEM_C_L2(29);
				elsif GPMC_ADDR_L2 = x"5DC" then DATA_OUT_L2 <= MEM_C_L2(30);
				elsif GPMC_ADDR_L2 = x"5DE" then DATA_OUT_L2 <= MEM_C_L2(31);
				elsif	GPMC_ADDR_L2 = x"5E0" then DATA_OUT_L2 <= MEM_C_L2(32);
				elsif GPMC_ADDR_L2 = x"5E2" then DATA_OUT_L2 <= MEM_C_L2(33);
				elsif GPMC_ADDR_L2 = x"5E4" then DATA_OUT_L2 <= MEM_C_L2(34);				
				elsif GPMC_ADDR_L2 = x"5E6" then DATA_OUT_L2 <= MEM_C_L2(35);				
				elsif GPMC_ADDR_L2 = x"5E8" then DATA_OUT_L2 <= MEM_C_L2(36);
				elsif GPMC_ADDR_L2 = x"5EA" then DATA_OUT_L2 <= MEM_C_L2(37);
				elsif GPMC_ADDR_L2 = x"5EC" then DATA_OUT_L2 <= MEM_C_L2(38);
				elsif GPMC_ADDR_L2 = x"5EE" then DATA_OUT_L2 <= MEM_C_L2(39);	
				else									   DATA_OUT_L2 <= (others => 'Z');
				end if;
			end if;	
		
		end if;
	end process;


------------------------------------------------------------------------------------------------
------------------------------------LEG MASTER3-------------------------------------------------
------------------------------------------------------------------------------------------------	
	WRITE_L3_C_LEG3 		: process(OP_CLK, GPMC_ADDR_L3, GPMC_CSn_L3, GPMC_WEn_L3)
	begin
		if OP_CLK'event and OP_CLK = '1'  then
			
			if GPMC_CSn_L3 = '0' and GPMC_WEn_L3 = '0' then
				if 	GPMC_ADDR_L3 = x"1E0" then MEM_L3_C(0)  <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"1E2" then MEM_L3_C(1)  <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"1E4" then MEM_L3_C(2)  <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"1E6" then MEM_L3_C(3)  <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"1E8" then MEM_L3_C(4)  <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"1EA" then MEM_L3_C(5)  <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"1EC" then MEM_L3_C(6)  <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"1EE" then MEM_L3_C(7)  <= GPMC_DATA_L3; 
				elsif	GPMC_ADDR_L3 = x"1F0" then MEM_L3_C(8)  <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"1F2" then MEM_L3_C(9)  <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"1F4" then MEM_L3_C(10) <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"1F6" then MEM_L3_C(11) <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"1F8" then MEM_L3_C(12) <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"1FA" then MEM_L3_C(13) <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"1FC" then MEM_L3_C(14) <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"1FE" then MEM_L3_C(15) <= GPMC_DATA_L3; 		
				elsif	GPMC_ADDR_L3 = x"200" then MEM_L3_C(16) <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"202" then MEM_L3_C(17) <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"204" then MEM_L3_C(18) <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"206" then MEM_L3_C(19) <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"208" then MEM_L3_C(20) <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"20A" then MEM_L3_C(21) <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"20C" then MEM_L3_C(22) <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"20E" then MEM_L3_C(23) <= GPMC_DATA_L3; 		
				elsif	GPMC_ADDR_L3 = x"210" then MEM_L3_C(24) <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"212" then MEM_L3_C(25) <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"214" then MEM_L3_C(26) <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"216" then MEM_L3_C(27) <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"218" then MEM_L3_C(28) <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"21A" then MEM_L3_C(29) <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"21C" then MEM_L3_C(30) <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"21E" then MEM_L3_C(31) <= GPMC_DATA_L3;
				elsif	GPMC_ADDR_L3 = x"220" then MEM_L3_C(32) <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"222" then MEM_L3_C(33) <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"224" then MEM_L3_C(34) <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"226" then MEM_L3_C(35) <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"228" then MEM_L3_C(36) <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"22A" then MEM_L3_C(37) <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"22C" then MEM_L3_C(38) <= GPMC_DATA_L3;
				elsif GPMC_ADDR_L3 = x"22E" then MEM_L3_C(39) <= GPMC_DATA_L3; 		 				
				end if;
			end if;	
		
		end if;
	
	end process;
	
	READ_C_L3_LEG3			: process(OP_CLK, GPMC_ADDR_L3, GPMC_CSn_L3, GPMC_OEn_L3)
	begin
		if OP_CLK'event and OP_CLK = '1'  then
			
			if GPMC_CSn_L3 = '0' and GPMC_OEn_L3 = '0' then
				if 	GPMC_ADDR_L3 = x"500" then DATA_OUT_L3 <= MEM_C_Comm(0);
				elsif GPMC_ADDR_L3 = x"502" then DATA_OUT_L3 <= MEM_C_Comm(1);
				elsif GPMC_ADDR_L3 = x"504" then DATA_OUT_L3 <= MEM_C_Comm(2);				
				elsif GPMC_ADDR_L3 = x"506" then DATA_OUT_L3 <= MEM_C_Comm(3);				
				elsif GPMC_ADDR_L3 = x"508" then DATA_OUT_L3 <= MEM_C_Comm(4);
				elsif GPMC_ADDR_L3 = x"50A" then DATA_OUT_L3 <= MEM_C_Comm(5);
				elsif GPMC_ADDR_L3 = x"50C" then DATA_OUT_L3 <= MEM_C_Comm(6);
				elsif GPMC_ADDR_L3 = x"50E" then DATA_OUT_L3 <= MEM_C_Comm(7);
				elsif	GPMC_ADDR_L3 = x"510" then DATA_OUT_L3 <= MEM_C_Comm(8);
				elsif GPMC_ADDR_L3 = x"512" then DATA_OUT_L3 <= MEM_C_Comm(9);
				elsif GPMC_ADDR_L3 = x"514" then DATA_OUT_L3 <= MEM_C_Comm(10);				
				elsif GPMC_ADDR_L3 = x"516" then DATA_OUT_L3 <= MEM_C_Comm(11);				
				elsif GPMC_ADDR_L3 = x"518" then DATA_OUT_L3 <= MEM_C_Comm(12);
				elsif GPMC_ADDR_L3 = x"51A" then DATA_OUT_L3 <= MEM_C_Comm(13);
				elsif GPMC_ADDR_L3 = x"51C" then DATA_OUT_L3 <= MEM_C_Comm(14);
				elsif GPMC_ADDR_L3 = x"51E" then DATA_OUT_L3 <= MEM_C_Comm(15);
				elsif	GPMC_ADDR_L3 = x"520" then DATA_OUT_L3 <= MEM_C_Comm(16);
				elsif GPMC_ADDR_L3 = x"522" then DATA_OUT_L3 <= MEM_C_Comm(17);
				elsif GPMC_ADDR_L3 = x"524" then DATA_OUT_L3 <= MEM_C_Comm(18);				
				elsif GPMC_ADDR_L3 = x"526" then DATA_OUT_L3 <= MEM_C_Comm(19);				
				elsif GPMC_ADDR_L3 = x"528" then DATA_OUT_L3 <= MEM_C_Comm(20);
				elsif GPMC_ADDR_L3 = x"52A" then DATA_OUT_L3 <= MEM_C_Comm(21);
				elsif GPMC_ADDR_L3 = x"52C" then DATA_OUT_L3 <= MEM_C_Comm(22);
				elsif GPMC_ADDR_L3 = x"52E" then DATA_OUT_L3 <= MEM_C_Comm(23);
				elsif	GPMC_ADDR_L3 = x"530" then DATA_OUT_L3 <= MEM_C_Comm(24);
				elsif GPMC_ADDR_L3 = x"532" then DATA_OUT_L3 <= MEM_C_Comm(25);
				elsif GPMC_ADDR_L3 = x"534" then DATA_OUT_L3 <= MEM_C_Comm(26);				
				elsif GPMC_ADDR_L3 = x"536" then DATA_OUT_L3 <= MEM_C_Comm(27);				
				elsif GPMC_ADDR_L3 = x"538" then DATA_OUT_L3 <= MEM_C_Comm(28);
				elsif GPMC_ADDR_L3 = x"53A" then DATA_OUT_L3 <= MEM_C_Comm(29);
				elsif GPMC_ADDR_L3 = x"53C" then DATA_OUT_L3 <= MEM_C_Comm(30);
				elsif GPMC_ADDR_L3 = x"53E" then DATA_OUT_L3 <= MEM_C_Comm(31);
				elsif	GPMC_ADDR_L3 = x"540" then DATA_OUT_L3 <= MEM_C_Comm(32);
				elsif GPMC_ADDR_L3 = x"542" then DATA_OUT_L3 <= MEM_C_Comm(33);
				elsif GPMC_ADDR_L3 = x"544" then DATA_OUT_L3 <= MEM_C_Comm(34);				
				elsif GPMC_ADDR_L3 = x"546" then DATA_OUT_L3 <= MEM_C_Comm(35);				
				elsif GPMC_ADDR_L3 = x"548" then DATA_OUT_L3 <= MEM_C_Comm(36);
				elsif GPMC_ADDR_L3 = x"54A" then DATA_OUT_L3 <= MEM_C_Comm(37);
				elsif GPMC_ADDR_L3 = x"54C" then DATA_OUT_L3 <= MEM_C_Comm(38);
				elsif GPMC_ADDR_L3 = x"54E" then DATA_OUT_L3 <= MEM_C_Comm(39);				
								
				elsif	GPMC_ADDR_L3 = x"5F0" then DATA_OUT_L3 <= MEM_C_L3(0);
				elsif GPMC_ADDR_L3 = x"5F2" then DATA_OUT_L3 <= MEM_C_L3(1);
				elsif GPMC_ADDR_L3 = x"5F4" then DATA_OUT_L3 <= MEM_C_L3(2);				
				elsif GPMC_ADDR_L3 = x"5F6" then DATA_OUT_L3 <= MEM_C_L3(3);				
				elsif GPMC_ADDR_L3 = x"5F8" then DATA_OUT_L3 <= MEM_C_L3(4);
				elsif GPMC_ADDR_L3 = x"5FA" then DATA_OUT_L3 <= MEM_C_L3(5);
				elsif GPMC_ADDR_L3 = x"5FC" then DATA_OUT_L3 <= MEM_C_L3(6);
				elsif GPMC_ADDR_L3 = x"5FE" then DATA_OUT_L3 <= MEM_C_L3(7);
				elsif	GPMC_ADDR_L3 = x"600" then DATA_OUT_L3 <= MEM_C_L3(8);
				elsif GPMC_ADDR_L3 = x"602" then DATA_OUT_L3 <= MEM_C_L3(9);
				elsif GPMC_ADDR_L3 = x"604" then DATA_OUT_L3 <= MEM_C_L3(10);				
				elsif GPMC_ADDR_L3 = x"606" then DATA_OUT_L3 <= MEM_C_L3(11);				
				elsif GPMC_ADDR_L3 = x"608" then DATA_OUT_L3 <= MEM_C_L3(12);
				elsif GPMC_ADDR_L3 = x"60A" then DATA_OUT_L3 <= MEM_C_L3(13);
				elsif GPMC_ADDR_L3 = x"60C" then DATA_OUT_L3 <= MEM_C_L3(14);
				elsif GPMC_ADDR_L3 = x"60E" then DATA_OUT_L3 <= MEM_C_L3(15);
				elsif	GPMC_ADDR_L3 = x"610" then DATA_OUT_L3 <= MEM_C_L3(16);
				elsif GPMC_ADDR_L3 = x"612" then DATA_OUT_L3 <= MEM_C_L3(17);
				elsif GPMC_ADDR_L3 = x"614" then DATA_OUT_L3 <= MEM_C_L3(18);				
				elsif GPMC_ADDR_L3 = x"616" then DATA_OUT_L3 <= MEM_C_L3(19);				
				elsif GPMC_ADDR_L3 = x"618" then DATA_OUT_L3 <= MEM_C_L3(20);
				elsif GPMC_ADDR_L3 = x"61A" then DATA_OUT_L3 <= MEM_C_L3(21);
				elsif GPMC_ADDR_L3 = x"61C" then DATA_OUT_L3 <= MEM_C_L3(22);
				elsif GPMC_ADDR_L3 = x"61E" then DATA_OUT_L3 <= MEM_C_L3(23);
				elsif	GPMC_ADDR_L3 = x"620" then DATA_OUT_L3 <= MEM_C_L3(24);
				elsif GPMC_ADDR_L3 = x"622" then DATA_OUT_L3 <= MEM_C_L3(25);
				elsif GPMC_ADDR_L3 = x"624" then DATA_OUT_L3 <= MEM_C_L3(26);				
				elsif GPMC_ADDR_L3 = x"626" then DATA_OUT_L3 <= MEM_C_L3(27);				
				elsif GPMC_ADDR_L3 = x"628" then DATA_OUT_L3 <= MEM_C_L3(28);
				elsif GPMC_ADDR_L3 = x"62A" then DATA_OUT_L3 <= MEM_C_L3(29);
				elsif GPMC_ADDR_L3 = x"62C" then DATA_OUT_L3 <= MEM_C_L3(30);
				elsif GPMC_ADDR_L3 = x"62E" then DATA_OUT_L3 <= MEM_C_L3(31);
				elsif	GPMC_ADDR_L3 = x"630" then DATA_OUT_L3 <= MEM_C_L3(32);
				elsif GPMC_ADDR_L3 = x"632" then DATA_OUT_L3 <= MEM_C_L3(33);
				elsif GPMC_ADDR_L3 = x"634" then DATA_OUT_L3 <= MEM_C_L3(34);				
				elsif GPMC_ADDR_L3 = x"636" then DATA_OUT_L3 <= MEM_C_L3(35);				
				elsif GPMC_ADDR_L3 = x"638" then DATA_OUT_L3 <= MEM_C_L3(36);
				elsif GPMC_ADDR_L3 = x"63A" then DATA_OUT_L3 <= MEM_C_L3(37);
				elsif GPMC_ADDR_L3 = x"63C" then DATA_OUT_L3 <= MEM_C_L3(38);
				elsif GPMC_ADDR_L3 = x"63E" then DATA_OUT_L3 <= MEM_C_L3(39);	
				else									   DATA_OUT_L3 <= (others => 'Z');
				end if;
			end if;	
		
		end if;
	end process;

end arch;
	