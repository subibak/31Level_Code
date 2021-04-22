library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;


entity GATING_COMPARATOR is

	port(
				OP_CLK	 				:	in std_logic;
				
				EMIF_ADDR				:	in std_logic_vector(11 downto 0);
				EM1CS2n					:	in std_logic;
				EM1WEn					: 	in std_logic;	
				EMIF_DATA				: 	in std_logic_vector(13 downto 0);		
				
				SM_A1_CARRIER				:	in std_logic_vector(13 downto 0);
				SM_A1_SEQ					:	in std_logic;
				SM_A2_CARRIER				:	in std_logic_vector(13 downto 0);
				SM_A2_SEQ					:	in std_logic;
				SM_A3_CARRIER				:	in std_logic_vector(13 downto 0);
				SM_A3_SEQ					:	in std_logic;
				SM_B1_CARRIER				:	in std_logic_vector(13 downto 0);
				SM_B1_SEQ					:	in std_logic;
				SM_B2_CARRIER				:	in std_logic_vector(13 downto 0);
				SM_B5_SEQ					:	in std_logic;
				SM_B3_CARRIER				:	in std_logic_vector(13 downto 0);
				SM_B6_SEQ					:	in std_logic;
	
				SM_A1_GATING				: 	out std_logic;
				SM_A2_GATING				: 	out std_logic;
				SM_A3_GATING				: 	out std_logic;
				SM_B1_GATING				: 	out std_logic;
				SM_B2_GATING				: 	out std_logic;
				SM_B3_GATING				: 	out std_logic;
				Check_point					: 	out std_logic
			);

end GATING_COMPARATOR;


architecture arch of GATING_COMPARATOR is
  
	signal 	REF_MAX				:	std_logic_vector(13 downto 0) := "10011100010000";  
	signal 	REF_MIN				:	std_logic_vector(13 downto 0) := "00000000000000";
		
	signal	SM_A1_REF				:	std_logic_vector(13 downto 0) := "00000000000000";
	signal	SM_A2_REF				:	std_logic_vector(13 downto 0) := "00000000000000";
	signal	SM_A3_REF				:	std_logic_vector(13 downto 0) := "00000000000000";
	signal	SM_B1_REF				:	std_logic_vector(13 downto 0) := "00000000000000";
	signal	SM_B2_REF				:	std_logic_vector(13 downto 0) := "00000000000000";
	signal	SM_B3_REF				:	std_logic_vector(13 downto 0) := "00000000000000";

	signal	SM_A1_REF_reg			:	std_logic_vector(13 downto 0) := "00000000000000";
	signal	SM_A2_REF_reg			:	std_logic_vector(13 downto 0) := "00000000000000";
	signal	SM_A3_REF_reg			:	std_logic_vector(13 downto 0) := "00000000000000";
	signal	SM_B1_REF_reg			:	std_logic_vector(13 downto 0) := "00000000000000";
	signal	SM_B2_REF_reg			:	std_logic_vector(13 downto 0) := "00000000000000";
	signal	SM_B3_REF_reg			:	std_logic_vector(13 downto 0) := "00000000000000";

	signal 	SM_A1_GATING_reg		: 	std_logic := '0';
	signal 	SM_A2_GATING_reg		: 	std_logic := '0';
	signal 	SM_A3_GATING_reg		: 	std_logic := '0';
	signal 	SM_B1_GATING_reg		: 	std_logic := '0';
	signal 	SM_B2_GATING_reg		: 	std_logic := '0';
	signal 	SM_B3_GATING_reg		: 	std_logic := '0';
