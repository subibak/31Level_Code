library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

entity RS422_RX_BUFFER is
	port( 
			OP_CLK						: in std_logic;
			ACCESS_ADDR					: in std_logic_vector(11 downto 0);
			EM1OEn						: in std_logic;
			EM1CS2n						: in std_logic;
			LOAD_EN						: in std_logic;
			DATA_IN						: in std_logic_vector(303 downto 0);
				
			DATA_OUT						: out std_logic_vector(15 downto 0)
			
	);
end RS422_RX_BUFFER;

architecture RX_BUFFER of RS422_RX_BUFFER is
	signal Data_all					: std_logic_vector(303 downto 0);
	signal Flag_Loading				: std_logic;
	
	type DATA_MEM is array (0 to 19) of std_logic_vector(15 downto 0);
	signal Data_o			 			: DATA_MEM;
	
begin
	
	DATA_ACCESS : process(LOAD_EN,OP_CLK, EM1OEn, EM1CS2n, ACCESS_ADDR, Data_all)
	begin
		Flag_Loading <= '0';
		if LOAD_EN = '0' then
			Flag_Loading <= '1';
			Data_all <= DATA_IN;
			Data_o(0) <= "00000000" & Data_all(7 downto 0);
			Data_o(1) <= "00000000" & Data_all(15 downto 8);
			Data_o(2) <= Data_all(31 downto 16);
			Data_o(3) <= Data_all(47 downto 32);
			Data_o(4) <= Data_all(63 downto 48);
			Data_o(5) <= Data_all(79 downto 64);
			Data_o(6) <= Data_all(95 downto 80);
			Data_o(7) <= Data_all(111 downto 96);
			Data_o(8) <= Data_all(127 downto 112);
			Data_o(9) <= Data_all(143 downto 128);
			Data_o(10) <= Data_all(159 downto 144);
			Data_o(11) <= Data_all(175 downto 160);
			Data_o(12) <= Data_all(191 downto 176);
			Data_o(13) <= Data_all(207 downto 192);
			Data_o(14) <= Data_all(223 downto 208);
			Data_o(15) <= Data_all(239 downto 224);
			Data_o(16) <= Data_all(255 downto 240);
			Data_o(17) <= Data_all(271 downto 256);
			Data_o(18) <= Data_all(287 downto 272);
			Data_o(19) <= Data_all(303 downto 288);
			Flag_Loading <= '0';

		elsif OP_CLK'event and OP_CLK = '1' then
			if EM1OEn = '0' and EM1CS2n = '0' then
				case ACCESS_ADDR is
					when "000000100000" =>
						DATA_OUT <= Data_o(0);
					when "000000100001" =>
						DATA_OUT <= Data_o(1);
					when "000000100010" =>
						DATA_OUT <= Data_o(2);
					when "000000100011" =>
						DATA_OUT <= Data_o(3);
					when "000000100100" =>
						DATA_OUT <= Data_o(4);
					when "000000100101" =>
						DATA_OUT <= Data_o(5);
					when "000000100110" =>
						DATA_OUT <= Data_o(6);
					when "000000100111" =>
						DATA_OUT <= Data_o(7);
					when "000000101000" =>
						DATA_OUT <= Data_o(8);
					when "000000101001" =>
						DATA_OUT <= Data_o(9);
					when "000000101010" =>
						DATA_OUT <= Data_o(10);
					when "000000101011" =>
						DATA_OUT <= Data_o(11);
					when "000000101100" =>
						DATA_OUT <= Data_o(12);
					when "000000101101" =>
						DATA_OUT <= Data_o(13);
					when "000000101110" =>
						DATA_OUT <= Data_o(14);
					when "000000101111" =>
						DATA_OUT <= Data_o(15);
					when "000000110000" =>
						DATA_OUT <= Data_o(16);				
					when "000000110001" =>
						DATA_OUT <= Data_o(17);		
					when "000000110010" =>
						DATA_OUT <= Data_o(18);	
					when "000000110011" =>
						DATA_OUT <= Data_o(19);	
					when others => 
						DATA_OUT <= (others => 'Z');
				end case;
					Flag_Loading <= '0';	
			end if;
		end if;
	end process;
	
end RX_BUFFER;

	