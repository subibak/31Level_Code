-- EN 신호가 발생시에는 레퍼런스값을 다음 블럭으로 래치하고
-- STATE_EN 신호가 발생시에는 레퍼런스 값의 상태(MAX,0 그리고 0<x<MAX)를 다음 블럭으로 래치 함

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity Gate_latch is
	
	port(
			Data_in		:		in std_logic_vector(15 downto 0);
			EN				:     in std_logic;
			STATE_EN		:		in std_logic;
			XWE0			:     in std_logic;
						
			Data_out		:		out std_logic_vector(15 downto 0);
			state_out	:		out std_logic_vector(1 downto 0)
			);

end Gate_latch;


architecture arch of Gate_latch is

begin

	
	process(EN, data_in,XWE0)
	begin
		if(EN = '0') then
			if(XWE0'event and XWE0='1') then 
				Data_out <= Data_in;
			end if;
		end if;
		
	end process;
	
	process(STATE_EN, data_in,XWE0)
	begin
		if(STATE_EN = '0') then
			if(XWE0'event and XWE0='1') then 
				state_out <= Data_in(1 downto 0);
			end if;
		end if;
		
	end process;

end arch;
