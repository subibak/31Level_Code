library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity  cs_sig_generator is
	port (
			clk						: in std_logic;
			pwm_en_cs_n				: in std_logic;
					
			pwm_en_cs				: out std_logic	
			);
			
end cs_sig_generator;

architecture act of cs_sig_generator is
signal en_cs_pulse : std_logic;
signal en_cnt : std_logic_vector (2 downto 0);
begin

-- 클럭이 들어 올때마다 pwm_en_cs_n(Active low) 값을 체크하여 0이 되는 순간 출력값을 카운터를 동작하게 하고
-- 출력 1로 하여 Active low 동작하게 함 
	process(clk, pwm_en_cs_n)
	begin
		if (clk'event and clk = '0') then
			if (pwm_en_cs_n = '1') then
				en_cnt <= "000";
				en_cs_pulse <= '0';
			else
				if (en_cnt = "000") then
					en_cs_pulse <= '1';
					en_cnt <= "001";
				elsif (en_cnt = "01") then
					en_cs_pulse <= '1';
					en_cnt <= "010";
				else
					en_cs_pulse <= '0';
					en_cnt <= "011";
				end if;
			end if;
		end if;
	end process;
	pwm_en_cs <= en_cs_pulse;
end act;
