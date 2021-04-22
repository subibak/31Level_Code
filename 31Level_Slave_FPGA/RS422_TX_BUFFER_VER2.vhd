library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity RS422_TX_BUFFER_VER2 is 
	
	port(
			OP_CLK			: 	in std_logic;
			RSTn				:	in std_logic;									-- Reset 
			STORE_ENn		:	in std_logic;									-- Data input enable
			NUMn				:	in std_logic;									-- Group number
			FAUn				:	in std_logic;									-- Groupmodule fault
			TEMn				: 	in std_logic;									-- Submodule Temperatre of groupmodule
			VOLn				:	in std_logic;									-- Submodule votlage of groupmodule
			REG_ENn			:	in std_logic;									-- Register to DATA_OUT
			DATA_IN			:  in std_logic_vector(15 downto 0);	
		
			DATA_OUT			:  out std_logic_vector(303 downto 0)
		);
		
end RS422_TX_BUFFER_VER2;

 
architecture TX_BUFFER of RS422_TX_BUFFER_VER2 is

	signal Flag_num 			: std_logic := '0';
	signal Flag_fau 			: std_logic := '0';
	signal Flag_tem 			: std_logic := '0';
	signal Flag_vol 			: std_logic := '0';
	signal Flag_reg 			: std_logic := '0';
	
	signal Num_reg				: std_logic_vector(7 downto 0) := (others => '0');
	signal Fau_reg				: std_logic_vector(7 downto 0) := (others => '0');
	signal Data_reg			: std_logic_vector(303 downto 0) := (others => '0');
	
	signal Tem_cnt				: integer range 0 to 12 := 0;
	signal Vol_cnt				: integer range 0 to 6	:= 0;
		
	type TEMP_MEM is array (0 to 11) of std_logic_vector(15 downto 0);
	signal Tem_reg 			: TEMP_MEM;
	
	type VOL_MEM is array (0 to 5) of std_logic_vector(15 downto 0);
	signal Vol_reg				: VOL_MEM;
	
	type STATETYPE is (IDLE, STORE, SENDING);
	signal State		 		: STATETYPE := IDLE;
	signal Next_State 		: STATETYPE := IDLE;	
begin
	
	BUFFER_OPERATION : process(RSTn, OP_CLK, Data_reg)
	begin
		
		DATA_OUT <= Data_reg;
		
		if RSTn = '0' then
			STATE <= IDLE;
			Tem_cnt <= 0;
			Vol_cnt <= 0;
		elsif OP_CLK'event and OP_CLK = '1' then
			STATE <= Next_State;
			
			if Flag_num = '1' then
				Num_reg(7 downto 0) <= DATA_IN(7 downto 0);
			end if;
			if Flag_fau = '1' then
				Fau_reg(7 downto 0) <= DATA_IN(7 downto 0);
			end if;
			if Flag_tem = '1' then
				Tem_reg(Tem_cnt) <= DATA_IN(15 downto 0);
				Tem_cnt <= Tem_cnt + 1;
			end if;
			if Flag_vol = '1' then
				Vol_reg(Vol_cnt) <= DATA_IN(15 downto 0);
				Vol_cnt <= Vol_cnt + 1;
			end if;

		end if;
			
	end process;
	
	
	NEXT_STATE_SWITCH : process(State, STORE_ENn, NUMn, FAUn, TEMn, VOLn, REG_ENn, Vol_cnt, Vol_reg, Tem_reg,
										Fau_reg, Num_reg)
	begin
		
		Flag_num 	<= '0';
		Flag_fau 	<= '0';
		Flag_tem 	<= '0';
		Flag_vol 	<= '0';
		Flag_reg 	<= '0';
	
		case State is
			when IDLE =>
				if STORE_ENn = '0' then
					Next_State <= STORE;
				else
					Next_State <= IDLE;
				end if;
			when STORE =>
				if NUMn = '0' then
					Flag_num <= '1';
					Next_State <= STORE;
				end if;
								
				if FAUn = '0' then
					Flag_fau <= '1';
					Next_State <= STORE;
				end if;
				
				if TEMn = '0' then
					if Tem_cnt <= 11 then
						Flag_tem <= '1';
						Next_State <= STORE;
					end if;
				end if;	
				
				if VOLn = '0' then
					if(Vol_cnt <= 5) then
						Flag_vol <= '1';
						Next_State <= STORE;
					end if;
				end if;
				
				if REG_ENn = '0' then
					Next_State <= SENDING;
				end if;
				
			when SENDING =>
				Data_reg <= Vol_reg(5) & Vol_reg(4) & Vol_reg(3) & Vol_reg(2) & Vol_reg(1) & Vol_reg(0) &
								Tem_reg(11) & Tem_reg(10) & Tem_reg(9) & Tem_reg(8) & 
								Tem_reg(7) & Tem_reg(6) & Tem_reg(5) & Tem_reg(4) & 
								Tem_reg(3) & Tem_reg(2) & Tem_reg(1) & Tem_reg(0) & Fau_reg & Num_reg;
				Next_State <= IDLE;
--			when others =>
--				Next_State <= IDLE;
		end case;				
	end process;

end TX_BUFFER;

