library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

entity RS422_RX_RECEIVING_8BIT is
	port(
			OP_CLK							: in std_logic;
			AUX_CLK							: in std_logic;
			EMIF_ADDR						: in std_logic_vector(11 downto 0);
			EM1CS2n							: in std_logic;
			EM1WEn							: in std_logic;
			EM1OEn							: in std_logic;
			RSTn								: in std_logic;
			RX_SERIAL_IN					: in std_logic;
			
			DATA_OUT							: out std_logic_vector(15 downto 0)
	);
	

end RS422_RX_RECEIVING_8BIT;


architecture RECEVING of RS422_RX_RECEIVING_8BIT is

	signal Sample_cnt							: integer range 0 to 21 := 0;
	signal High_cnt							: integer range 0 to 21 := 0;
	signal Low_cnt								: integer range 0 to 21 := 0;
	signal Bit_cnt								: integer range 0 to 9 := 0;
	
	signal Flag_sample_cnt_inc 			: std_logic := '0';
	signal Flag_sample_cnt_clr 			: std_logic := '0';
	signal Flag_high_cnt_inc	 			: std_logic := '0';
	signal Flag_high_cnt_clr				: std_logic := '0';
	signal Flag_low_cnt_inc 				: std_logic := '0';
	signal Flag_low_cnt_clr					: std_logic := '0';
	signal Flag_bit_deci						: std_logic := '0';
	signal Flag_shift							: std_logic := '0';
	signal Flag_bit_cnt_clr					: std_logic := '0';
	signal Flag_store							: std_logic := '0';	
		
	signal Serial_in_reg 					: std_logic := 'Z';
	signal Data_in_reg						: std_logic_vector(7 downto 0) := (others => 'Z');
	signal Data_out_reg						: std_logic_vector(7 downto 0)	:= (others => 'Z');

	type STATETYPE is (IDLE, START, RECEVING);
	signal State 								: STATETYPE := IDLE;
	signal Next_State							: STATETYPE	:= IDLE;
	
	type DATA_MEM is array (0 to 39) of std_logic_vector(15 downto 0);
	signal Data_o			 			: DATA_MEM;

