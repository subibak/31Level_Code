library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity DAC8803_8CH is

	port(
			CLK			:  	in std_logic;
			DAC_CS_IN	:		in std_logic;
			DAC_LD_IN_1	:		in std_logic;
			DAC_LD_IN_2	:		in std_logic;
			DAC_DATA 	:		in std_logic_vector(15 downto 0);
			
			DAC_LD_1	: 		out std_logic;
			DAC_LD_2	: 		out std_logic;
			DAC_CS	:		out std_logic;
			DAC_CLK	:		out std_logic;
			DAC_SDI	:		out std_logic
		);

end DAC8803_8CH;

architecture arch of DAC8803_8CH is
	
	signal dac_reg			:		std_logic_vector(1 downto 0);
	signal dac_reg_1		:		std_logic_vector(1 downto 0);
	signal dac_reg_2		:		std_logic_vector(1 downto 0);
	signal dac_reg_3		:		std_logic_vector(1 downto 0);
	signal dac_reg_4		:		std_logic_vector(1 downto 0);
	signal dac_count		:		std_logic_vector(15 downto 0);
	signal dac_count_1	:		std_logic_vector(15 downto 0);
	signal dac_count_2	:		std_logic_vector(15 downto 0);
	signal dac_count_3	:		std_logic_vector(15 downto 0);
	signal dac_count_4	:		std_logic_vector(15 downto 0);
	signal dac_csn			: 		std_logic;
	signal dac_ldn			: 		std_logic;
	signal dac_ldn_1		: 		std_logic;
	signal dac_ldn_2		: 		std_logic;
	signal clk_temp		: 		std_logic;
	signal dac_sdi_temp	: 		std_logic;

