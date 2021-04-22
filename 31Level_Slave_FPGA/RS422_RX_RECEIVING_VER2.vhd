library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

entity RS422_RX_RECEIVING_VER2 is
	port(
			OP_CLK							: in std_logic;
			EMIF_ADDR						: in std_logic_vector(11 downto 0);
			EM1CS2n							: in std_logic;
			EM1WEn							: in std_logic;
			EM1OEn							: in std_logic;
			RSTn								: in std_logic;
			RX_SERIAL_IN					: in std_logic;
			
			DATA_OUT							: out std_logic_vector(15 downto 0)
	);
	

end RS422_RX_RECEIVING_VER2;


architecture RECEVING of RS422_RX_RECEIVING_VER2 is

	signal Sample_cnt							: integer range 0 to 21 := 0;
	signal High_cnt							: integer range 0 to 21 := 0;
	signal Low_cnt								: integer range 0 to 21 := 0;
	signal Bit_cnt								: integer range 0 to 305 := 0;
	signal Access_cnt							: integer range 0 to 305 := 0;
	
	signal Flag_sample_cnt_inc 			: std_logic := '0';
	signal Flag_sample_cnt_clr 			: std_logic := '0';
	signal Flag_high_cnt_inc	 			: std_logic := '0';
	signal Flag_high_cnt_clr				: std_logic := '0';
	signal Flag_low_cnt_inc 				: std_logic := '0';
	signal Flag_low_cnt_clr					: std_logic := '0';
	signal Flag_bit_deci						: std_logic := '0';
	signal Flag_access_clr					: std_logic := '0';
	signal Flag_access_inc					: std_logic := '0';
	signal Flag_shift							: std_logic := '0';
	signal Flag_bit_cnt_clr					: std_logic := '0';
		
	signal Serial_in_reg 					: std_logic := 'Z';
	signal Data_in_reg						: std_logic_vector(303 downto 0) := (others => 'Z');
	signal Data_out_reg						: std_logic_vector(303 downto 0)	:= (others => 'Z');

	type STATETYPE is (IDLE, START, RECEVING, STOP);
	signal State 								: STATETYPE := IDLE;
	signal Next_State							: STATETYPE	:= IDLE;
	
	type DATA_MEM is array (0 to 19) of std_logic_vector(15 downto 0);
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
			Access_cnt <= 0;
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
				Data_in_reg <= Serial_in_reg & Data_in_reg(303 downto 1);
			end if;	
			
			if Flag_access_clr = '1'  then
				Access_cnt <= 0;
			elsif Flag_access_inc = '1' then
				Access_cnt <= Access_cnt + 1;
			end if;
		end if;
	end process;
	
	STATE_SWITCH : process(State, RX_SERIAL_IN, Bit_cnt, Sample_cnt, Access_cnt, Data_in_reg)
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
		Flag_access_clr		<= '0';
		Flag_access_inc		<= '0';
				
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
				elsif Sample_cnt <= 15 then
					Flag_sample_cnt_inc <= '1';
					Next_State <= START;
				else 
					Flag_sample_cnt_clr <= '1';
					Next_State <= RECEVING;
				end if;
			when RECEVING => 
				if	Bit_cnt < 304 then
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
				elsif	Bit_cnt = 304 then
						Flag_bit_cnt_clr <= '1';
						Next_State <= STOP;
				else
					Next_State <= STOP;
				end if;	
			when STOP =>
				if Access_cnt < 303 then
					Flag_access_inc <= '1';
					Next_State <= STOP;
				else
					Flag_access_clr <= '1';
					Next_State <= IDLE;
				end if;
			when others =>
				Next_State <= IDLE;
		end case;
	end process;

	Allocation :process(OP_CLK, Data_in_reg, Data_out_reg)
	begin
		if OP_CLK'event and OP_CLK = '1' then
			if State = STOP then
				Data_out_reg <= Data_in_reg;
				Data_o(0) <= "00000000" & Data_out_reg(7 downto 0);
				Data_o(1) <= "00000000" & Data_out_reg(15 downto 8);
				Data_o(2) <= Data_out_reg(31 downto 16);
				Data_o(3) <= Data_out_reg(47 downto 32);
				Data_o(4) <= Data_out_reg(63 downto 48);
				Data_o(5) <= Data_out_reg(79 downto 64);
				Data_o(6) <= Data_out_reg(95 downto 80);
				Data_o(7) <= Data_out_reg(111 downto 96);
				Data_o(8) <= Data_out_reg(127 downto 112);
				Data_o(9) <= Data_out_reg(143 downto 128);
				Data_o(10) <= Data_out_reg(159 downto 144);
				Data_o(11) <= Data_out_reg(175 downto 160);
				Data_o(12) <= Data_out_reg(191 downto 176);
				Data_o(13) <= Data_out_reg(207 downto 192);
				Data_o(14) <= Data_out_reg(223 downto 208);
				Data_o(15) <= Data_out_reg(239 downto 224);
				Data_o(16) <= Data_out_reg(255 downto 240);
				Data_o(17) <= Data_out_reg(271 downto 256);
				Data_o(18) <= Data_out_reg(287 downto 272);
				Data_o(19) <= Data_out_reg(303 downto 288);
			end if;
		end if;
	end process;
	
	DATA_ACCESS : process(OP_CLK, EMIF_ADDR, EM1CS2n, Data_o)
	begin
		
		if OP_CLK'event and OP_CLK = '1' then	
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
			else
					DATA_OUT <= (others => 'Z');
			end if;
		end if;
	end process;
	
end RECEVING;
