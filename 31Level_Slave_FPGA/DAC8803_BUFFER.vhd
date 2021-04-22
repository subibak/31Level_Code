library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity DAC8803_BUFFER is

	port(
			OP_CLK				:  in std_logic;
			DAC8803_CH1n		:	in std_logic;									-- DAC8803_CH1
			DAC8803_CH2n		:	in std_logic;									-- DAC8803_CH1
			DAC8803_CH3n		:	in std_logic;									-- DAC8803_CH1
			DAC8803_CH4n		:	in std_logic;									-- DAC8803_CH1
			DAC8803_CH5n		:	in std_logic;									-- DAC8803_CH1
			DAC8803_CH6n		:	in std_logic;									-- DAC8803_CH1
			DAC8803_CH7n		:	in std_logic;									-- DAC8803_CH1
			DAC8803_CH8n		:	in std_logic;									-- DAC8803_CH1
			DAC8803_GENn		:	in std_logic;									-- DAC8803_GEN
			DAC_DATA_IN			:	in std_logic_vector(15 downto 0);
			
			nDAC_CS				:  out std_logic;
			nDAC_Load1 			:  out std_logic;
			nDAC_Load2			:  out std_logic;
			DAC_DATA_OUT		:	out std_logic_vector(15 downto 0)
	);
	

end DAC8803_BUFFER;


architecture arch of DAC8803_BUFFER is

	signal da_cs_cnt		:	std_logic_vector(15 downto 0) := (others => '0');
	signal da_cs_o 		: 	std_logic := '1';
	signal da_ld1_o		: 	std_logic := '1';
	signal da_ld2_o		: 	std_logic := '1';
	signal CS_GEN_FLAG	:  std_logic := '0';
	signal CH1_buffer		: 	std_logic_vector(15 downto 0) := (others => '0');
	signal CH2_buffer		: 	std_logic_vector(15 downto 0) := (others => '0');
	signal CH3_buffer		: 	std_logic_vector(15 downto 0) := (others => '0');
	signal CH4_buffer		: 	std_logic_vector(15 downto 0) := (others => '0');
	signal CH5_buffer		: 	std_logic_vector(15 downto 0) := (others => '0');
	signal CH6_buffer		: 	std_logic_vector(15 downto 0) := (others => '0');
	signal CH7_buffer		: 	std_logic_vector(15 downto 0) := (others => '0');
	signal CH8_buffer		: 	std_logic_vector(15 downto 0) := (others => '0');
	signal Buffer_Out		:  std_logic_vector(15 downto 0) := (others => '0');
	
