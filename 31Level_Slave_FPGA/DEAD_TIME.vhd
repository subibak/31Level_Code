library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity  DEAD_TIME is
	port (
				OP_CLK			: in std_logic;
				rst_n				: in std_logic;
				dead_t 			: out std_logic
			);
end DEAD_TIME;

architecture act of DEAD_TIME is

	signal q_buffer : std_logic_vector(7 downto 0);

begin 
	
	DEADTIME_OP : process (OP_CLK, rst_n )
	begin 
		if rst_n='0' then 
			q_buffer <= "00000000";
			dead_t   <= '0';
		elsif (OP_CLK'event and OP_CLK ='1') then 
			if (q_buffer = 60) THEN 
				dead_t <= '1' ;
			else 
				q_buffer <= q_buffer + '1';
				dead_t   <= '0';
			end if;
		end if;
	end process;
	
end act;
