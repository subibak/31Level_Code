library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;


entity CARRIER_GENERATOR_HB6 is

	port(
			OP_CLK						:	in std_logic;
				
			EMIF_ADDR					:	in std_logic_vector(11 downto 0);
			EM1CS2n						:	in std_logic;
			EM1WEn						: 	in std_logic;	
			EMIF1_DATA					:  in std_logic_vector(14 downto 0);
			
			CNT_A1_OUT 					:	out std_logic_vector(13 downto 0);
			SEQ_A1_OUT					:  out std_logic;

			CNT_A2_OUT 					:	buffer std_logic_vector(13 downto 0);
			SEQ_A2_OUT					:  out std_logic;

			CNT_A3_OUT 					:	buffer std_logic_vector(13 downto 0);
			SEQ_A3_OUT					:  out std_logic;
						
			CNT_B1_OUT 					:	buffer std_logic_vector(13 downto 0);
			SEQ_B1_OUT					:  out std_logic;

			CNT_B2_OUT 					:	buffer std_logic_vector(13 downto 0);
			SEQ_B2_OUT					:  out std_logic;

			CNT_B3_OUT		 			:	buffer std_logic_vector(13 downto 0);
			SEQ_B3_OUT					:  out std_logic
		);
	

end CARRIER_GENERATOR_HB6;

architecture arch of CARRIER_GENERATOR_HB6 is

	signal HALF_CNT				:		std_logic_vector(13 downto 0)	:=	"10011100010000";	--------  10000 count
	signal SEQ1_MAX				:		std_logic_vector(13 downto 0)	:=	"10011100001111";	--------  9999 count
	constant SEQ0_MIN				:		std_logic_vector(13 downto 0)	:=	"00000000000001"; --------     1 count
	constant ZERO_CNT				:		std_logic_vector(13 downto 0)	:=	"00000000000000"; --------     0 count
	constant SEQ0					:		std_logic  := '0';
	constant SEQ1					:		std_logic  := '1';
	
	signal INIT_CARRIER_A1		:		std_logic_vector(13 downto 0) := "00000000000000"; --------  Carrier 1 (initial : 0, seq : 1)
	signal INIT_CARRIER_A2		:		std_logic_vector(13 downto 0) := "00000000000000";	--------  Carrier 2 (initial : 0, seq : 1)
	signal INIT_CARRIER_A3		:		std_logic_vector(13 downto 0) := "00000000000000"; --------  Carrier 3 (initial : 0, seq : 1)
	signal INIT_CARRIER_B1		:		std_logic_vector(13 downto 0) := "00000000000000"; --------  Carrier 4 (initial : 0, seq : 1)
	signal INIT_CARRIER_B2		:		std_logic_vector(13 downto 0) := "00000000000000"; --------  Carrier 5 (initial : 0, seq : 1)
	signal INIT_CARRIER_B3		:		std_logic_vector(13 downto 0) := "00000000000000";	--------  Carrier 6 (initial : 0, seq : 1)

	signal INIT_SEQ_A1			:		std_logic := '1';
	signal INIT_SEQ_A2			:		std_logic := '1';
	signal INIT_SEQ_A3			:		std_logic := '1';
	signal INIT_SEQ_B1			:		std_logic := '1';
	signal INIT_SEQ_B2			:		std_logic := '1';
	signal INIT_SEQ_B3			:		std_logic := '1';
	
	signal FINAL_CARRIER_A1		:		std_logic_vector(13 downto 0) := "00000000000001";
	signal FINAL_CARRIER_A2		:		std_logic_vector(13 downto 0) := "00000000000001";
	signal FINAL_CARRIER_A3		:		std_logic_vector(13 downto 0) := "00000000000001";
	signal FINAL_CARRIER_B1		:		std_logic_vector(13 downto 0) := "00000000000001";
	signal FINAL_CARRIER_B2		:		std_logic_vector(13 downto 0) := "00000000000001";
	signal FINAL_CARRIER_B3		:		std_logic_vector(13 downto 0) := "00000000000001";
	
	signal cnt_A1_value			:		std_logic_vector(13 downto 0) := "00000000000000";
	signal cnt_A2_value			:		std_logic_vector(13 downto 0) := "00000000000000";
	signal cnt_A3_value			:		std_logic_vector(13 downto 0) := "00000000000000";
	signal cnt_B1_value			:		std_logic_vector(13 downto 0) := "00000000000000";
	signal cnt_B2_value			:		std_logic_vector(13 downto 0) := "00000000000000";
	signal cnt_B3_value			:		std_logic_vector(13 downto 0) := "00000000000000";
	
	signal cnt_A1_seq				: 		std_logic := '1';
	signal cnt_A2_seq				: 		std_logic := '1';			
	signal cnt_A3_seq				: 		std_logic := '1';			
	signal cnt_B1_seq				: 		std_logic := '1';			
	signal cnt_B2_seq				: 		std_logic := '1';
	signal cnt_B3_seq				: 		std_logic := '1';			
	
	type STATETYPE is (IDLE, INIT, UP_DOWN);
	signal  A1_State			:	STATETYPE := IDLE;
	signal  A1_Next_State	: 	STATETYPE := IDLE;
	
	signal Flag_cnt_up			:		std_logic := '0';
   signal Flag_cnt_down			:		std_logic := '0';
	signal Flag_init_load 		:		std_logic := '0';
	signal Flag_seq1_half 		:		std_logic := '0';
	signal Flag_seq0_half 		:		std_logic := '0';

