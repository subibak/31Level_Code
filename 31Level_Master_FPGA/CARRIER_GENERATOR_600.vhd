library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;


entity CARRIER_GENERATOR_600 is

	port(
			OP_CLK						:	in std_logic;
				
			EMIF_ADDR					:	in std_logic_vector(11 downto 0);
			EM1CS2n						:	in std_logic;
			EM1WEn						: 	in std_logic;	
			EMIF1_DATA					:  in std_logic_vector(15 downto 0);
			
			CNT_A1_OUT 					:	out std_logic_vector(15 downto 0);
			SEQ_A1_OUT					:  out std_logic;
			SYNC							:  out std_logic
		);
	

end CARRIER_GENERATOR_600;

architecture arch of CARRIER_GENERATOR_600 is

	signal HALF_CNT				:		std_logic_vector(15 downto 0)	:=	"0111010100110000";	--------  30000 count  -- 0100111000100000 20000 count
	signal SEQ1_MAX				:		std_logic_vector(15 downto 0)	:=	"0111010100110000";	--------  30000 count  -- 0010011100010000 10000 count
	constant SEQ0_MIN				:		std_logic_vector(15 downto 0)	:=	"0000000000000001"; --------     1 count
	constant ZERO_CNT				:		std_logic_vector(15 downto 0)	:=	"0000000000000000"; --------     0 count
	constant SEQ0					:		std_logic  := '0';
	constant SEQ1					:		std_logic  := '1';
	
	signal INIT_CARRIER_A1		:		std_logic_vector(15 downto 0) := "0000000000000000"; --------  Carrier 1 (initial : 0, seq : 1)

	signal INIT_SEQ_A1			:		std_logic := '1';

	signal FINAL_CARRIER_A1		:		std_logic_vector(15 downto 0) := "0000000000000001";

	signal cnt_A1_value			:		std_logic_vector(15 downto 0) := "0000000000000000";
	
	signal cnt_A1_seq				: 		std_logic := '1';
	signal SYNC_reg				:		std_logic := '0'; 
	
	type STATETYPE is (IDLE, INIT, UP_DOWN);
	signal  A1_State			:	STATETYPE := IDLE;
	signal  A1_Next_State	: 	STATETYPE := IDLE;
	
	signal Flag_cnt_up			:		std_logic := '0';
   signal Flag_cnt_down			:		std_logic := '0';
	signal Flag_init_load 		:		std_logic := '0';
	signal Flag_seq1_half 		:		std_logic := '0';
	signal Flag_seq0_half 		:		std_logic := '0';

begin

		
		CARRIER_A1 : process(OP_CLK, cnt_A1_seq, cnt_A1_value, EMIF_ADDR, EM1CS2n, EM1WEn, INIT_CARRIER_A1, INIT_SEQ_A1) 
		begin
				if EMIF_ADDR = "000000000010" and EM1CS2n = '0' and EM1WEn = '0' then						
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
								if(cnt_A1_value = SEQ0_MIN) then
									cnt_A1_seq <= SEQ1;
									cnt_A1_value <= cnt_A1_value - '1';
								else
									cnt_A1_value <= cnt_A1_value - '1';
								end if;	
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
				
				
		Sync_generator : process(OP_CLK, cnt_A1_value, cnt_A1_seq)
		begin
		
			SYNC <= SYNC_reg;
			
			if OP_CLK'event and OP_CLK = '1' then
				if((cnt_A1_value >= "0000000000000000") and (cnt_A1_value < "0010011100010000") and (cnt_A1_seq = SEQ1))  then -- 0 <=  < 10000
					SYNC_reg <= '1';
				elsif((cnt_A1_value >= "0010011100010000") and (cnt_A1_value < "0100111000100000") and (cnt_A1_seq = SEQ1))  then  -- 10000 <=  < 20000
					SYNC_reg <= '0';
				elsif((cnt_A1_value >= "0100111000100000") and (cnt_A1_value < "0111010100110000") and (cnt_A1_seq = SEQ1))  then  -- 20000 <=  < 30000
					SYNC_reg <= '1';
				elsif((cnt_A1_value > "0100111000100000") and (cnt_A1_value <= "0111010100110000") and (cnt_A1_seq = SEQ0))  then  -- 20000 <   <= 30000
					SYNC_reg <= '0';
				elsif((cnt_A1_value > "0010011100010000") and (cnt_A1_value <= "0100111000100000") and (cnt_A1_seq = SEQ0))  then  -- 10000 <   <= 20000
					SYNC_reg <= '1';
				elsif((cnt_A1_value > "0000000000000000") and (cnt_A1_value <= "0010011100010000") and (cnt_A1_seq = SEQ0))  then  -- 0 <   <= 10000
					SYNC_reg <= '0';
				end if;
			end if;
		
		end process;
		
end arch;