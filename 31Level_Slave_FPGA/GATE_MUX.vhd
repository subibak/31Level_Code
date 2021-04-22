library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity  GATE_MUX is
	port ( 	gate_in : in std_logic;
			sig : in std_logic_vector(1 downto 0);
			gate_out : out std_logic);
end GATE_MUX;

architecture act of GATE_MUX is
begin
--레퍼런스 값이 MAX 값이면 출력값이 0이 되도록 설정
--레퍼런스 값이 0 값이면 출력값이 1이 되도록 설정
--레퍼런스 값이 0보다 크고 MAX 보다 작으면 PWM_COMPARATOR 값을 출력값이 되도록 설정
	process (sig,gate_in)
	begin
		case sig is
			when "00" => gate_out <= '1';
			when "01" => gate_out <= '0';
			when others => gate_out <= gate_in;
		end case;
	end process;
end act;
