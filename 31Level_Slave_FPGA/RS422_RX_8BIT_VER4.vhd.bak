library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.all;

entity RS422_RX_8BIT_VER3 is
	port(
			OP_CLK							: in std_logic;
			AUX_CLK							: in std_logic;
			EMIF_ADDR						: in std_logic_vector(11 downto 0);
			EM1CS2n							: in std_logic;
			EM1WEn							: in std_logic;
			EM1OEn							: in std_logic;
			EMIF_DATA						: in std_logic_vector(15 downto 0);
			RSTn								: in std_logic;
			RX_SERIAL_IN					: in std_logic;
			
			DATA_OUT							: out std_logic_vector(15 downto 0);
			RX_INDICATOR					: out std_logic
	);
	

end RS422_RX_8BIT_VER3;


architecture RECEVING of RS422_RX_8BIT_VER3 is

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
		
	signal RX_INDICATOR_reg					: std_logic := '0';

	type STATETYPE is (IDLE, START, RECEVING);
	signal State 								: STATETYPE := IDLE;
	signal Next_State							: STATETYPE	:= IDLE;
	
	signal Stack_ptr							: integer range 0 to 8100 := 0;
	signal Stack_LSB							: integer range 0 to 8100 := 0;
	signal Stack_MSB							: integer range 0 to 8100 := 0;
	signal ACCESS_INDEX						: integer range 0 to 8100 := 0;
	signal Data_o 								: std_logic_vector(15 downto 0) := "0000000000000000";
	signal Data_LSB							: std_logic_vector(7 downto 0);
	signal Data_MSB							: std_logic_vector(7 downto 0);	
begin
	
	--LED_INDICATOR
	RX_LED_INDICAOTR_OP : process(AUX_CLK, State)
	begin
		if AUX_CLK'event and AUX_CLK = '1' then
			if STATE = RECEVING then
				RX_INDICATOR_reg <= '1';
			else
				RX_INDICATOR_reg <= '0';
			end if;
		end if;
		
		RX_INDICATOR <= RX_INDICATOR_reg;
	end process;
	
	--
	RS422_RX_FLAG : process(RSTn, OP_CLK, Flag_sample_cnt_clr, Flag_sample_cnt_inc, Flag_high_cnt_clr, Flag_high_cnt_inc,
								Flag_low_cnt_clr, Flag_low_cnt_inc, Flag_bit_deci, Flag_shift, Data_in_reg, Serial_in_reg)
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
	
	RS422_RX_STATE : process(State, RX_SERIAL_IN, Bit_cnt, Sample_cnt)
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
		
	MEMORY_OP : process(OP_CLK, RSTn, Data_in_reg, Stack_ptr, Data_LSB, Data_MSB)
	begin
		if RSTn = '0' then
			Stack_ptr <= 0;
		elsif OP_CLK'event and OP_CLK = '1' then
			if Flag_store = '1' then
				if Stack_ptr = Stack_LSB then
					Data_LSB <= Data_in_reg;
				elsif Stack_ptr = Stack_MSB then
					Data_MSB <= Data_in_reg;
					Data_o <= Data_MSB & Data_LSB;
				end if;
				Stack_ptr <= Stack_ptr + 1;
			end if;
		end if;
	end process;
		
	MEMMORY_ACCESS : process(AUX_CLK, EMIF_ADDR, EM1CS2n, EM1OEn, EMIF_DATA, Data_o, ACCESS_INDEX)
  	begin
	
		if AUX_CLK'event and AUX_CLK = '1' then	
			if EMIF_ADDR = "000010010101" and EM1CS2n = '0' then
				ACCESS_INDEX <= conv_integer(EMIF_DATA(15 downto 0));
				Stack_LSB <= 2*ACCESS_INDEX;
				Stack_MSB <= 2*ACCESS_INDEX+1;
			end if;
			
			if EMIF_ADDR = "000010010110" and EM1CS2n = '0' and EM1OEn = '0' then
				DATA_OUT <= Data_o;
			else
				DATA_OUT <= (others => 'Z');
			end if;
		end if;
	
	end process;
	
end RECEVING;
