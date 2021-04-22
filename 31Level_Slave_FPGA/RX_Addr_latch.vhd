library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
--use ieee.std_logic_arith.all;
use ieee.numeric_std.all;


entity RX_Addr_latch is
	port(
		Data_bus				: in std_logic_vector(15 downto 0);
		
		clk					: in std_logic;
		RX_Addr				: in std_logic;
		XWE0					: in std_logic;
	
		ADDR_out 			: out std_logic_vector(7 downto 0) := (others => '0');
		Memory_out_reg		: out std_logic
		
		);
end RX_Addr_latch;


architecture arch of RX_Addr_latch is

	signal Output_start_reg	: std_logic_vector(1 downto 0) := "11";
	
begin
	process(clk, Output_start_reg)
	begin
		if (clk'event and clk = '1') then
			Output_start_reg <= Output_start_reg(0) & RX_Addr;
		end if;
	end process;
	
	
	process(clk, Output_start_reg, RX_Addr, XWE0)
	begin
		if (RX_Addr ='0') then
	--		if (XWE0'event and XWE0 = '1') then 
				ADDR_out <= Data_bus(7 downto 0);
	--		end if;
		end if;
		
		if (clk'event and clk = '1') then
			if Output_start_reg = "00" then
				Memory_out_reg <= '1';
			else
				Memory_out_reg <= '0';
			end if;
		end if;
	end process;
	
end arch;