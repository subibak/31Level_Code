library ieee;
use ieee.std_logic_1164.all;

entity EMIFx_Interface is
	generic(
			PC_MAX		:	integer range 0 to 96						:= 1									-- Prgram Counter MAX
	);

	port(
			--EMIFx Singal(from DSP)
			EMxCLK			: 	in std_logic								:= '0';								-- EMIFx Clock
			EMxADDR			: 	in std_logic_vector(11 downto 0)		:= (others => '0');				-- EMIFx Address
			nEMxOE			:	in std_logic								:= '1';								-- EMIFx nOE singal
			nEMxCS2			:	in std_logic								:= '1';								-- EMIFx Chip Select2
			nEMxCS3			: 	in std_logic								:= '1';								-- EMIFx Chip Select3
			nEMxCS4			:	in std_logic								:= '1';								-- EMIFx Chip Select4			
			EMxDATA			:	inout std_logic_vector(15 downto 0)	:= (others => '0');				-- EMIFx Data
			-- Internal Module singal
			IntMdlData		:	in std_logic_vector(15 downto 0)		:= (others => '0');				-- Internal Module Data
			IntMdlAddr		:	out Std_logic_vector(15 downto 0)	:= (others => '0');				-- Internal Module Address
			nIntMdlCS		:	out std_logic_vector(15 downto 0)	:= (others => '1')				-- Internal Module Chip Select Signal		
	);

end EMIFx_Interface;

architecture arch of EMIFx_Interface is

	signal PC_EN			: std_logic								:= '0';										-- Program Counter Enable
	signal PC				: integer range 0 to 96				:= 0;											-- Program Counter 
	signal EMxAddr_Raw	: std_logic_vector(23 downto 0) 	:= (others => '0');						-- Reconstructed EMIFx Address RAW
	signal EMXAddr_Lth	: std_logic_vector(23 downto 0) 	:= (others => '0');						-- Latched Address 
	
	signal nIntMdlCS_Raw	: std_logic_vector(15 downto 0)	:= (others => '1');						-- Module Chip Select Signal RAW
begin

	-- Program Counter Enable
	PC_EN <= not(nEMxCS2 and nEMxCS3 and nEMxCS4);
	
	-- EMIFx Address Generator(Reconstructing the Address from TMS320F28377D EMIF1 nCS2, nCS3 and nCS4)
	-- nCS2 : 0x0010 0000 - 002F FFFF
	-- nCS3 : 0x0030 0000 - 0037 FFFF
	-- nCS4 : 0x0038 0000 - 003D FFFF
	EMxAddr_Raw(23 downto 22) 	<= (others => '0');
	EMxAddr_Raw(21) 				<= nEMxCS3 nand nEMxCS4;
	EMxAddr_Raw(20) 				<= PC_EN;
	EMxAddr_Raw(19)				<= not(nEMxCS4);
	EMxAddr_Raw(18 downto 12)  <= (others => '0');
	EMxAddr_Raw(11 downto 0)	<= EMxADDR;
	
	-- Program Counter and Latch Address
	Program_Counter : Process (PC_EN, EMxCLK)
	begin
		if PC_EN = '0' then
			EMxAddr_Lth	<= x"000000";
			PC				<= 0;
		elsif falling_edge(EMxCLK) then
			if PC = PC_MAX then
				EMxAddr_Lth <= EMxAddr_Raw;
			end if;
			PC <= PC + 1;
		end if;
	end process;
	
	-- Internal Module Chip Select Signal Generator(EMIFx Address Decoder)
	-- Group-x GPIO Selection Gnerator	
	nIntMdlCS_Raw(0)		<= '0' when EMxAddr_Lth(23 downto 2) & "00" = x"100000" else '1';			-- GPIO_A Selection Signal : 0x0010 0000 - 0x0010 0003
	nIntMdlCS_Raw(1)		<= '0' when EMxAddr_Lth(23 downto 2) & "00" = x"100004" else '1';			-- GPIO_B Selection Signal : 0x0010 0004 - 0x0010 0007	
	nIntMdlCS_Raw(2)		<= '0' when EMxAddr_Lth(23 downto 2) & "00" = x"100008" else '1';			-- GPIO_C Selection Signal : 0x0010 0008 - 0x0010 000B
	nIntMdlCS_Raw(3)		<= '0' when EMxAddr_Lth(23 downto 2) & "00" = x"10000C" else '1';			-- GPIO_D Selection Signal : 0x0010 000C - 0x0010 000F	
	nIntMdlCS_Raw(4)		<= '0' when EMxAddr_Lth(23 downto 2) & "00" = x"100010" else '1';			-- GPIO_E Selection Signal : 0x0010 0010 - 0x0010 0013
	nIntMdlCS_Raw(5)		<= '0' when EMxAddr_Lth(23 downto 2) & "00" = x"100014" else '1';			-- GPIO_F Selection Signal : 0x0010 0014 - 0x0010 0017
	nIntMdlCS_Raw(6)		<= '0' when EMxAddr_Lth(23 downto 2) & "00" = x"100018" else '1';			-- GPIO_G Selection Signal : 0x0010 0018 - 0x0010 001B
	nIntMdlCS_Raw(7)		<= '0' when EMxAddr_Lth(23 downto 2) & "00" = x"10001C" else '1';			-- GPIO_H Selection Signal : 0x0010 001C - 0x0010 001F
	nIntMdlCS_Raw(8)		<= '0' ;
	nIntMdlCS_Raw(9)		<= '0' ;
	nIntMdlCS_Raw(10)		<= '0' ;
	nIntMdlCS_Raw(11)		<= '0' ;
	nIntMdlCS_Raw(12)		<= '0' ;
	nIntMdlCS_Raw(13)		<= '0' ;
	nIntMdlCS_Raw(14)		<= '0' ;
	nIntMdlCS_Raw(15)		<= '0' ;
			
	nIntMdlCS 				<= nIntMdlCS_Raw;
	
	-- Internal Module Address Generator
	IntMdlAddr <= EMxAddr_Lth(15 downto 0);

	-- Internal Module Data Select
	EMxDATA <= IntMdlData when nEMxOE = '0' else (others => 'Z');
		
end arch; 