library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;

entity RX_RS_422 is
	port(
			OP_CLK				: 	in std_logic;
			RX_CLK				:	in std_logic;
			RX_IN 				:	in std_logic;
						
			RX_DATA				: 	out std_logic_vector(27 downto 0);
			RX_End				:  out std_logic
			);
	


end RX_RS_422;

architecture arch of RX_RS_422 is

	signal Rx_en_reg1						:  std_logic_vector(1 downto 0) := "11";
	signal Rx_en_reg2						:  std_logic_vector(1 downto 0) := "11";
	signal Rx_start_en					:  std_logic := '1';
	signal Rx_start_flag					:  std_logic := '0';
	signal Rx_high							:  unsigned(5 downto 0)  := (others => '0');
	signal Rx_low							:  unsigned(5 downto 0)  := (others => '0');
	signal Rx_bit_count					:  unsigned(5 downto 0)  := (others => '0');
	signal Rx_sample_count				:  unsigned(5 downto 0)  := (others => '0');
	signal Rx_bit_flag					:  std_logic := '0';
	signal Rx_data_buffer				: 	std_logic_vector(29 downto 0) := (others => '1');
	signal Rx_buffer						:  std_logic := '1';
	signal Rx_out_buffer					:  std_logic_vector(27 downto 0) := (others => '1');
begin
	
	process(OP_CLK,RX_IN,Rx_start_en,Rx_start_flag)
	begin
	
		if RX_IN = '0' then
			if Rx_start_en = '1' then
				Rx_start_flag <= '1';
			else
				Rx_start_flag <= '0';
			end if;
		end if;

	end process;
	
	

	
	process(Rx_bit_flag,RX_CLK,Rx_sample_count, Rx_start_flag,Rx_start_en)
	begin
		
		if Rx_start_flag = '1' then
		
			Rx_start_en <= '0';
		
		elsif Rx_start_en = '0' then
					
			if RX_CLK'event and RX_CLK = '1' then
					
				Rx_sample_count <= Rx_sample_count + '1';	
			  
				if Rx_sample_count > 2 and Rx_sample_count < 15 then
					if RX_IN = '0' then
						Rx_low <= Rx_low + '1';
					else
						Rx_high <= Rx_high + '1';
					end if;
				end if;
				
				if Rx_sample_count = 14 then
						
					if Rx_low > Rx_high then
						Rx_buffer <= '0';
					else
						Rx_buffer <= '1';
					end if;
					
					Rx_low <= (others => '0');
					Rx_high <= (others => '0');
					Rx_sample_count <= (others => '0');
					
					if Rx_bit_count = 32 then
						Rx_bit_count <= (others => '0');
						Rx_start_en <= '1';
					else
						Rx_bit_count <= Rx_bit_count + '1';
					end if;
					
					Rx_bit_flag <= '1';
				
				else
					Rx_bit_flag <= '0';
				end if;
			end if;
		else
			Rx_bit_flag <= '0';
		end if;
		
	end process;
	
	
	process(RX_CLK,Rx_data_buffer,Rx_buffer,Rx_bit_count, Rx_en_reg1,Rx_en_reg2, Rx_out_buffer)
	begin
		
		if RX_CLK'event and RX_CLK = '1' then
			if Rx_bit_flag = '1' then			
				if Rx_bit_count >= 1 and Rx_bit_count <= 30 then
					Rx_data_buffer <=  Rx_buffer & Rx_data_buffer(29 downto 1);
				elsif Rx_bit_count = 31 then
					Rx_out_buffer <= Rx_data_buffer(28 downto 1);
				end if; 
			end if;
		end if;
		
		if Rx_data_buffer(0) = '0' then
			RX_DATA <= Rx_out_buffer;
			RX_End <= '0';
			if Rx_bit_count < 31 then
				RX_End <= '1';
			end if;
		else
			RX_DATA <= (others => 'Z');
			RX_End <= '1';
		end if;
	end process;	
end arch;