begin
	
		INITIALIZATION : process(OP_CLK, EMIF_ADDR, EM1CS2n, EM1WEn)
		begin
			if OP_CLK'event and OP_CLK = '1' then
				if EMIF_ADDR = "000010100001" and EM1CS2n = '0' and EM1WEn = '0' then
					INIT_CARRIER_A1	<= EMIF1_DATA(14 downto 1);
					INIT_SEQ_A1		<= EMIF1_DATA(0);
					if INIT_SEQ_A1 = '0' and INIT_CARRIER_A1 = HALF_CNT then
						FINAL_CARRIER_A1 <= HALF_CNT - '1';
					elsif INIT_SEQ_A1 = '1' and INIT_CARRIER_A1 /= ZERO_CNT then
						FINAL_CARRIER_A1 <= INIT_CARRIER_A1 - '1';	
					elsif INIT_SEQ_A1 = '1' and INIT_CARRIER_A1 = ZERO_CNT then
						FINAL_CARRIER_A1 <= "00000000000001";
					elsif INIT_SEQ_A1 = '0' and INIT_CARRIER_A1 /= ZERO_CNT then
						FINAL_CARRIER_A1 <= INIT_CARRIER_A1 + '1';
					end if;
				end if;
				if EMIF_ADDR = "000010100010" and EM1CS2n = '0' and EM1WEn = '0' then
					INIT_CARRIER_A2	<= EMIF1_DATA(14 downto 1);
					INIT_SEQ_A2		<= EMIF1_DATA(0);
					if INIT_SEQ_A2 = '0' and INIT_CARRIER_A2 = HALF_CNT then
						FINAL_CARRIER_A2 <= HALF_CNT - '1';
					elsif INIT_SEQ_A2 = '1' and INIT_CARRIER_A2 /= ZERO_CNT then
						FINAL_CARRIER_A2 <= INIT_CARRIER_A2 - '1';	
					elsif INIT_SEQ_A2 = '1' and INIT_CARRIER_A2 = ZERO_CNT then
						FINAL_CARRIER_A2 <= "00000000000001";
					elsif INIT_SEQ_A2 = '0' and INIT_CARRIER_A2 /= ZERO_CNT then
						FINAL_CARRIER_A2 <= INIT_CARRIER_A2 + '1';
					end if;
				end if;
				if EMIF_ADDR = "000010100011" and EM1CS2n = '0' and EM1WEn = '0' then
					INIT_CARRIER_A3	<= EMIF1_DATA(14 downto 1);
					INIT_SEQ_A3		<= EMIF1_DATA(0);
					if INIT_SEQ_A3 = '0' and INIT_CARRIER_A3 = HALF_CNT then
						FINAL_CARRIER_A3 <= HALF_CNT - '1';
					elsif INIT_SEQ_A3 = '1' and INIT_CARRIER_A3 /= ZERO_CNT then
						FINAL_CARRIER_A3 <= INIT_CARRIER_A3 - '1';	
					elsif INIT_SEQ_A3 = '1' and INIT_CARRIER_A3 = ZERO_CNT then
						FINAL_CARRIER_A3 <= "00000000000001";
					elsif INIT_SEQ_A3 = '0' and INIT_CARRIER_A3 /= ZERO_CNT then
						FINAL_CARRIER_A3 <= INIT_CARRIER_A3 + '1';
					end if;
				end if;
				if EMIF_ADDR = "000010100100" and EM1CS2n = '0' and EM1WEn = '0' then
					INIT_CARRIER_B1	<= EMIF1_DATA(14 downto 1);
					INIT_SEQ_B1		<= EMIF1_DATA(0);
					if INIT_SEQ_B1 = '0' and INIT_CARRIER_B1 = HALF_CNT then
						FINAL_CARRIER_B1 <= HALF_CNT - '1';
					elsif INIT_SEQ_B1 = '1' and INIT_CARRIER_B1 /= ZERO_CNT then
						FINAL_CARRIER_B1 <= INIT_CARRIER_B1 - '1';	
					elsif INIT_SEQ_B1 = '1' and INIT_CARRIER_B1 = ZERO_CNT then
						FINAL_CARRIER_B1 <= "00000000000001";
					elsif INIT_SEQ_B1 = '0' and INIT_CARRIER_B1 /= ZERO_CNT then
						FINAL_CARRIER_B1 <= INIT_CARRIER_B1 + '1';
					end if;
				end if;
				if EMIF_ADDR = "000010100101" and EM1CS2n = '0' and EM1WEn = '0' then
					INIT_CARRIER_B2	<= EMIF1_DATA(14 downto 1);
					INIT_SEQ_B2		<= EMIF1_DATA(0);
					if INIT_SEQ_B2 = '0' and INIT_CARRIER_B2 = HALF_CNT then
						FINAL_CARRIER_B2 <= HALF_CNT - '1';
					elsif INIT_SEQ_B2 = '1' and INIT_CARRIER_B2 /= ZERO_CNT then
						FINAL_CARRIER_B2 <= INIT_CARRIER_B2 - '1';	
					elsif INIT_SEQ_B2 = '1' and INIT_CARRIER_B2 = ZERO_CNT then
						FINAL_CARRIER_B2 <= "00000000000001";
					elsif INIT_SEQ_B2 = '0' and INIT_CARRIER_B2 /= ZERO_CNT then
						FINAL_CARRIER_B2 <= INIT_CARRIER_B2 + '1';
					end if;
				end if;
				if EMIF_ADDR = "000010100110" and EM1CS2n = '0' and EM1WEn = '0' then
					INIT_CARRIER_B3	<= EMIF1_DATA(14 downto 1);
					INIT_SEQ_B3		<= EMIF1_DATA(0);
					if INIT_SEQ_B3 = '0' and INIT_CARRIER_B3 = HALF_CNT then
						FINAL_CARRIER_B3 <= HALF_CNT - '1';
					elsif INIT_SEQ_B3 = '1' and INIT_CARRIER_B3 /= ZERO_CNT then
						FINAL_CARRIER_B3 <= INIT_CARRIER_B3 - '1';	
					elsif INIT_SEQ_B3 = '1' and INIT_CARRIER_B3 = ZERO_CNT then
						FINAL_CARRIER_B3 <= "00000000000001";
					elsif INIT_SEQ_B3 = '0' and INIT_CARRIER_B3 /= ZERO_CNT then
						FINAL_CARRIER_B3 <= INIT_CARRIER_B3 + '1';
					end if;
				end if;

				if EMIF_ADDR = "000010100111" and EM1CS2n = '0' and EM1WEn = '0' then
					HALF_CNT	<= EMIF1_DATA(13 downto 0);
					SEQ1_MAX <= HALF_CNT - '1';
				end if;
			
			end if;			
		end process;
		
		CARRIER_A1 : process(OP_CLK, cnt_A1_seq, cnt_A1_value, EMIF_ADDR, EM1CS2n, EM1WEn, INIT_CARRIER_A1, INIT_SEQ_A1) 
		begin
				if EMIF_ADDR = "000010100000" and EM1CS2n = '0' and EM1WEn = '0' then						
					cnt_A1_value <= INIT_CARRIER_A1;					
					cnt_A1_seq <= INIT_SEQ_A1;
				elsif OP_CLK'event and OP_CLK = '1' then
					if(cnt_A1_seq = SEQ1) then
						if INIT_SEQ_A1 = '0' and INIT_CARRIER_A1 = HALF_CNT then
							if cnt_A1_value = FINAL_CARRIER_A1 then
								cnt_A1_value <= FINAL_CARRIER_A1;
							else
								if(cnt_A1_value = SEQ1_MAX) then    
									cnt_A1_seq <= SEQ0;
									cnt_A1_value <= cnt_A1_value + '1';
								else
									cnt_A1_value <= cnt_A1_value + '1';
								end if;
							end if;
						elsif INIT_SEQ_A1 = '1' and INIT_CARRIER_A1 /= ZERO_CNT then 
							if cnt_A1_value = FINAL_CARRIER_A1 then
								cnt_A1_value <= FINAL_CARRIER_A1;
							else
								if(cnt_A1_value = SEQ1_MAX) then    
									cnt_A1_seq <= SEQ0;
									cnt_A1_value <= cnt_A1_value + '1';
								else
									cnt_A1_value <= cnt_A1_value + '1';
								end if;
							end if;
						else
							if(cnt_A1_value = SEQ1_MAX) then    
								cnt_A1_seq <= SEQ0;
								cnt_A1_value <= cnt_A1_value + '1';
							else
								cnt_A1_value <= cnt_A1_value + '1';
							end if;
						end if;
					elsif(cnt_A1_seq = SEQ0) then
						if INIT_SEQ_A1 = '1' and INIT_CARRIER_A1 = ZERO_CNT then
							if cnt_A1_value = FINAL_CARRIER_A1 then
								cnt_A1_value <= FINAL_CARRIER_A1;
							else
							--	if(cnt_A1_value = SEQ0_MIN) then
							--		cnt_A1_seq <= SEQ1;
							--		cnt_A1_value <= cnt_A1_value - '1';
							--	else
									cnt_A1_value <= cnt_A1_value - '1';
							--	end if;	
							end if;
						elsif INIT_SEQ_A1 = '0' and INIT_CARRIER_A1 /= ZERO_CNT then						
							if cnt_A1_value = FINAL_CARRIER_A1 then
								cnt_A1_value <= FINAL_CARRIER_A1;
							else
								if(cnt_A1_value = SEQ0_MIN) then
									cnt_A1_seq <= SEQ1;
									cnt_A1_value <= cnt_A1_value - '1';
								else
									cnt_A1_value <= cnt_A1_value - '1';
								end if;	
							end if;							
						else
							if(cnt_A1_value = SEQ0_MIN) then
								cnt_A1_seq <= SEQ1;
								cnt_A1_value <= cnt_A1_value - '1';
							else
								cnt_A1_value <= cnt_A1_value - '1';
							end if;	
						end if;
					end if;					
				end if;
		
			CNT_A1_OUT <= cnt_A1_value;
			SEQ_A1_OUT <= cnt_A1_seq;
		end process;		
				
		CARRIER_A2 : process(OP_CLK, cnt_A2_seq, cnt_A2_value, EMIF_ADDR, EM1CS2n, EM1WEn, INIT_CARRIER_A2, INIT_SEQ_A2) 
		begin
				if EMIF_ADDR = "000010100000" and EM1CS2n = '0' and EM1WEn = '0' then 							
					cnt_A2_value <= INIT_CARRIER_A2;					
					cnt_A2_seq <= INIT_SEQ_A2;
				elsif OP_CLK'event and OP_CLK = '1' then
					if(cnt_A2_seq = SEQ1) then
						if INIT_SEQ_A2 = '0' and INIT_CARRIER_A2 = HALF_CNT then
							if cnt_A2_value = FINAL_CARRIER_A2 then
								cnt_A2_value <= FINAL_CARRIER_A2;
							else
								if(cnt_A2_value = SEQ1_MAX) then    
									cnt_A2_seq <= SEQ0;
									cnt_A2_value <= cnt_A2_value + '1';
								else
									cnt_A2_value <= cnt_A2_value + '1';
								end if;
							end if;
						elsif INIT_SEQ_A2 = '1' and INIT_CARRIER_A2 /= ZERO_CNT then 
							if cnt_A2_value = FINAL_CARRIER_A2 then
								cnt_A2_value <= FINAL_CARRIER_A2;
							else
								if(cnt_A2_value = SEQ1_MAX) then    
									cnt_A2_seq <= SEQ0;
									cnt_A2_value <= cnt_A2_value + '1';
								else
									cnt_A2_value <= cnt_A2_value + '1';
								end if;
							end if;
						else
							if(cnt_A2_value = SEQ1_MAX) then    
								cnt_A2_seq <= SEQ0;
								cnt_A2_value <= cnt_A2_value + '1';
							else
								cnt_A2_value <= cnt_A2_value + '1';
							end if;
						end if;
					elsif(cnt_A2_seq = SEQ0) then
						if INIT_SEQ_A2 = '1' and INIT_CARRIER_A2 = ZERO_CNT then
							if cnt_A2_value = FINAL_CARRIER_A2 then
								cnt_A2_value <= FINAL_CARRIER_A2;
							else
							--	if(cnt_A2_value = SEQ0_MIN) then
							--		cnt_A2_seq <= SEQ1;
							--		cnt_A2_value <= cnt_A2_value - '1';
							--	else
									cnt_A2_value <= cnt_A2_value - '1';
							--	end if;	
							end if;
						elsif INIT_SEQ_A2 = '0' and INIT_CARRIER_A2 /= ZERO_CNT then						
							if cnt_A2_value = FINAL_CARRIER_A2 then
								cnt_A2_value <= FINAL_CARRIER_A2;
							else
								if(cnt_A2_value = SEQ0_MIN) then
									cnt_A2_seq <= SEQ1;
									cnt_A2_value <= cnt_A2_value - '1';
								else
									cnt_A2_value <= cnt_A2_value - '1';
								end if;	
							end if;							
						else
							if(cnt_A2_value = SEQ0_MIN) then
								cnt_A2_seq <= SEQ1;
								cnt_A2_value <= cnt_A2_value - '1';
							else
								cnt_A2_value <= cnt_A2_value - '1';
							end if;	
						end if;
					end if;					
				end if;
		
			CNT_A2_OUT <= cnt_A2_value;
			SEQ_A2_OUT <= cnt_A2_seq;
		end process;
		
		CARRIER_A3 : process(OP_CLK, cnt_A3_seq, cnt_A3_value, EMIF_ADDR, EM1CS2n, EM1WEn, INIT_CARRIER_A3, INIT_SEQ_A3) 
		begin
				if EMIF_ADDR = "000010100000" and EM1CS2n = '0' and EM1WEn = '0' then							
					cnt_A3_value <= INIT_CARRIER_A3;					
					cnt_A3_seq <= INIT_SEQ_A3;
				elsif OP_CLK'event and OP_CLK = '1' then
					if(cnt_A3_seq = SEQ1) then
						if INIT_SEQ_A3 = '0' and INIT_CARRIER_A3 = HALF_CNT then
							if cnt_A3_value = FINAL_CARRIER_A3 then
								cnt_A3_value <= FINAL_CARRIER_A3;
							else
								if(cnt_A3_value = SEQ1_MAX) then    
									cnt_A3_seq <= SEQ0;
									cnt_A3_value <= cnt_A3_value + '1';
								else
									cnt_A3_value <= cnt_A3_value + '1';
								end if;
							end if;
						elsif INIT_SEQ_A3 = '1' and INIT_CARRIER_A3 /= ZERO_CNT then 
							if cnt_A3_value = FINAL_CARRIER_A3 then
								cnt_A3_value <= FINAL_CARRIER_A3;
							else
								if(cnt_A3_value = SEQ1_MAX) then    
									cnt_A3_seq <= SEQ0;
									cnt_A3_value <= cnt_A3_value + '1';
								else
									cnt_A3_value <= cnt_A3_value + '1';
								end if;
							end if;
						else
							if(cnt_A3_value = SEQ1_MAX) then    
								cnt_A3_seq <= SEQ0;
								cnt_A3_value <= cnt_A3_value + '1';
							else
								cnt_A3_value <= cnt_A3_value + '1';
							end if;
						end if;
					elsif(cnt_A3_seq = SEQ0) then
						if INIT_SEQ_A3 = '1' and INIT_CARRIER_A3 = ZERO_CNT then
							if cnt_A3_value = FINAL_CARRIER_A3 then
								cnt_A3_value <= FINAL_CARRIER_A3;
							else
							--	if(cnt_A3_value = SEQ0_MIN) then
							--		cnt_A3_seq <= SEQ1;
							--		cnt_A3_value <= cnt_A3_value - '1';
							--	else
									cnt_A3_value <= cnt_A3_value - '1';
							--	end if;	
							end if;
						elsif INIT_SEQ_A3 = '0' and INIT_CARRIER_A3 /= ZERO_CNT then						
							if cnt_A3_value = FINAL_CARRIER_A3 then
								cnt_A3_value <= FINAL_CARRIER_A3;
							else
								if(cnt_A3_value = SEQ0_MIN) then
									cnt_A3_seq <= SEQ1;
									cnt_A3_value <= cnt_A3_value - '1';
								else
									cnt_A3_value <= cnt_A3_value - '1';
								end if;	
							end if;							
						else
							if(cnt_A3_value = SEQ0_MIN) then
								cnt_A3_seq <= SEQ1;
								cnt_A3_value <= cnt_A3_value - '1';
							else
								cnt_A3_value <= cnt_A3_value - '1';
							end if;	
						end if;
					end if;					
				end if;
		
			CNT_A3_OUT <= cnt_A3_value;
			SEQ_A3_OUT <= cnt_A3_seq;
		end process;
		
		CARRIER_B1 : process(OP_CLK, cnt_B1_seq, cnt_B1_value, EMIF_ADDR, EM1CS2n, EM1WEn, INIT_CARRIER_B1, INIT_SEQ_B1) 
		begin
				if EMIF_ADDR = "000010100000" and EM1CS2n = '0' and EM1WEn = '0' then							
					cnt_B1_value <= INIT_CARRIER_B1;					
					cnt_B1_seq <= INIT_SEQ_B1;
				elsif OP_CLK'event and OP_CLK = '1' then
					if(cnt_B1_seq = SEQ1) then
						if INIT_SEQ_B1 = '0' and INIT_CARRIER_B1 = HALF_CNT then
							if cnt_B1_value = FINAL_CARRIER_B1 then
								cnt_B1_value <= FINAL_CARRIER_B1;
							else
								if(cnt_B1_value = SEQ1_MAX) then    
									cnt_B1_seq <= SEQ0;
									cnt_B1_value <= cnt_B1_value + '1';
								else
									cnt_B1_value <= cnt_B1_value + '1';
								end if;
							end if;
						elsif INIT_SEQ_B1 = '1' and INIT_CARRIER_B1 /= ZERO_CNT then 
							if cnt_B1_value = FINAL_CARRIER_B1 then
								cnt_B1_value <= FINAL_CARRIER_B1;
							else
								if(cnt_B1_value = SEQ1_MAX) then    
									cnt_B1_seq <= SEQ0;
									cnt_B1_value <= cnt_B1_value + '1';
								else
									cnt_B1_value <= cnt_B1_value + '1';
								end if;
							end if;
						else
							if(cnt_B1_value = SEQ1_MAX) then    
								cnt_B1_seq <= SEQ0;
								cnt_B1_value <= cnt_B1_value + '1';
							else
								cnt_B1_value <= cnt_B1_value + '1';
							end if;
						end if;
					elsif(cnt_B1_seq = SEQ0) then
						if INIT_SEQ_B1 = '1' and INIT_CARRIER_B1 = ZERO_CNT then
							if cnt_B1_value = FINAL_CARRIER_B1 then
								cnt_B1_value <= FINAL_CARRIER_B1;
							else
							--	if(cnt_B1_value = SEQ0_MIN) then
							--		cnt_B1_seq <= SEQ1;
							--		cnt_B1_value <= cnt_B1_value - '1';
							--	else
									cnt_B1_value <= cnt_B1_value - '1';
							--	end if;	
							end if;
						elsif INIT_SEQ_B1 = '0' and INIT_CARRIER_B1 /= ZERO_CNT then						
							if cnt_B1_value = FINAL_CARRIER_B1 then
								cnt_B1_value <= FINAL_CARRIER_B1;
							else
								if(cnt_B1_value = SEQ0_MIN) then
									cnt_B1_seq <= SEQ1;
									cnt_B1_value <= cnt_B1_value - '1';
								else
									cnt_B1_value <= cnt_B1_value - '1';
								end if;	
							end if;							
						else
							if(cnt_B1_value = SEQ0_MIN) then
								cnt_B1_seq <= SEQ1;
								cnt_B1_value <= cnt_B1_value - '1';
							else
								cnt_B1_value <= cnt_B1_value - '1';
							end if;	
						end if;
					end if;					
				end if;
		
			CNT_B1_OUT <= cnt_B1_value;
			SEQ_B1_OUT <= cnt_B1_seq;
		end process;
		
		CARRIER_B2 : process(OP_CLK, cnt_B2_seq, cnt_B2_value, EMIF_ADDR, EM1CS2n, EM1WEn, INIT_CARRIER_B2, INIT_SEQ_B2) 
		begin
				if EMIF_ADDR = "000010100000" and EM1CS2n = '0' and EM1WEn = '0' then 							
					cnt_B2_value <= INIT_CARRIER_B2;					
					cnt_B2_seq <= INIT_SEQ_B2;
				elsif OP_CLK'event and OP_CLK = '1' then
					if(cnt_B2_seq = SEQ1) then
						if INIT_SEQ_B2 = '0' and INIT_CARRIER_B2 = HALF_CNT then
							if cnt_B2_value = FINAL_CARRIER_B2 then
								cnt_B2_value <= FINAL_CARRIER_B2;
							else
								if(cnt_B2_value = SEQ1_MAX) then    
									cnt_B2_seq <= SEQ0;
									cnt_B2_value <= cnt_B2_value + '1';
								else
									cnt_B2_value <= cnt_B2_value + '1';
								end if;
							end if;
						elsif INIT_SEQ_B2 = '1' and INIT_CARRIER_B2 /= ZERO_CNT then 
							if cnt_B2_value = FINAL_CARRIER_B2 then
								cnt_B2_value <= FINAL_CARRIER_B2;
							else
								if(cnt_B2_value = SEQ1_MAX) then    
									cnt_B2_seq <= SEQ0;
									cnt_B2_value <= cnt_B2_value + '1';
								else
									cnt_B2_value <= cnt_B2_value + '1';
								end if;
							end if;
						else
							if(cnt_B2_value = SEQ1_MAX) then    
								cnt_B2_seq <= SEQ0;
								cnt_B2_value <= cnt_B2_value + '1';
							else
								cnt_B2_value <= cnt_B2_value + '1';
							end if;
						end if;
					elsif(cnt_B2_seq = SEQ0) then
						if INIT_SEQ_B2 = '1' and INIT_CARRIER_B2 = ZERO_CNT then
							if cnt_B2_value = FINAL_CARRIER_B2 then
								cnt_B2_value <= FINAL_CARRIER_B2;
							else
							--	if(cnt_B2_value = SEQ0_MIN) then
							--		cnt_B2_seq <= SEQ1;
							--		cnt_B2_value <= cnt_B2_value - '1';
							--	else
									cnt_B2_value <= cnt_B2_value - '1';
							--	end if;	
							end if;
						elsif INIT_SEQ_B2 = '0' and INIT_CARRIER_B2 /= ZERO_CNT then						
							if cnt_B2_value = FINAL_CARRIER_B2 then
								cnt_B2_value <= FINAL_CARRIER_B2;
							else
								if(cnt_B2_value = SEQ0_MIN) then
									cnt_B2_seq <= SEQ1;
									cnt_B2_value <= cnt_B2_value - '1';
								else
									cnt_B2_value <= cnt_B2_value - '1';
								end if;	
							end if;							
						else
							if(cnt_B2_value = SEQ0_MIN) then
								cnt_B2_seq <= SEQ1;
								cnt_B2_value <= cnt_B2_value - '1';
							else
								cnt_B2_value <= cnt_B2_value - '1';
							end if;	
						end if;
					end if;					
				end if;
		
			CNT_B2_OUT <= cnt_B2_value;
			SEQ_B2_OUT <= cnt_B2_seq;
		end process;
		
		CARRIER_B3 : process(OP_CLK, cnt_B3_seq, cnt_B3_value, EMIF_ADDR, EM1CS2n, EM1WEn, INIT_CARRIER_B3, INIT_SEQ_B3) 
		begin
				if EMIF_ADDR = "000010100000" and EM1CS2n = '0' and EM1WEn = '0' then							
					cnt_B3_value <= INIT_CARRIER_B3;					
					cnt_B3_seq <= INIT_SEQ_B3;
				elsif OP_CLK'event and OP_CLK = '1' then
					if(cnt_B3_seq = SEQ1) then
						if INIT_SEQ_B3 = '0' and INIT_CARRIER_B3 = HALF_CNT then
							if cnt_B3_value = FINAL_CARRIER_B3 then
								cnt_B3_value <= FINAL_CARRIER_B3;
							else
								if(cnt_B3_value = SEQ1_MAX) then    
									cnt_B3_seq <= SEQ0;
									cnt_B3_value <= cnt_B3_value + '1';
								else
									cnt_B3_value <= cnt_B3_value + '1';
								end if;
							end if;
						elsif INIT_SEQ_B3 = '1' and INIT_CARRIER_B3 /= ZERO_CNT then 
							if cnt_B3_value = FINAL_CARRIER_B3 then
								cnt_B3_value <= FINAL_CARRIER_B3;
							else
								if(cnt_B3_value = SEQ1_MAX) then    
									cnt_B3_seq <= SEQ0;
									cnt_B3_value <= cnt_B3_value + '1';
								else
									cnt_B3_value <= cnt_B3_value + '1';
								end if;
							end if;
						else
							if(cnt_B3_value = SEQ1_MAX) then    
								cnt_B3_seq <= SEQ0;
								cnt_B3_value <= cnt_B3_value + '1';
							else
								cnt_B3_value <= cnt_B3_value + '1';
							end if;
						end if;
					elsif(cnt_B3_seq = SEQ0) then
						if INIT_SEQ_B3 = '1' and INIT_CARRIER_B3 = ZERO_CNT then
							if cnt_B3_value = FINAL_CARRIER_B3 then
								cnt_B3_value <= FINAL_CARRIER_B3;
							else
							--	if(cnt_B3_value = SEQ0_MIN) then
							--		cnt_B3_seq <= SEQ1;
							--		cnt_B3_value <= cnt_B3_value - '1';
							--	else
									cnt_B3_value <= cnt_B3_value - '1';
							--	end if;	
							end if;
						elsif INIT_SEQ_B3 = '0' and INIT_CARRIER_B3 /= ZERO_CNT then						
							if cnt_B3_value = FINAL_CARRIER_B3 then
								cnt_B3_value <= FINAL_CARRIER_B3;
							else
								if(cnt_B3_value = SEQ0_MIN) then
									cnt_B3_seq <= SEQ1;
									cnt_B3_value <= cnt_B3_value - '1';
								else
									cnt_B3_value <= cnt_B3_value - '1';
								end if;	
							end if;							
						else
							if(cnt_B3_value = SEQ0_MIN) then
								cnt_B3_seq <= SEQ1;
								cnt_B3_value <= cnt_B3_value - '1';
							else
								cnt_B3_value <= cnt_B3_value - '1';
							end if;	
						end if;
					end if;					
				end if;
		
			CNT_B3_OUT <= cnt_B3_value;
			SEQ_B3_OUT <= cnt_B3_seq;
		end process;
end arch;