begin
	
	RECEVING_OP : process(RSTn, OP_CLK, Flag_sample_cnt_clr, Flag_sample_cnt_inc, Flag_high_cnt_clr, Flag_high_cnt_inc,
								Flag_low_cnt_clr, Flag_low_cnt_inc, Flag_bit_deci, Flag_shift)
	begin
		
		if RSTn = '0' then
			State <= IDLE;
			Sample_cnt <= 0;
			High_cnt <= 0;
			Low_cnt	<= 0;
			Bit_cnt <= 0;
		elsif(OP_CLK'event and OP_CLK = '1') then
			State <= Next_State;
			
			if Flag_sample_cnt_clr = '1'  then
				Sample_cnt <= 0;
			elsif Flag_sample_cnt_inc = '1' then
				Sample_cnt <= Sample_cnt + 1;
			end if;
			
			if Flag_high_cnt_clr = '1' then
				Sample_cnt <= 0;
				High_cnt <= 0;
			elsif Flag_high_cnt_inc = '1' then
				Sample_cnt <= Sample_cnt + 1;
				High_cnt <= High_cnt + 1;
			end if;
			
			if Flag_low_cnt_clr = '1' then
				Sample_cnt <= 0;
				Low_cnt <= 0;
			elsif Flag_low_cnt_inc = '1' then
				Sample_cnt <= Sample_cnt + 1;
				Low_cnt <= Low_cnt + 1;
			end if;
	
			if Flag_bit_deci = '1' then
				if High_cnt >= Low_cnt then
					Serial_in_reg <= '1';
				else
					Serial_in_reg <= '0';
				end if;
			end if;
	
			if Flag_bit_cnt_clr = '1' then
				Sample_cnt <= 0;
				High_cnt <= 0;
				Low_cnt <= 0;
				Bit_cnt <= 0;
			elsif Flag_shift = '1' then
				Bit_cnt <= Bit_cnt + 1;
				Sample_cnt <= 0;
				High_cnt <= 0;
				Low_cnt <= 0;
				Data_in_reg <= Serial_in_reg & Data_in_reg(7 downto 1);
			end if;	
		end if;
	end process;
	
	STATE_SWITCH : process(State, RX_SERIAL_IN, Bit_cnt, Sample_cnt, Data_in_reg)
	begin
	
		Flag_sample_cnt_inc 	<= '0';
		Flag_sample_cnt_clr 	<= '0';
		Flag_high_cnt_inc 	<= '0';
		Flag_high_cnt_clr		<= '0';
		Flag_low_cnt_inc 		<= '0';
		Flag_low_cnt_clr		<= '0';
		Flag_bit_deci			<= '0';
		Flag_shift				<= '0';
		Flag_bit_cnt_clr		<= '0';	
		Flag_store				<= '0';
				
		case State is
			when IDLE =>
				if RX_SERIAL_IN = '0' then
					Next_State <= START;
				else 
					Next_State <= IDLE;
				end if;
			when START =>
				if RX_SERIAL_IN = '1' then
					Flag_sample_cnt_clr <= '1';
					Next_State <= IDLE;
				elsif Sample_cnt <= 17 then
					Flag_sample_cnt_inc <= '1';
					Next_State <= START;
				else 
					Flag_sample_cnt_clr <= '1';
					Next_State <= RECEVING;
				end if;
			when RECEVING => 
				if	Bit_cnt < 8 then
					if Sample_cnt < 18 then
						if Sample_cnt >= 7 and Sample_cnt <= 17 then
							if RX_SERIAL_IN = '1' then
								Flag_high_cnt_inc <= '1';
							elsif RX_SERIAL_IN = '0' then
								Flag_low_cnt_inc <= '1';
							end if;
						else
							Flag_sample_cnt_inc <= '1';
						end if;
						Next_State <= RECEVING;
					elsif Sample_cnt = 18 then
						Flag_bit_deci <= '1';
						Flag_sample_cnt_inc <= '1';
					else	
						Flag_shift <= '1';
						Next_State <= RECEVING;
					end if;
				elsif	Bit_cnt = 8 then
					if Sample_cnt < 19 then
						Flag_sample_cnt_inc <= '1';
						Next_State <= RECEVING;
					elsif Sample_cnt = 19 then
						Flag_bit_cnt_clr <= '1';
						Flag_store <= '1';
						Next_State <= IDLE;
					end if;
				else
					Next_State <= IDLE;
				end if;	
			when others =>
				Next_State <= IDLE;
		end case;
	end process;

	MEMORY : process(OP_CLK, Data_in_reg)
	begin
		if OP_CLK'event and OP_CLK = '1' then
			if Flag_store = '1' then
				Data_o(0) <= Data_o(1);
				Data_o(1) <= Data_o(2);
				Data_o(2) <= Data_o(3);
				Data_o(3) <= Data_o(4);
				Data_o(4) <= Data_o(5);
				Data_o(5) <= Data_o(6);
				Data_o(6) <= Data_o(7);
				Data_o(7) <= Data_o(8);
				Data_o(8) <= Data_o(9);
				Data_o(9) <= Data_o(10);
				Data_o(10) <= Data_o(11);
				Data_o(11) <= Data_o(12);
				Data_o(12) <= Data_o(13);
				Data_o(13) <= Data_o(14);
				Data_o(14) <= Data_o(15);
				Data_o(15) <= Data_o(16);
				Data_o(16) <= Data_o(17);
				Data_o(17) <= Data_o(18);
				Data_o(18) <= Data_o(19);
				Data_o(19) <= Data_o(20);
				Data_o(20) <= Data_o(21);
				Data_o(21) <= Data_o(22);
				Data_o(22) <= Data_o(23);
				Data_o(23) <= Data_o(24);
				Data_o(24) <= Data_o(25);
				Data_o(25) <= Data_o(26);
				Data_o(26) <= Data_o(27);
				Data_o(27) <= Data_o(28);
				Data_o(28) <= Data_o(29);
				Data_o(29) <= Data_o(30);
				Data_o(30) <= Data_o(31);
				Data_o(31) <= Data_o(32);
				Data_o(32) <= Data_o(33);
				Data_o(33) <= Data_o(34);
				Data_o(34) <= Data_o(35);
				Data_o(35) <= Data_o(36);
				Data_o(36) <= Data_o(37);
				Data_o(37) <= "00000000" & Data_in_reg;
			end if;
		end if;
	end process;
	
	DATA_ACCESS : process(AUX_CLK, EMIF_ADDR, EM1CS2n, Data_o)
	begin
		
		if AUX_CLK'event and AUX_CLK = '1' then	
			if EMIF_ADDR = "000000100000" and EM1CS2n = '0' and EM1OEn = '0' then
					DATA_OUT <= Data_o(0);
			elsif EMIF_ADDR = "000000100001" and EM1CS2n = '0' and EM1OEn = '0' then
					DATA_OUT <= Data_o(1);
			elsif EMIF_ADDR = "000000100010" and EM1CS2n = '0' and EM1OEn = '0'  then
					DATA_OUT <= Data_o(2);
			elsif EMIF_ADDR = "000000100011" and EM1CS2n = '0' and EM1OEn = '0'  then
					DATA_OUT <= Data_o(3);
			elsif EMIF_ADDR = "000000100100" and EM1CS2n = '0' and EM1OEn = '0'  then
					DATA_OUT <= Data_o(4);
			elsif EMIF_ADDR = "000000100101" and EM1CS2n = '0' and EM1OEn = '0'  then
					DATA_OUT <= Data_o(5);
			elsif EMIF_ADDR = "000000100110" and EM1CS2n = '0' and EM1OEn = '0'  then
					DATA_OUT <= Data_o(6);
			elsif EMIF_ADDR = "000000100111" and EM1CS2n = '0' and EM1OEn = '0'  then
					DATA_OUT <= Data_o(7);
			elsif EMIF_ADDR = "000000101000"  and EM1CS2n = '0' and EM1OEn = '0' then
					DATA_OUT <= Data_o(8);
			elsif EMIF_ADDR = "000000101001"  and EM1CS2n = '0' and EM1OEn = '0' then
					DATA_OUT <= Data_o(9);
			
			elsif EMIF_ADDR = "000000101010"  and EM1CS2n = '0' and EM1OEn = '0' then
					DATA_OUT <= Data_o(10);
			elsif EMIF_ADDR = "000000101011"  and EM1CS2n = '0' and EM1OEn = '0' then
					DATA_OUT <= Data_o(11);
			elsif EMIF_ADDR = "000000101100"  and EM1CS2n = '0' and EM1OEn = '0' then
					DATA_OUT <= Data_o(12);
			elsif EMIF_ADDR = "000000101101"  and EM1CS2n = '0' and EM1OEn = '0' then
					DATA_OUT <= Data_o(13);
			elsif EMIF_ADDR = "000000101110"  and EM1CS2n = '0' and EM1OEn = '0' then
					DATA_OUT <= Data_o(14);
			elsif EMIF_ADDR = "000000101111"  and EM1CS2n = '0' and EM1OEn = '0' then
					DATA_OUT <= Data_o(15);
			elsif EMIF_ADDR = "000000110000"  and EM1CS2n = '0' and EM1OEn = '0' then
					DATA_OUT <= Data_o(16);				
			elsif EMIF_ADDR = "000000110001"  and EM1CS2n = '0' and EM1OEn = '0' then
					DATA_OUT <= Data_o(17);		
			elsif EMIF_ADDR = "000000110010"  and EM1CS2n = '0' and EM1OEn = '0' then
					DATA_OUT <= Data_o(18);	
			elsif EMIF_ADDR = "000000110011"  and EM1CS2n = '0' and EM1OEn = '0' then
					DATA_OUT <= Data_o(19);	
					
			elsif EMIF_ADDR = "000010000000" and EM1CS2n = '0' and EM1OEn = '0' then
					DATA_OUT <= Data_o(20);
			elsif EMIF_ADDR = "000010000001" and EM1CS2n = '0' and EM1OEn = '0' then
					DATA_OUT <= Data_o(21);
			elsif EMIF_ADDR = "000010000010" and EM1CS2n = '0' and EM1OEn = '0'  then
					DATA_OUT <= Data_o(22);
			elsif EMIF_ADDR = "000010000011" and EM1CS2n = '0' and EM1OEn = '0'  then
					DATA_OUT <= Data_o(23);
			elsif EMIF_ADDR = "000010000100" and EM1CS2n = '0' and EM1OEn = '0'  then
					DATA_OUT <= Data_o(24);
			elsif EMIF_ADDR = "000010000101" and EM1CS2n = '0' and EM1OEn = '0'  then
					DATA_OUT <= Data_o(25);
			elsif EMIF_ADDR = "000010000110" and EM1CS2n = '0' and EM1OEn = '0'  then
					DATA_OUT <= Data_o(26);
			elsif EMIF_ADDR = "000010000111" and EM1CS2n = '0' and EM1OEn = '0'  then
					DATA_OUT <= Data_o(27);
			elsif EMIF_ADDR = "000010001000"  and EM1CS2n = '0' and EM1OEn = '0' then
					DATA_OUT <= Data_o(28);
			elsif EMIF_ADDR = "000010001001"  and EM1CS2n = '0' and EM1OEn = '0' then
					DATA_OUT <= Data_o(29);
			
			elsif EMIF_ADDR = "000010001010"  and EM1CS2n = '0' and EM1OEn = '0' then
					DATA_OUT <= Data_o(30);
			elsif EMIF_ADDR = "000010001011"  and EM1CS2n = '0' and EM1OEn = '0' then
					DATA_OUT <= Data_o(31);
			elsif EMIF_ADDR = "000010001100"  and EM1CS2n = '0' and EM1OEn = '0' then
					DATA_OUT <= Data_o(32);
			elsif EMIF_ADDR = "000010001101"  and EM1CS2n = '0' and EM1OEn = '0' then
					DATA_OUT <= Data_o(33);
			elsif EMIF_ADDR = "000010001110"  and EM1CS2n = '0' and EM1OEn = '0' then
					DATA_OUT <= Data_o(34);
			elsif EMIF_ADDR = "000010001111"  and EM1CS2n = '0' and EM1OEn = '0' then
					DATA_OUT <= Data_o(35);
			elsif EMIF_ADDR = "000010010000"  and EM1CS2n = '0' and EM1OEn = '0' then
					DATA_OUT <= Data_o(36);				
			elsif EMIF_ADDR = "000010010001"  and EM1CS2n = '0' and EM1OEn = '0' then
					DATA_OUT <= Data_o(37);		
			elsif EMIF_ADDR = "000010010010"  and EM1CS2n = '0' and EM1OEn = '0' then
					DATA_OUT <= Data_o(38);	
			elsif EMIF_ADDR = "000010010011"  and EM1CS2n = '0' and EM1OEn = '0' then
					DATA_OUT <= Data_o(39);	
			else
					DATA_OUT <= (others => 'Z');
			end if;
		end if;
	end process;
	
end RECEVING;
