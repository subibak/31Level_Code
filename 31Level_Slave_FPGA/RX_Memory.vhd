library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
--use ieee.std_logic_arith.all;
use ieee.numeric_std.all;

entity RX_Memory is
	port(
		Data_in 				: in std_logic_vector(23 downto 0);
		Addr_in				: in std_logic_vector(7 downto 0);
		
		Memory_in_reg		: in std_logic;
		Memory_out_reg		: in std_logic;
		
		clk					: in std_logic;
		
		Receive_en			: in std_logic;
		
		
		RX_load			: out std_logic;
		RX_DATA 			: out std_logic_vector(15 downto 0) := (others => '0')

		);
end RX_Memory;


architecture arch of RX_Memory is
	
	type ram is array (0 to 255) of std_logic_vector(15 downto 0);
	
	signal table : ram;
		
	signal Addr_buffer			: std_logic_vector(7 downto 0) := (others => '0');
	signal Data_buffer			: std_logic_vector(15 downto 0) := (others => '0');
	
	signal Busy_load				: std_logic;
	signal Busy_write				: std_logic;
	
	signal Memory_state			: std_logic_vector(2 downto 0) := (others => '0');
	signal Memory_state_next	: std_logic_vector(2 downto 0) := (others => '0');
	signal Memory_state_old		: std_logic_vector(2 downto 0) := (others => '0');
	
	signal Addr_index				: integer range 0 to 255 :=0;
	signal Addr_call				: integer range 0 to 255 :=0;
	
	signal count_out				: std_logic_vector(2 downto 0) := "000";
	
	signal Data_out_buffer		: std_logic_vector(15 downto 0) := (others => '0');
	signal RX_DATA1            : std_logic_vector(15 downto 0) := (others => '0');
begin

	process(clk, Memory_in_reg, Busy_load, Memory_out_reg, Memory_state, Memory_state_next, Memory_state_old, Busy_write)
	begin
			if Memory_in_reg = '1' then
				if Busy_load = '1' then
					Memory_state_old <= "001";
				else
					Memory_state_next <= "001";
					Busy_write <= '1';
				end if;
				
			elsif Memory_out_reg = '1' then
				if Busy_write = '1' then
					Memory_state_old <= "001";
					Memory_state_next <= "100";
				else
					Memory_state_next <= "100";
				end if;
				
				Busy_load <= '1';
						
			elsif (clk'event and clk = '1') then
				Memory_state <= Memory_state_next;

				case Memory_state is
					when "001" =>
						Addr_buffer <= Data_in(23 downto 16);
						Data_buffer <= Data_in(15 downto 0);
						Memory_state_next <= "010";
						Busy_write <= '1';

					when "010" =>
						Addr_index <= to_integer(unsigned(Addr_buffer));
						Memory_state_next <= "011";
						Busy_write <= '1';
					
					when "011" =>
						table(Addr_index) <= Data_buffer;
						Memory_state_next <= "000";
						Busy_write <= '0';	
						Memory_state_old <= (others => '0');
					
					when "000" =>
						Addr_buffer <= (others => '0');
						Data_buffer <= (others => '0');
						Addr_index <= 0;
						RX_load <= '1';
					
					when "100" =>
						--if (count_out > 6) then
							Addr_call <= to_integer(unsigned(Addr_in));
							Memory_state_next <= "101";
					--		count_out <= (others => '0');
					--	else
					--		count_out <= count_out + '1';
					--	end if;
						
					when "101" => 
						Data_out_buffer <= table(Addr_call);
						Memory_state_next <= Memory_state_old;
						Busy_load <= '0';
						RX_load <= Busy_load;
						
					when others =>
						Memory_state <= Memory_state_next;
						
				end case;

			end if;
		
	end process;
		
	process(Data_out_buffer, RX_DATA1, Receive_en)
	begin
		if Receive_en = '0' then
			RX_DATA1 <= Data_out_buffer;
		else
			RX_DATA1 <= (others => 'Z');
		end if;	
		RX_DATA <= RX_DATA1;
	end process;
	
end arch;	