begin

	INIT_SET	: process(OP_CLK, EMIF_ADDR, EM1CS2n, EM1WEn)
	begin
		if OP_CLK'event and OP_CLK = '1' then
			if EMIF_ADDR = "000010101000" and EM1CS2n = '0' and EM1WEn = '0' then
					REF_MAX <= EMIF_DATA;
			end if;	
			if EMIF_ADDR = "000010101001" and EM1CS2n = '0' and EM1WEn = '0' then
					REF_MIN <= EMIF_DATA;
			end if;	
		end if;
	end process;
	
	REFERENCE_buffer : process(OP_CLK, EMIF_ADDR, EM1CS2n, EM1WEn)
	begin
		if OP_CLK'event and OP_CLK = '1' then	
			
			if EMIF_ADDR = "000010101010" and EM1CS2n = '0' and EM1WEn = '0' then
					SM_A1_REF_reg <= EMIF_DATA;
			end if;	
			if EMIF_ADDR = "000010101011" and EM1CS2n = '0' and EM1WEn = '0' then
					SM_A2_REF_reg <= EMIF_DATA;
			end if;	
			if EMIF_ADDR = "000010101100" and EM1CS2n = '0' and EM1WEn = '0' then
					SM_A3_REF_reg <= EMIF_DATA;
			end if;	
			if EMIF_ADDR = "000010101101" and EM1CS2n = '0' and EM1WEn = '0' then
					SM_B1_REF_reg <= EMIF_DATA;
			end if;	
			if EMIF_ADDR = "000010101110" and EM1CS2n = '0' and EM1WEn = '0' then
					SM_B2_REF_reg <= EMIF_DATA;
			end if;	
			if EMIF_ADDR = "000010101111" and EM1CS2n = '0' and EM1WEn = '0' then
					SM_B3_REF_reg <= EMIF_DATA;
			end if;	
		end if;
	end process;
		
	SM_A1_GATING_OPERATION : process(OP_CLK, EMIF_ADDR, EM1CS2n, EM1WEn, SM_A1_CARRIER, SM_A1_SEQ, SM_A1_REF, SM_A1_GATING_reg, SM_A1_REF_reg)
	begin
		
		SM_A1_GATING <= SM_A1_GATING_reg;
		if EMIF_ADDR = "000010100000" and EM1CS2n = '0' and EM1WEn = '0' then
			SM_A1_REF <= SM_A1_REF_reg;
		elsif OP_CLK'event and OP_CLK = '1' then
				
				if SM_A1_REF >= REF_MAX then
					SM_A1_GATING_reg <= '1';
				elsif SM_A1_REF <= REF_MIN then
					SM_A1_GATING_reg <= '0';
				elsif SM_A1_REF > SM_A1_CARRIER then
					if SM_A1_SEQ = '1' then
						SM_A1_GATING_reg <= SM_A1_SEQ;
					else
						SM_A1_GATING_reg <= not(SM_A1_SEQ);
					end if;
				elsif SM_A1_REF <= SM_A1_CARRIER then
					if SM_A1_SEQ = '1' then
						SM_A1_GATING_reg <= not(SM_A1_SEQ);
					else
						SM_A1_GATING_reg <= SM_A1_SEQ;
					end if;
				end if;			
		end if;
	end process;
	
	SM_A2_GATING_OPERATION : process(OP_CLK, EMIF_ADDR, EM1CS2n, EM1WEn, SM_A2_CARRIER, SM_A2_SEQ, SM_A2_REF, SM_A2_GATING_reg, SM_A2_REF_reg)
	begin
		
		SM_A2_GATING <= SM_A2_GATING_reg;
		if EMIF_ADDR = "000010100000" and EM1CS2n = '0' and EM1WEn = '0' then
			SM_A2_REF <= SM_A2_REF_reg;
		elsif OP_CLK'event and OP_CLK = '1' then
				
				if SM_A2_REF >= REF_MAX then
					SM_A2_GATING_reg <= '1';
				elsif SM_A2_REF <= REF_MIN then
					SM_A2_GATING_reg <= '0';
				elsif SM_A2_REF > SM_A2_CARRIER then
					if SM_A2_SEQ = '1' then
						SM_A2_GATING_reg <= SM_A2_SEQ;
					else
						SM_A2_GATING_reg <= not(SM_A2_SEQ);
					end if;
				else
					if SM_A2_SEQ = '1' then
						SM_A2_GATING_reg <= not(SM_A2_SEQ);
					else
						SM_A2_GATING_reg <= SM_A2_SEQ;
					end if;
				end if;			
		end if;
	end process;
	
	SM_A3_GATING_OPERATION : process(OP_CLK, EMIF_ADDR, EM1CS2n, EM1WEn, SM_A3_CARRIER, SM_A3_SEQ, SM_A3_REF, SM_A3_GATING_reg, SM_A3_REF_reg)
	begin
		
		SM_A3_GATING <= SM_A3_GATING_reg;
		if EMIF_ADDR = "000010100000" and EM1CS2n = '0' and EM1WEn = '0' then
			SM_A3_REF <= SM_A3_REF_reg;
		elsif OP_CLK'event and OP_CLK = '1' then
				
				if SM_A3_REF >= REF_MAX then
					SM_A3_GATING_reg <= '1';
				elsif SM_A3_REF <= REF_MIN then
					SM_A3_GATING_reg <= '0';
				elsif SM_A3_REF > SM_A3_CARRIER then
					if SM_A3_SEQ = '1' then
						SM_A3_GATING_reg <= SM_A3_SEQ;
					else
						SM_A3_GATING_reg <= not(SM_A3_SEQ);
					end if;
				else
					if SM_A3_SEQ = '1' then
						SM_A3_GATING_reg <= not(SM_A3_SEQ);
					else
						SM_A3_GATING_reg <= SM_A3_SEQ;
					end if;
				end if;			
		end if;
	end process;

	SM_B1_GATING_OPERATION : process(OP_CLK, EMIF_ADDR, EM1CS2n, EM1WEn, SM_B1_CARRIER, SM_B1_SEQ, SM_B1_REF, SM_B1_GATING_reg, SM_B1_REF_reg)
	begin
		
		SM_B1_GATING <= SM_B1_GATING_reg;
			
		if EMIF_ADDR = "000010100000" and EM1CS2n = '0' and EM1WEn = '0' then
				SM_B1_REF <= SM_B1_REF_reg;
		elsif OP_CLK'event and OP_CLK = '1' then
				
				if SM_B1_REF >= REF_MAX then
					SM_B1_GATING_reg <= '1';
				elsif SM_B1_REF <= REF_MIN then
					SM_B1_GATING_reg <= '0';
				elsif SM_B1_REF > SM_B1_CARRIER then
					if SM_B1_SEQ = '1' then
						SM_B1_GATING_reg <= SM_B1_SEQ;
					else
						SM_B1_GATING_reg <= not(SM_B1_SEQ);
					end if;
				else
					if SM_B1_SEQ = '1' then
						SM_B1_GATING_reg <= not(SM_B1_SEQ);
					else
						SM_B1_GATING_reg <= SM_B1_SEQ;
					end if;
				end if;			
		end if;
	end process;
	
	SM_B2_GATING_OPERATION : process(OP_CLK, EMIF_ADDR, EM1CS2n, EM1WEn, SM_B2_CARRIER, SM_B5_SEQ, SM_B2_REF, SM_B2_GATING_reg, SM_B2_REF_reg)
	begin
		
		SM_B2_GATING <= SM_B2_GATING_reg;
			
		if EMIF_ADDR = "000010100000" and EM1CS2n = '0' and EM1WEn = '0' then
				SM_B2_REF <= SM_B2_REF_reg;
		elsif OP_CLK'event and OP_CLK = '1' then
				
				if SM_B2_REF >= REF_MAX then
					SM_B2_GATING_reg <= '1';
				elsif SM_B2_REF <= REF_MIN then
					SM_B2_GATING_reg <= '0';
				elsif SM_B2_REF > SM_B2_CARRIER then
					if SM_B5_SEQ = '1' then
						SM_B2_GATING_reg <= SM_B5_SEQ;
					else
						SM_B2_GATING_reg <= not(SM_B5_SEQ);
					end if;
				else
					if SM_B5_SEQ = '1' then
						SM_B2_GATING_reg <= not(SM_B5_SEQ);
					else
						SM_B2_GATING_reg <= SM_B5_SEQ;
					end if;
				end if;			
		end if;
	end process;
	
	SM_B3_GATING_OPERATION : process(OP_CLK, EMIF_ADDR, EM1CS2n, EM1WEn, SM_B3_CARRIER, SM_B6_SEQ, SM_B3_REF, SM_B3_GATING_reg, SM_B3_REF_reg)
	begin
		
		SM_B3_GATING <= SM_B3_GATING_reg;
			
		if EMIF_ADDR = "000010100000" and EM1CS2n = '0' and EM1WEn = '0' then
				SM_B3_REF <= SM_B3_REF_reg;
		elsif OP_CLK'event and OP_CLK = '1' then
				
				if SM_B3_REF >= REF_MAX then
					SM_B3_GATING_reg <= '1';
				elsif SM_B3_REF <= REF_MIN then
					SM_B3_GATING_reg <= '0';
				elsif SM_B3_REF > SM_B3_CARRIER then
					if SM_B6_SEQ = '1' then
						SM_B3_GATING_reg <= SM_B6_SEQ;
					else
						SM_B3_GATING_reg <= not(SM_B6_SEQ);
					end if;
				else
					if SM_B6_SEQ = '1' then
						SM_B3_GATING_reg <= not(SM_B6_SEQ);
					else
						SM_B3_GATING_reg <= SM_B6_SEQ;
					end if;
				end if;			
		end if;
	end process;
	
	Period_Check : process(OP_CLK, EMIF_ADDR, EM1CS2n, EM1WEn)
	begin
		
		if OP_CLK'event and OP_CLK = '1' then
			if EMIF_ADDR = "000010100000" and EM1CS2n = '0' and EM1WEn = '0' then
					Check_point <= '1';
			else
					Check_point <= '0';
			end if;
		end if;
	end process;
		
end arch;