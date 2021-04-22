library ieee;
use ieee.std_logic_1164.all;

entity GPIOx is
	generic(
		Dir_Reg_Init	: std_logic_vector(15 downto 0) := (others => '0');			-- GPIO Direction Initialization (0 : Input, 1: Output)
		Out_Reg_Init	: std_logic_vector(15 downto 0) := (others => '0')				-- GPIO Output Register Initialization
	);
	
	port(
			Data		:	in std_logic_vector(15 downto 0)		:= (others => '0');		-- Data
			Addr		: 	in std_logic_vector(1 downto 0)		:= (others => '0');		-- Address
			nCS		:	in std_logic 								:= '1';						-- Chip Select
			nEMxWE	:	in std_logic								:= '1';						-- EMIF Write Enable
			
			Int_Data	:	out std_logic_vector(15 downto 0);									-- Internal Data Bus
			GPIO		:	inout std_logic_vector(15 downto 0)									-- GPIO In-Out
	);
end GPIOx;

architecture arch of GPIOx is
	signal nWE		:	std_logic							:= '1';								-- GPIOx Write Enable
	signal Dir_Reg	:	std_logic_vector(15 downto 0) := Dir_Reg_Init;					-- GPIO Direction Register
	signal IN_Reg	:	std_logic_vector(15 downto 0); 										-- GPIO Input Register
	signal Out_Reg	:	std_logic_vector(15 downto 0)	:= Out_Reg_Init;					-- GPIO Out Register
begin
	
	-- GPIOx nWE Generator
	nWE <= nCS or nEMxWE;																			-- GPIOx nWE

	--	GPIOx Setting (Direction, Data, Set, Clear Mode selection)
	GPIOx_Setting : process(nWE, Addr)															
	begin
		if falling_edge(nWE) then
			case Addr is
				when "00" 	=> Dir_Reg 		<= Data;												-- GPIOx Direction Set(0x0) 
				when "01" 	=> Out_Reg		<=	Dir_Reg and Data;								-- GPIOx Data			 (0x1)
				when "10" 	=> Out_Reg		<= Out_Reg or (Dir_Reg and Data);			-- GPIOx Data Set		 (0x2)
				when "11" 	=> Out_Reg		<= Out_Reg and (Dir_Reg nand Data);			-- GPIOx Data Clear	 (0x3)
				when others	=> null;
			end case;
		end if;
	end process;
	
	-- GPIO In data Selection
	with Addr select Int_Data <= 	Dir_Reg 				when "00", 							-- GPIO Direction Data
											In_Reg 				when "01",							-- GPIO Current State
											(others => '0')	when others;						-- In case of Set, Clear data request, send 0
				
			
	-- GPIO In-Out
	GPIO(0) 	<= Out_Reg(0)  when Dir_Reg(0)  = '1' else 'Z';								-- GPIO 0 
	GPIO(1) 	<= Out_Reg(1)  when Dir_Reg(1)  = '1' else 'Z';								-- GPIO 1
	GPIO(2) 	<= Out_Reg(2)  when Dir_Reg(2)  = '1' else 'Z';								-- GPIO 2
	GPIO(3) 	<= Out_Reg(3)  when Dir_Reg(3)  = '1' else 'Z';								-- GPIO 3
	GPIO(4) 	<= Out_Reg(4)  when Dir_Reg(4)  = '1' else 'Z';								-- GPIO 4
	GPIO(5) 	<= Out_Reg(5)  when Dir_Reg(5)  = '1' else 'Z';								-- GPIO 5
	GPIO(6)	<= Out_Reg(6)  when Dir_Reg(6)  = '1' else 'Z';								-- GPIO 6
	GPIO(7)	<= Out_Reg(7)  when Dir_Reg(7)  = '1' else 'Z';								-- GPIO 7
	GPIO(8)	<= Out_Reg(8)  when Dir_Reg(8)  = '1' else 'Z';								-- GPIO 8
	GPIO(9)	<= Out_Reg(9)  when Dir_Reg(9)  = '1' else 'Z';								-- GPIO 9
	GPIO(10)	<= Out_Reg(10) when Dir_Reg(10) = '1' else 'Z';								-- GPIO 10
	GPIO(11) <= Out_Reg(11) when Dir_Reg(11) = '1' else 'Z';								-- GPIO 11
	GPIO(12) <= Out_Reg(12) when Dir_Reg(12) = '1' else 'Z';								-- GPIO 12
	GPIO(13) <= Out_Reg(13) when Dir_Reg(13) = '1' else 'Z';								-- GPIO 13
	GPIO(14) <= Out_Reg(14) when Dir_Reg(14) = '1' else 'Z';								-- GPIO 14
	GPIO(15) <= Out_Reg(15) when Dir_Reg(15) = '1' else 'Z';								-- GPIO 15
	
	In_Reg <= GPIO;																					-- GPIO Input Register
	
end arch;