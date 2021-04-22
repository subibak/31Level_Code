library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity GATING_ENABLE is
	port(
				OP_CLK	 				:	in std_logic;
				
				EMIF_ADDR				:	in std_logic_vector(11 downto 0);
				EM1CS2n					:	in std_logic;
				EM1WEn					: 	in std_logic;	
				EMIF_DATA				: 	in std_logic_vector(15 downto 0);		
		
				SMA1U						: 	in std_logic;
				SMA1L						: 	in std_logic;
				SMA2U						: 	in std_logic;
				SMA2L						: 	in std_logic;
				SMA3U						: 	in std_logic;
				SMA3L						: 	in std_logic;

				SMB1U						: 	in std_logic;
				SMB1L						: 	in std_logic;
				SMB2U						: 	in std_logic;
				SMB2L						: 	in std_logic;
				SMB3U						: 	in std_logic;
				SMB3L						: 	in std_logic;
				
				SM_A1U					: 	out std_logic;
				SM_A1L					: 	out std_logic;
				SM_A2U					: 	out std_logic;
				SM_A2L					: 	out std_logic;
				SM_A3U					: 	out std_logic;
				SM_A3L					: 	out std_logic;

				SM_B1U					: 	out std_logic;
				SM_B1L					: 	out std_logic;
				SM_B2U					: 	out std_logic;
				SM_B2L					: 	out std_logic;
				SM_B3U					: 	out std_logic;
				SM_B3L					: 	out std_logic;
				SW_EN						:  out std_logic_vector(5 downto 0)
	);
end GATING_ENABLE;

architecture arch of GATING_ENABLE is

	signal SM_reg	:	std_logic_vector(5 downto 0) := "000000";
	
begin

	SW_DECODER: process(OP_CLK, EMIF_ADDR, EM1CS2n, EM1WEn, EMIF_DATA)
	begin
		if OP_CLK'event and OP_CLK = '1' then
			if EMIF_ADDR = "000100000000" and EM1CS2n = '0' and EM1WEn = '0' then
				SM_reg <= EMIF_DATA(5 downto 0);
			end if;
		end if;
		SW_EN <= SM_reg;
	end process;

	SMA1_ENABLE : process(OP_CLK, SMA1U, SMA1L, SM_reg(0))
	begin
		if OP_CLK'event and OP_CLK = '1' then
			if SM_reg(0) = '1' then
					SM_A1U <= SMA1U;
					SM_A1L <= SMA1L;
			else
					SM_A1U <= '0';
					SM_A1L <= '0';
			end if;	
		end if;
	end process;
	
	SMA2_ENABLE : process(OP_CLK, SMA2U, SMA2L, SM_reg(1))
	begin
		if OP_CLK'event and OP_CLK = '1' then
			if SM_reg(1) = '1' then
					SM_A2U <= SMA2U;
					SM_A2L <= SMA2L;
			else
					SM_A2U <= '0';
					SM_A2L <= '0';
			end if;	
		end if;
	end process;
	
	SMA3_ENABLE : process(OP_CLK, SMA3U, SMA3L, SM_reg(2))
	begin
		if OP_CLK'event and OP_CLK = '1' then
			if SM_reg(2) = '1' then
					SM_A3U <= SMA3U;
					SM_A3L <= SMA3L;
			else
					SM_A3U <= '0';
					SM_A3L <= '0';
			end if;	
		end if;
	end process;
	
	SMB1_ENABLE : process(OP_CLK, SMB1U, SMB1L, SM_reg(3))
	begin
		if OP_CLK'event and OP_CLK = '1' then
			if SM_reg(3) = '1' then
					SM_B1U <= SMB1U;
					SM_B1L <= SMB1L;
			else
					SM_B1U <= '0';
					SM_B1L <= '0';
			end if;	
		end if;
	end process;
	
	SMB2_ENABLE : process(OP_CLK, SMB2U, SMB2L, SM_reg(4))
	begin
		if OP_CLK'event and OP_CLK = '1' then
			if SM_reg(4) = '1' then
					SM_B2U <= SMB2U;
					SM_B2L <= SMB2L;
			else
					SM_B2U <= '0';
					SM_B2L <= '0';
			end if;	
		end if;
	end process;
	
	SMB3_ENABLE : process(OP_CLK, SMB3U, SMB3L, SM_reg(5))
	begin
		if OP_CLK'event and OP_CLK = '1' then
			if SM_reg(5) = '1' then
					SM_B3U <= SMB3U;
					SM_B3L <= SMB3L;
			else
					SM_B3U <= '0';
					SM_B3L <= '0';
			end if;	
		end if;
	end process;
	
end arch; 

