library ieee;
use ieee.std_logic_1164.all;

entity Internal_Data_16Mux is
	port(
			nCS					:	in std_logic_vector(15 downto 0)		:= (others => '1');					-- Chip Select
			IntMdlData0_In		:  in std_logic_vector(15 downto 0)		:= (others => '0');					-- Internal Module 0 Data
			IntMdlData1_In		:  in std_logic_vector(15 downto 0)		:= (others => '0');					-- Internal Module 1 Data
			IntMdlData2_In		:  in std_logic_vector(15 downto 0)		:= (others => '0');					-- Internal Module 2 Data
			IntMdlData3_In		:  in std_logic_vector(15 downto 0)		:= (others => '0');					-- Internal Module 3 Data
			IntMdlData4_In		:  in std_logic_vector(15 downto 0)		:= (others => '0');					-- Internal Module 4 Data
			IntMdlData5_In		:  in std_logic_vector(15 downto 0)		:= (others => '0');					-- Internal Module 5 Data
			IntMdlData6_In		:  in std_logic_vector(15 downto 0)		:= (others => '0');					-- Internal Module 6 Data
			IntMdlData7_In		:  in std_logic_vector(15 downto 0)		:= (others => '0');					-- Internal Module 7 Data
			IntMdlData8_In		:  in std_logic_vector(15 downto 0)		:= (others => '0');					-- Internal Module 8 Data
			IntMdlData9_In		:  in std_logic_vector(15 downto 0)		:= (others => '0');					-- Internal Module 9 Data
			IntMdlData10_In	:  in std_logic_vector(15 downto 0)		:= (others => '0');					-- Internal Module 10 Data
			IntMdlData11_In	:  in std_logic_vector(15 downto 0)		:= (others => '0');					-- Internal Module 11 Data
			IntMdlData12_In	:  in std_logic_vector(15 downto 0)		:= (others => '0');					-- Internal Module 12 Data
			IntMdlData13_In	:  in std_logic_vector(15 downto 0)		:= (others => '0');					-- Internal Module 13 Data
			IntMdlData14_In	:  in std_logic_vector(15 downto 0)		:= (others => '0');					-- Internal Module 14 Data
			IntMdlData15_In	:  in std_logic_vector(15 downto 0)		:= (others => '0');					-- Internal Module 15 Data
			
			IntMdlData		:	out std_logic_vector(15 downto 0)	:= (others => '0')						-- Output Internal Module Data
	);

end Internal_Data_16Mux;

architecture arch of Internal_Data_16Mux is

begin

		with not(nCS) select IntMdlData <=	IntMdlData0_In			when x"0001",
														IntMdlData1_In			when x"0002",
														IntMdlData2_In			when x"0004",
														IntMdlData3_In			when x"0008",
														IntMdlData4_In			when x"0010",
														IntMdlData5_In			when x"0020",
														IntMdlData6_In			when x"0040",
														IntMdlData7_In			when x"0080",
														IntMdlData8_In			when x"0100",
														IntMdlData9_In			when x"0200",
														IntMdlData10_In		when x"0400",
														IntMdlData11_In		when x"0800",
														IntMdlData12_In		when x"1000",
														IntMdlData13_In		when x"2000",
														IntMdlData14_In		when x"4000",
														IntMdlData15_In		when x"8000",
														(others => '0')		when others;

end arch;
	