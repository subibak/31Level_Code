library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity LED_FPGA is
port( 
		OP_CLK		:  in std_logic;
		LED_ENn 		:	in std_logic;
		LED_SEQ 		:	in std_logic_vector(3 downto 0);
		
		LED_OUT 		:	out std_logic_vector(3 downto 0)
		);
end LED_FPGA ;

architecture Sequence of LED_FPGA is
	signal LED_SEQ_reg : std_logic_vector(3 downto 0);
begin

		LED_STATE : Process(OP_CLK, LED_ENn, LED_SEQ, LED_SEQ_reg)
		begin
			if OP_CLK'event and OP_CLK = '1' then
				if LED_ENn = '0' then
					LED_SEQ_reg <= LED_SEQ;
				end if;
				
				case LED_SEQ_reg is
						when "0001" => LED_OUT <= "0001";
						when "0010" => LED_OUT <= "0011";
						when "0011" => LED_OUT <= "0111";
						when "0100" => LED_OUT <= "1111";
						when "0101" => LED_OUT <= "1110";
						when "0110" => LED_OUT <= "1100";
						when "0111" => LED_OUT <= "1000";
						when others => LED_OUT <= "0000";
				end case;
			end if;
		end process;

end Sequence;

