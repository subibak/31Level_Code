library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;

entity TX_RS_422 is
	port(
			
			OP_CLK		 : in std_logic;  							-- Operating Clock
			TX_CLK 		 : in std_logic;  							-- Transfer Clock
			TX_EN			 : in std_logic;
			DATA 			 : in std_logic_vector(27 downto 0); 
			
			TX_Busy		 : out std_logic := '1';
			TX_OUT		 : out std_logic := '1'
		);

end TX_RS_422;


architecture arch of TX_RS_422 is
	
	signal 	Tx_cs_reg					:		std_logic_vector(1 downto 0) := "11";
	signal 	Tx_count	 					:		unsigned(5 downto 0)  := (others => '0');
	signal	Tx_buffer_out 				:		std_logic := '1';
	signal   Tx_Parity					:  	std_logic := '0';
	shared variable DATA_buffer_in   :  	std_logic_vector(27 downto 0) := (others => '0');
	shared variable DATA_buffer_past	: 		std_logic_vector(27 downto 0) := (others => '0');
	shared variable DATA_buffer_shift: 		std_logic_vector(27 downto 0) := (others => '0');
	
	signal Tx_en_flag		 : std_logic := '0'; 
	signal Tx_on_flag_next: std_logic_vector(1 downto 0) := "00"; 
	signal Tx_on_flag 	 : std_logic_vector(1 downto 0) := "00"; 
begin
	
	process(OP_CLK, TX_EN,Tx_cs_reg)
	begin	
	
		if OP_CLK'event and OP_CLK = '1' then
				Tx_cs_reg <= Tx_cs_reg(0) & TX_EN;
		end if;
		
	end process;


	process(OP_CLK, DATA, TX_CLK, Tx_cs_reg)
	begin
		if OP_CLK'event and OP_CLK = '1' then
			if Tx_cs_reg = "10" then
				Tx_en_flag <= '1';
				DATA_buffer_in := DATA;

			else
				Tx_en_flag <= '0';
			end if;
		end if;
	end process;
	
	process(Tx_en_flag, Tx_on_flag, Tx_on_flag_next, TX_CLK, Tx_buffer_out)
	begin	
		if Tx_en_flag = '1' then
			Tx_on_flag_next <= "01";
			Tx_buffer_out <= '1';	
				
		elsif TX_CLK'event and TX_CLK = '1' then	
			Tx_buffer_out <= '1';	
				
			if Tx_on_flag = "01" then
					
					DATA_buffer_shift := DATA_buffer_in;
					Tx_on_flag_next <= "10";
				
			elsif Tx_on_flag =  "10" then
					
					if Tx_count = 0 then	
						Tx_buffer_out <= '0';
						Tx_count <= Tx_count + '1';
						Tx_on_flag_next <= "10";
					elsif Tx_count >= 1 and Tx_count <= 28 then
						Tx_buffer_out <= DATA_buffer_shift(0);
						DATA_buffer_shift :=  '1' & DATA_buffer_shift(27 downto 1);
						Tx_count <= Tx_count + '1';
						Tx_on_flag_next <= "10";
					elsif Tx_count >= 29 then
						DATA_buffer_shift := (others => '1');
						Tx_count <= (others => '0');
						Tx_buffer_out <= '0' ;
						Tx_on_flag_next <= "11";
					end if;
		
			elsif Tx_on_flag = "11" then
			
					DATA_buffer_shift := (others => '1');
					Tx_buffer_out <= '1' ; 				
					Tx_on_flag_next <= "00";
			
			elsif Tx_on_flag = "00" then				
			
					DATA_buffer_shift := (others => '1');
					Tx_buffer_out <= '1' ; 
					Tx_on_flag_next <= "00";
					
			end if;
		
		end if;
		
		TX_OUT <= Tx_buffer_out;
		Tx_on_flag <= Tx_on_flag_next;
			
	end process;
	
	process(Tx_on_flag, OP_CLK)
	begin
		if OP_CLK'event and OP_CLK = '1' then
			if Tx_on_flag = "00" then
				TX_Busy <= '0';
			else
				TX_Busy <= '1';
			end if;
		end if;
	end process;
	
	
end arch;