begin	

	CS_LOAD_SIGNAL : process(CLK)
	begin
		if CLK'event and CLK = '1' then
				dac_reg <= dac_reg(0) & DAC_CS_IN;
				dac_reg_1 <= dac_reg_1(0) & DAC_LD_IN_1;
				dac_reg_2 <= dac_reg_2(0) & DAC_LD_IN_2;
		end if;
	end process;
	
	COUNT_STATE : process(CLK, dac_reg_1, dac_reg_2)
	begin	
		if CLK'event and CLK = '1' then
			if(dac_reg = "10") then
				dac_count <= ( others => '0');
			else 
				dac_count <= 1 + dac_count;
			end if;
			
			if(dac_reg_1 = "10") then
				dac_count_1 <= ( others => '0');
			else 
				dac_count_1 <= 1 + dac_count_1;
			end if;
			
			if(dac_reg_2 = "10") then
				dac_count_2 <= ( others => '0');
			else 
				dac_count_2 <= 1 + dac_count_2;
			end if;
		
		end if;
	end process;
	
	CS_LOAD_SINGAL_STATE : process(CLK, dac_count, dac_count_1, dac_count_2)
	begin	

		if CLK'event and CLK = '1' then
			if dac_count <= "1010" then 
				dac_csn <= '1';
			elsif dac_count > "1010" and dac_count <= "11001000" then
				dac_csn <= '0';
			else
				dac_csn <= '1';
			end if;

			if dac_count_1 <= "11010010" then 
				DAC_LD_1 <= '1';
			elsif dac_count_1 > "11010010" and dac_count_1 <= "11110000" then
				DAC_LD_1 <= '0';
			else 
				DAC_LD_1 <= '1';
			end if;
		
			if dac_count_2 <= "11010010" then 
				DAC_LD_2 <= '1';
			elsif dac_count_2 > "11010010" and dac_count_2 <= "11110000" then
				DAC_LD_2 <= '0';
			else 
				DAC_LD_2 <= '1';
			end if;
		end if;

	end process;

	SENDING : process(CLK, dac_count)
	begin
		if CLK'event and CLK = '1' then
			if dac_count <= "1111" then  --0.15 us    --count 5us each step 100MHz 
				clk_temp <= '0';
			elsif dac_count > "1111" and dac_count <= "10100" then  -- 0.20 us
				clk_temp <= '0';
				dac_sdi_temp <= DAC_DATA(15);
			elsif dac_count > "10100" and dac_count <= "11001" then  -- 0.25 us
				clk_temp <= '1'; 
			elsif dac_count > "11001" and dac_count <= "11110" then  -- 0.30 us
				clk_temp <= '0';
				dac_sdi_temp <= DAC_DATA(14);
			elsif dac_count > "11110" and dac_count <= "100011" then -- 0.35 us				
				clk_temp <= '1';
			elsif dac_count > "100011" and dac_count <="101000"then -- 0.40 us
				clk_temp <= '0';
				dac_sdi_temp <= DAC_DATA(13);													
			elsif dac_count > "101000" and dac_count <="101101" then -- 0.45 us
				clk_temp <= '1';
			elsif dac_count > "101101" and dac_count <= "110010"then -- 0.50 us
				clk_temp <= '0';
				dac_sdi_temp <= DAC_DATA(12);                                        
			elsif dac_count > "110010" and dac_count <= "110111"then -- 0.55 us
				clk_temp <= '1';
			elsif dac_count > "110111" and dac_count <= "111100"then -- 0.60 us
				clk_temp <= '0';
				dac_sdi_temp <= DAC_DATA(11);
			elsif dac_count > "111100" and dac_count <= "1000001"then -- 0.65 us
				clk_temp <= '1';
			elsif dac_count > "1000001" and dac_count <= "1000110"then -- 0.70 us
				clk_temp <= '0';
				dac_sdi_temp <= DAC_DATA(10);
			elsif dac_count > "1000110" and dac_count <= "1001011"then -- 0.75 us
				clk_temp <= '1';
			elsif dac_count > "1001011" and dac_count <="1010000"then 	-- 0.80 us
				clk_temp <= '0';
				dac_sdi_temp <= DAC_DATA(9);													
			elsif dac_count > "1010000" and dac_count <="1010101"then -- 0.85 us
				clk_temp <= '1';
			elsif dac_count > "1010101" and dac_count <= "1011010"then -- 0.90 us
				clk_temp <= '0';
				dac_sdi_temp <= DAC_DATA(8);	                                        	
			elsif dac_count > "1011010" and dac_count <= "1011111"then -- 0.95 us
				clk_temp <= '1';
			elsif dac_count > "1011111" and dac_count <= "1100100"then -- 1.00 us
				clk_temp <= '0';
				dac_sdi_temp <= DAC_DATA(7);
			elsif dac_count > "1100100" and dac_count <= "1101001"then -- 1.05 us
				clk_temp <= '1';
			elsif dac_count > "1101001" and dac_count <= "1101110"then -- 1.10 us
				clk_temp <= '0';
				dac_sdi_temp <= DAC_DATA(6);
			elsif dac_count > "1101110" and dac_count <= "1110011"then 	-- 1.15 us
				clk_temp <= '1';
			elsif dac_count > "1110011" and dac_count <="1111000"then	-- 1.20 us
				clk_temp <= '0';
				dac_sdi_temp <= DAC_DATA(5);													
			elsif dac_count > "1111000" and dac_count <="1111101"then 	-- 1.25 us
				clk_temp <= '1';
			elsif dac_count > "1111101" and dac_count <= "10000010"then 	-- 1.30 us
				clk_temp <= '0';
				dac_sdi_temp <= DAC_DATA(4);	                                        	
			elsif dac_count > "10000010" and dac_count <= "10000111"then 	-- 1.35 us
				clk_temp <= '1';
			elsif dac_count > "10000111" and dac_count <= "10001100"then 	-- 1.40 us
				clk_temp <= '0';
				dac_sdi_temp <= DAC_DATA(3);
			elsif dac_count > "10001100" and dac_count <= "10010001"then 	-- 1.45 us
				clk_temp <= '1';
			elsif dac_count > "10010001" and dac_count <="10010110"then 	-- 1.50 us
				clk_temp <= '0';
				dac_sdi_temp <= DAC_DATA(2);													
			elsif dac_count > "10010110" and dac_count <="10011011"then 	-- 1.55 us
				clk_temp <= '1';
			elsif dac_count > "10011011" and dac_count <= "10100000"then 	--	1.60 us
				clk_temp <= '0';
				dac_sdi_temp <= DAC_DATA(1);	                                        	
			elsif dac_count > "10100000" and dac_count <= "10100101"then 	-- 1.65 us
				clk_temp <= '1';
			elsif dac_count > "10100101" and dac_count <= "10101010"then  -- 1.70 us
				clk_temp <= '0';
				dac_sdi_temp <= DAC_DATA(0);
			elsif dac_count > "10101010" and dac_count <= "10101111" then
				clk_temp <= '1';
			else
				clk_temp <= '0';		
				dac_sdi_temp  <= '1';		
			end if;
		end if;
			
		
	end process;
	
	DAC_CLK   <= clk_temp;
	DAC_SDI   <= dac_sdi_temp;
	DAC_CS 	 <= dac_csn;

end arch;