begin 
	
	CH1_STORAGE : process(DAC8803_CH1n)
	begin
							
		if	DAC8803_CH1n = '0' then
			CH1_buffer <= DAC_DATA_IN;
		end if;

	end process;
	
	CH2_STORAGE : process(DAC8803_CH2n)
	begin
							
		if	DAC8803_CH2n = '0' then
			CH2_buffer <= DAC_DATA_IN;
		end if;

	end process;
	
	CH3_STORAGE : process(DAC8803_CH3n)
	begin
							
		if	DAC8803_CH3n = '0' then
			CH3_buffer <= DAC_DATA_IN;
		end if;

	end process;
	
	CH4_STORAGE : process(DAC8803_CH4n)
	begin
							
		if	DAC8803_CH4n = '0' then
			CH4_buffer <= DAC_DATA_IN;
		end if;

	end process;
	
	CH5_STORAGE : process(DAC8803_CH5n)
	begin
							
		if	DAC8803_CH5n = '0' then
			CH5_buffer <= DAC_DATA_IN;
		end if;

	end process;
	
	CH6_STORAGE : process(DAC8803_CH6n)
	begin
							
		if	DAC8803_CH6n = '0' then
			CH6_buffer <= DAC_DATA_IN;
		end if;

	end process;
	
	CH7_STORAGE : process( DAC8803_CH7n)
	begin
							
		if	DAC8803_CH7n = '0' then
			CH7_buffer <= DAC_DATA_IN;
		end if;

	end process;
	
	CH8_STORAGE : process(DAC8803_CH8n)
	begin
							
		if	DAC8803_CH8n = '0' then
			CH8_buffer <= DAC_DATA_IN;
		end if;

	end process;

	SENDING : process(DAC8803_GENn, CS_GEN_FLAG, OP_CLK, Buffer_Out, da_cs_o, da_ld1_o, da_ld2_o)
	begin
		
		if DAC8803_GENn = '0'  then
		
			CS_GEN_FLAG <= '1';
		
		elsif CS_GEN_FLAG = '1' then
			
			if OP_CLK'event and OP_CLK = '1' then
				
				da_cs_cnt <= da_cs_cnt + '1';
					
				if da_cs_cnt >= 1 and da_cs_cnt < 6 then
					da_cs_o <= '0';
					Buffer_Out <= CH1_buffer;
				elsif da_cs_cnt >= 6 and da_cs_cnt < 257 then
					da_cs_o <= '1';
				elsif da_cs_cnt >= 257 and da_cs_cnt < 262 then
					da_cs_o <= '0';
					Buffer_Out <= CH2_buffer;
				elsif da_cs_cnt >= 262 and da_cs_cnt < 513 then
					da_cs_o <= '1';
				elsif da_cs_cnt >= 513 and da_cs_cnt < 518 then
					da_cs_o <= '0';
					Buffer_Out <= CH3_buffer;
				elsif da_cs_cnt >= 518 and da_cs_cnt < 769 then
					da_cs_o <= '1';
				elsif da_cs_cnt >= 769 and da_cs_cnt < 774 then
					da_cs_o <= '0';
					Buffer_Out <= CH4_buffer;
				elsif da_cs_cnt >= 774 and da_cs_cnt < 775 then
					da_cs_o <= '1';
				elsif da_cs_cnt >= 879 and da_cs_cnt < 884 then			-- LD1 
					da_ld1_o <= '0';
				elsif da_cs_cnt >= 884 and da_cs_cnt < 1135 then
					da_ld1_o <= '1';
				elsif da_cs_cnt >= 1135 and da_cs_cnt < 1140 then
					da_cs_o <= '0';
					Buffer_Out <= CH5_buffer;
				elsif da_cs_cnt >= 1140 and da_cs_cnt < 1391 then
					da_cs_o <= '1';
				elsif da_cs_cnt >= 1391 and da_cs_cnt < 1396 then
					da_cs_o <= '0';
					Buffer_Out <= CH6_buffer;
				elsif da_cs_cnt >= 1396 and da_cs_cnt < 1647 then
					da_cs_o <= '1';	
				elsif da_cs_cnt >= 1647 and da_cs_cnt < 1652 then
					da_cs_o <= '0';
					Buffer_Out <= CH7_buffer;
				elsif da_cs_cnt >= 1652 and da_cs_cnt < 1903 then
					da_cs_o <= '1';		
				elsif da_cs_cnt >= 1903 and da_cs_cnt < 1908 then
					da_cs_o <= '0';
					Buffer_Out <= CH8_buffer;
				elsif da_cs_cnt >= 1908 and da_cs_cnt < 1909 then
					da_cs_o <= '1';	
				elsif da_cs_cnt >= 2010 and da_cs_cnt < 2015	then			-- LD2
					da_ld2_o <= '0';
				elsif da_cs_cnt >= 2015 and da_cs_cnt < 2016 then
					da_ld2_o <= '1';	
				elsif da_cs_cnt >= 2231 then
					da_cs_cnt <= (others => '0');
					CS_GEN_FLAG <= '0';			
				end if;
			end if;
		end if;
		
		DAC_DATA_OUT <= Buffer_Out;
		nDAC_CS <= da_cs_o;
		nDAC_Load1 <= da_ld1_o;
		nDAC_Load2 <= da_ld2_o;

	end process;

end arch;
