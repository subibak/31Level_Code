-- Carrier를 만들어 내는 블럭

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;


entity PSC_10_Counter is
port(
			XCLK					:	in std_logic;  -- 37.5MHz Clock
			PWM_CNT_EN			:  in std_logic;  -- Chip Select Signal
	
			CNT_1_OUT 			:	buffer std_logic_vector(15 downto 0);
			SEQ_1_OUT			:  out std_logic;
			CNT_1_FLAG_OUT		:	out std_logic;
			
			CNT_2_OUT 			:	buffer std_logic_vector(15 downto 0);
			SEQ_2_OUT			:  out std_logic;
			CNT_2_FLAG_OUT		:	out std_logic;
						
			CNT_3_OUT 			:	buffer std_logic_vector(15 downto 0);
			SEQ_3_OUT			:  out std_logic;
			CNT_3_FLAG_OUT		:	out std_logic;
						
						
			CNT_4_OUT 			:	buffer std_logic_vector(15 downto 0);
			SEQ_4_OUT			:  out std_logic;
			CNT_4_FLAG_OUT		:	out std_logic;
		
			CNT_5_OUT 			:	buffer std_logic_vector(15 downto 0);
			SEQ_5_OUT			:  out std_logic;
			CNT_5_FLAG_OUT		:	out std_logic;
			
			CNT_6_OUT 			:	buffer std_logic_vector(15 downto 0);
			SEQ_6_OUT			:  out std_logic;
			CNT_6_FLAG_OUT		:	out std_logic;
						
					
			CNT_7_OUT 			:	buffer std_logic_vector(15 downto 0);
			SEQ_7_OUT			:  out std_logic;
			CNT_7_FLAG_OUT		:	out std_logic;
			
			CNT_8_OUT 			:	buffer std_logic_vector(15 downto 0);
			SEQ_8_OUT			:  out std_logic;
			CNT_8_FLAG_OUT		:	out std_logic;
			
			
			CNT_9_OUT 			:	buffer std_logic_vector(15 downto 0);
			SEQ_9_OUT			:  out std_logic;
			CNT_9_FLAG_OUT		:	out std_logic;
			
			CNT_10_OUT 			:	buffer std_logic_vector(15 downto 0);
			SEQ_10_OUT			:  out std_logic;
			CNT_10_FLAG_OUT	:	out std_logic
								
	);
end PSC_10_Counter;


architecture arch of PSC_10_Counter is

	signal cnt_reg					:		std_logic_vector(1 downto 0);
	
	constant HALF_CNT				:		std_logic_vector(15 downto 0)	:=	"0000111010100110";	--------  3750 count
	constant ZERO_CNT				:		std_logic_vector(15 downto 0)	:=	"0000000000000000";  --------     0 count
	constant SEQ0					:		std_logic                     := '0'; -- Down Count Mode
	constant SEQ1					:		std_logic                     := '1'; -- Up   Count Mode
	
	constant INITIAL_CARRIER_1	:		std_logic_vector(15 downto 0) := "0000000000000000";  --------  Carrier 1 (initial :    0, seq : 1)
	constant INITIAL_CARRIER_2	:		std_logic_vector(15 downto 0) := "0000000000000000";
	constant INITIAL_CARRIER_3	:		std_logic_vector(15 downto 0) := "0000000000000000";
	constant INITIAL_CARRIER_4	:		std_logic_vector(15 downto 0) := "0000000000000000";
	constant INITIAL_CARRIER_5	:		std_logic_vector(15 downto 0) := "0000000000000000";
	constant INITIAL_CARRIER_6	:		std_logic_vector(15 downto 0) := "0000000000000000";
	constant INITIAL_CARRIER_7	:		std_logic_vector(15 downto 0) := "0000000000000000";
	constant INITIAL_CARRIER_8	:		std_logic_vector(15 downto 0) := "0000000000000000";
	constant INITIAL_CARRIER_9	:		std_logic_vector(15 downto 0) := "0000000000000000";
	constant INITIAL_CARRIER_10	:		std_logic_vector(15 downto 0) := "0000000000000000";
	
	-- 동기신호의 어긋남으로 인한 캐리어 파형 조절 (Count 마지막 값 설정 필요)
	constant FINAL_CARRIER_1   :     std_logic_vector(15 downto 0) := "0000000000000001";  --------  Carrier 1 (final :    1, seq : 0)
	constant FINAL_CARRIER_2   :     std_logic_vector(15 downto 0) := "0000000000000001";
	constant FINAL_CARRIER_3   :     std_logic_vector(15 downto 0) := "0000000000000001";
	constant FINAL_CARRIER_4   :     std_logic_vector(15 downto 0) := "0000000000000001";
	constant FINAL_CARRIER_5   :     std_logic_vector(15 downto 0) := "0000000000000001";
	constant FINAL_CARRIER_6   :     std_logic_vector(15 downto 0) := "0000000000000001";
	constant FINAL_CARRIER_7   :     std_logic_vector(15 downto 0) := "0000000000000001";
	constant FINAL_CARRIER_8   :     std_logic_vector(15 downto 0) := "0000000000000001";
	constant FINAL_CARRIER_9   :     std_logic_vector(15 downto 0) := "0000000000000001";
	constant FINAL_CARRIER_10   :     std_logic_vector(15 downto 0) := "0000000000000001";
	
	
	signal cnt_1_value			:		std_logic_vector(15 downto 0);
	signal cnt_2_value			:		std_logic_vector(15 downto 0);
	signal cnt_3_value			:		std_logic_vector(15 downto 0);
	signal cnt_4_value			:		std_logic_vector(15 downto 0);
	signal cnt_5_value			:		std_logic_vector(15 downto 0);
	signal cnt_6_value			:		std_logic_vector(15 downto 0);
	signal cnt_7_value			:		std_logic_vector(15 downto 0);
	signal cnt_8_value			:		std_logic_vector(15 downto 0);
	signal cnt_9_value			:		std_logic_vector(15 downto 0);
	signal cnt_10_value			:		std_logic_vector(15 downto 0);
	
	signal cnt_1_seq				: 		std_logic;
	signal cnt_2_seq				: 		std_logic;
	signal cnt_3_seq				: 		std_logic;
	signal cnt_4_seq				: 		std_logic;
	signal cnt_5_seq				: 		std_logic;
	signal cnt_6_seq				: 		std_logic;
	signal cnt_7_seq				: 		std_logic;
	signal cnt_8_seq				: 		std_logic;
	signal cnt_9_seq				: 		std_logic;
	signal cnt_10_seq				: 		std_logic;	
	
	signal cnt_1_flag				: 		std_logic;
	signal cnt_2_flag				: 		std_logic;
	signal cnt_3_flag				: 		std_logic;
	signal cnt_4_flag				: 		std_logic;
	signal cnt_5_flag				: 		std_logic;
	signal cnt_6_flag				: 		std_logic;
	signal cnt_7_flag				: 		std_logic;
	signal cnt_8_flag				: 		std_logic;
	signal cnt_9_flag				: 		std_logic;
	signal cnt_10_flag				: 		std_logic;
	
begin
 	-- 37.5MHz의 클럭을 받아서 클럭이 매번 발생할 때 마다 외부에서(DSP) 받은 칩 셀렉터 신호를 2bit 의 레지스터에 저장&갱신
	-- 매 클럭 발생할 때마다 2bit 의 레지스터 최하위 비트에 저장됨 
	-- 그리고 다음 클럭 발생시 이전에 저장되었던 값을 상위 비트에 저장하면서 하위비트에는 새로운 값으로 갱신 
		process(XCLK)
		begin
			if(XCLK'event and XCLK = '1') then
				cnt_reg <= cnt_reg(0) & PWM_CNT_EN;
			end if;
		end process;
	
	--	37.5MHz의 클럭으로 정해진 초기값에 따라 업 또 다운 카운터를 진행 
	-- seq = 1 일 때는 업 카운터, seq = 0 일 때는 다운 카운터를 실시함
	-- 업 다운 카운터를 통해 최종적으로 카운터가 0에 도달하면 카운터 플래그 발생, 이 플래그는 이 후에 PWM_COMPARATOR 블럭에서 시컨스를 초기화 해주는 역활을 함
		process(XCLK, cnt_reg, CNT_1_OUT) 					--------  Carrier 1
		begin
			if (XCLK'event and XCLK = '1') then
				cnt_1_flag <= '1';
				if (cnt_reg = "10") then    							
					cnt_1_value <= INITIAL_CARRIER_1;     -- Counting Data Load				
					cnt_1_seq <= SEQ1;                    -- Up Count Order
					cnt_1_flag <= '1';				
					
				else -- cnt_reg = "00" & "01" & "11" 상태에서 계속적인 카운팅 실시
				
					if (cnt_1_seq = SEQ1) then             -- Up Count State
						cnt_1_value <= cnt_1_value + '1';  -- Up Count  
						
						if (cnt_1_value = HALF_CNT) then    -- Count == 7500
							cnt_1_seq <= SEQ0;              -- Down Count Order
						end if;
						
					elsif (cnt_1_seq = SEQ0) then          -- Down Count State
						
						if (cnt_1_value = FINAL_CARRIER_1) then
							cnt_1_value <= FINAL_CARRIER_1;
						else
							cnt_1_value <= cnt_1_value - '1';  -- Down Count
						
					--	if (cnt_1_value = ZERO_CNT) then    -- Zero Count State
						--	cnt_1_seq <= SEQ1;              -- Up Count Order
						--   cnt_1_flag <= '0';              -- Count Flag Initialization
				   	--end if;
							
						end if;
					end if;					
				end if;
			end if;
			
			CNT_1_OUT <= cnt_1_value;
			SEQ_1_OUT <= cnt_1_seq;
			CNT_1_FLAG_OUT <= cnt_1_flag;
		end process;
		
		process(XCLK, cnt_reg, CNT_2_OUT) 					--------  Carrier 1
		begin
			if (XCLK'event and XCLK = '1') then
				cnt_2_flag <= '1';
				if (cnt_reg = "10") then    							
					cnt_2_value <= INITIAL_CARRIER_2;     -- Counting Data Load				
					cnt_2_seq <= SEQ1;                    -- Up Count Order
					cnt_2_flag <= '1';				
					
				else -- cnt_reg = "00" & "01" & "11" 상태에서 계속적인 카운팅 실시
				
					if (cnt_2_seq = SEQ1) then             -- Up Count State
						cnt_2_value <= cnt_2_value + '1';  -- Up Count  
						
						if (cnt_2_value = HALF_CNT) then    -- Count == 7500
							cnt_2_seq <= SEQ0;              -- Down Count Order
						end if;
						
					elsif (cnt_2_seq = SEQ0) then          -- Down Count State
						
						if (cnt_2_value = FINAL_CARRIER_2) then
							cnt_2_value <= FINAL_CARRIER_2;
						else
							cnt_2_value <= cnt_2_value - '1';  -- Down Count
						
					--	if (cnt_1_value = ZERO_CNT) then    -- Zero Count State
						--	cnt_1_seq <= SEQ1;              -- Up Count Order
						--   cnt_1_flag <= '0';              -- Count Flag Initialization
				   	--end if;
							
						end if;
					end if;					
				end if;
			end if;
			
			CNT_2_OUT <= cnt_2_value;
			SEQ_2_OUT <= cnt_2_seq;
			CNT_2_FLAG_OUT <= cnt_2_flag;
		end process;
		
		
		process(XCLK, cnt_reg, CNT_3_OUT) 					--------  Carrier 1
		begin
			if (XCLK'event and XCLK = '1') then
				cnt_3_flag <= '1';
				if (cnt_reg = "10") then    							
					cnt_3_value <= INITIAL_CARRIER_3;     -- Counting Data Load				
					cnt_3_seq <= SEQ1;                    -- Up Count Order
					cnt_3_flag <= '1';				
					
				else -- cnt_reg = "00" & "01" & "11" 상태에서 계속적인 카운팅 실시
				
					if (cnt_3_seq = SEQ1) then             -- Up Count State
						cnt_3_value <= cnt_3_value + '1';  -- Up Count  
						
						if (cnt_3_value = HALF_CNT) then    -- Count == 7500
							cnt_3_seq <= SEQ0;              -- Down Count Order
						end if;
						
					elsif (cnt_3_seq = SEQ0) then          -- Down Count State
						
						if (cnt_3_value = FINAL_CARRIER_3) then
							cnt_3_value <= FINAL_CARRIER_3;
						else
							cnt_3_value <= cnt_3_value - '1';  -- Down Count
						
					--	if (cnt_1_value = ZERO_CNT) then    -- Zero Count State
						--	cnt_1_seq <= SEQ1;              -- Up Count Order
						--   cnt_1_flag <= '0';              -- Count Flag Initialization
				   	--end if;
							
						end if;
					end if;					
				end if;
			end if;
			
			CNT_3_OUT <= cnt_3_value;
			SEQ_3_OUT <= cnt_3_seq;
			CNT_3_FLAG_OUT <= cnt_3_flag;
		end process;
		
		
		process(XCLK, cnt_reg, CNT_4_OUT) 					--------  Carrier 1
		begin
			if (XCLK'event and XCLK = '1') then
				cnt_4_flag <= '1';
				if (cnt_reg = "10") then    							
					cnt_4_value <= INITIAL_CARRIER_4;     -- Counting Data Load				
					cnt_4_seq <= SEQ1;                    -- Up Count Order
					cnt_4_flag <= '1';				
					
				else -- cnt_reg = "00" & "01" & "11" 상태에서 계속적인 카운팅 실시
				
					if (cnt_4_seq = SEQ1) then             -- Up Count State
						cnt_4_value <= cnt_4_value + '1';  -- Up Count  
						
						if (cnt_4_value = HALF_CNT) then    -- Count == 7500
							cnt_4_seq <= SEQ0;              -- Down Count Order
						end if;
						
					elsif (cnt_4_seq = SEQ0) then          -- Down Count State
						
						if (cnt_4_value = FINAL_CARRIER_4) then
							cnt_4_value <= FINAL_CARRIER_4;
						else
							cnt_4_value <= cnt_4_value - '1';  -- Down Count
						
					--	if (cnt_1_value = ZERO_CNT) then    -- Zero Count State
						--	cnt_1_seq <= SEQ1;              -- Up Count Order
						--   cnt_1_flag <= '0';              -- Count Flag Initialization
				   	--end if;
							
						end if;
					end if;					
				end if;
			end if;
			
			CNT_4_OUT <= cnt_4_value;
			SEQ_4_OUT <= cnt_4_seq;
			CNT_4_FLAG_OUT <= cnt_4_flag;
		end process;
		
		
		process(XCLK, cnt_reg, CNT_5_OUT) 					--------  Carrier 1
		begin
			if (XCLK'event and XCLK = '1') then
				cnt_5_flag <= '1';
				if (cnt_reg = "10") then    							
					cnt_5_value <= INITIAL_CARRIER_5;     -- Counting Data Load				
					cnt_5_seq <= SEQ1;                    -- Up Count Order
					cnt_5_flag <= '1';				
					
				else -- cnt_reg = "00" & "01" & "11" 상태에서 계속적인 카운팅 실시
				
					if (cnt_5_seq = SEQ1) then             -- Up Count State
						cnt_5_value <= cnt_5_value + '1';  -- Up Count  
						
						if (cnt_5_value = HALF_CNT) then    -- Count == 7500
							cnt_5_seq <= SEQ0;              -- Down Count Order
						end if;
						
					elsif (cnt_5_seq = SEQ0) then          -- Down Count State
						
						if (cnt_5_value = FINAL_CARRIER_5) then
							cnt_5_value <= FINAL_CARRIER_5;
						else
							cnt_5_value <= cnt_5_value - '1';  -- Down Count
						
					--	if (cnt_1_value = ZERO_CNT) then    -- Zero Count State
						--	cnt_1_seq <= SEQ1;              -- Up Count Order
						--   cnt_1_flag <= '0';              -- Count Flag Initialization
				   	--end if;
							
						end if;
					end if;					
				end if;
			end if;
			
			CNT_5_OUT <= cnt_5_value;
			SEQ_5_OUT <= cnt_5_seq;
			CNT_5_FLAG_OUT <= cnt_5_flag;
		end process;
		
		
		process(XCLK, cnt_reg, CNT_6_OUT) 					--------  Carrier 1
		begin
			if (XCLK'event and XCLK = '1') then
				cnt_6_flag <= '1';
				if (cnt_reg = "10") then    							
					cnt_6_value <= INITIAL_CARRIER_6;     -- Counting Data Load				
					cnt_6_seq <= SEQ1;                    -- Up Count Order
					cnt_6_flag <= '1';				
					
				else -- cnt_reg = "00" & "01" & "11" 상태에서 계속적인 카운팅 실시
				
					if (cnt_6_seq = SEQ1) then             -- Up Count State
						cnt_6_value <= cnt_6_value + '1';  -- Up Count  
						
						if (cnt_6_value = HALF_CNT) then    -- Count == 7500
							cnt_6_seq <= SEQ0;              -- Down Count Order
						end if;
						
					elsif (cnt_6_seq = SEQ0) then          -- Down Count State
						
						if (cnt_6_value = FINAL_CARRIER_6) then
							cnt_6_value <= FINAL_CARRIER_6;
						else
							cnt_6_value <= cnt_6_value - '1';  -- Down Count
						
					--	if (cnt_1_value = ZERO_CNT) then    -- Zero Count State
						--	cnt_1_seq <= SEQ1;              -- Up Count Order
						--   cnt_1_flag <= '0';              -- Count Flag Initialization
				   	--end if;
							
						end if;
					end if;					
				end if;
			end if;
			
			CNT_6_OUT <= cnt_6_value;
			SEQ_6_OUT <= cnt_6_seq;
			CNT_6_FLAG_OUT <= cnt_6_flag;
		end process;
		
		
		process(XCLK, cnt_reg, CNT_7_OUT) 					--------  Carrier 1
		begin
			if (XCLK'event and XCLK = '1') then
				cnt_7_flag <= '1';
				if (cnt_reg = "10") then    							
					cnt_7_value <= INITIAL_CARRIER_7;     -- Counting Data Load				
					cnt_7_seq <= SEQ1;                    -- Up Count Order
					cnt_7_flag <= '1';				
					
				else -- cnt_reg = "00" & "01" & "11" 상태에서 계속적인 카운팅 실시
				
					if (cnt_7_seq = SEQ1) then             -- Up Count State
						cnt_7_value <= cnt_7_value + '1';  -- Up Count  
						
						if (cnt_7_value = HALF_CNT) then    -- Count == 7500
							cnt_7_seq <= SEQ0;              -- Down Count Order
						end if;
						
					elsif (cnt_7_seq = SEQ0) then          -- Down Count State
						
						if (cnt_7_value = FINAL_CARRIER_7) then
							cnt_7_value <= FINAL_CARRIER_7;
						else
							cnt_7_value <= cnt_7_value - '1';  -- Down Count
						
					--	if (cnt_1_value = ZERO_CNT) then    -- Zero Count State
						--	cnt_1_seq <= SEQ1;              -- Up Count Order
						--   cnt_1_flag <= '0';              -- Count Flag Initialization
				   	--end if;
							
						end if;
					end if;					
				end if;
			end if;
			
			CNT_7_OUT <= cnt_7_value;
			SEQ_7_OUT <= cnt_7_seq;
			CNT_7_FLAG_OUT <= cnt_7_flag;
		end process;
		
		
		process(XCLK, cnt_reg, CNT_8_OUT) 					--------  Carrier 1
		begin
			if (XCLK'event and XCLK = '1') then
				cnt_8_flag <= '1';
				if (cnt_reg = "10") then    							
					cnt_8_value <= INITIAL_CARRIER_8;     -- Counting Data Load				
					cnt_8_seq <= SEQ1;                    -- Up Count Order
					cnt_8_flag <= '1';				
					
				else -- cnt_reg = "00" & "01" & "11" 상태에서 계속적인 카운팅 실시
				
					if (cnt_8_seq = SEQ1) then             -- Up Count State
						cnt_8_value <= cnt_8_value + '1';  -- Up Count  
						
						if (cnt_8_value = HALF_CNT) then    -- Count == 7500
							cnt_8_seq <= SEQ0;              -- Down Count Order
						end if;
						
					elsif (cnt_8_seq = SEQ0) then          -- Down Count State
						
						if (cnt_8_value = FINAL_CARRIER_8) then
							cnt_8_value <= FINAL_CARRIER_8;
						else
							cnt_8_value <= cnt_8_value - '1';  -- Down Count
						
					--	if (cnt_1_value = ZERO_CNT) then    -- Zero Count State
						--	cnt_1_seq <= SEQ1;              -- Up Count Order
						--   cnt_1_flag <= '0';              -- Count Flag Initialization
				   	--end if;
							
						end if;
					end if;					
				end if;
			end if;
			
			CNT_8_OUT <= cnt_8_value;
			SEQ_8_OUT <= cnt_8_seq;
			CNT_8_FLAG_OUT <= cnt_8_flag;
		end process;
		
		
		process(XCLK, cnt_reg, CNT_9_OUT) 					--------  Carrier 1
		begin
			if (XCLK'event and XCLK = '1') then
				cnt_9_flag <= '1';
				if (cnt_reg = "10") then    							
					cnt_9_value <= INITIAL_CARRIER_1;     -- Counting Data Load				
					cnt_9_seq <= SEQ1;                    -- Up Count Order
					cnt_9_flag <= '1';				
					
				else -- cnt_reg = "00" & "01" & "11" 상태에서 계속적인 카운팅 실시
				
					if (cnt_9_seq = SEQ1) then             -- Up Count State
						cnt_9_value <= cnt_9_value + '1';  -- Up Count  
						
						if (cnt_9_value = HALF_CNT) then    -- Count == 7500
							cnt_9_seq <= SEQ0;              -- Down Count Order
						end if;
						
					elsif (cnt_9_seq = SEQ0) then          -- Down Count State
						
						if (cnt_9_value = FINAL_CARRIER_9) then
							cnt_9_value <= FINAL_CARRIER_9;
						else
							cnt_9_value <= cnt_9_value - '1';  -- Down Count
						
					--	if (cnt_1_value = ZERO_CNT) then    -- Zero Count State
						--	cnt_1_seq <= SEQ1;              -- Up Count Order
						--   cnt_1_flag <= '0';              -- Count Flag Initialization
				   	--end if;
							
						end if;
					end if;					
				end if;
			end if;
			
			CNT_9_OUT <= cnt_9_value;
			SEQ_9_OUT <= cnt_9_seq;
			CNT_9_FLAG_OUT <= cnt_9_flag;
		end process;
		
		
		process(XCLK, cnt_reg, CNT_10_OUT) 					--------  Carrier 1
		begin
			if (XCLK'event and XCLK = '1') then
				cnt_10_flag <= '1';
				if (cnt_reg = "10") then    							
					cnt_10_value <= INITIAL_CARRIER_10;     -- Counting Data Load				
					cnt_10_seq <= SEQ1;                    -- Up Count Order
					cnt_10_flag <= '1';				
					
				else -- cnt_reg = "00" & "01" & "11" 상태에서 계속적인 카운팅 실시
				
					if (cnt_10_seq = SEQ1) then             -- Up Count State
						cnt_10_value <= cnt_10_value + '1';  -- Up Count  
						
						if (cnt_10_value = HALF_CNT) then    -- Count == 7500
							cnt_10_seq <= SEQ0;              -- Down Count Order
						end if;
						
					elsif (cnt_10_seq = SEQ0) then          -- Down Count State
						
						if (cnt_10_value = FINAL_CARRIER_10) then
							cnt_10_value <= FINAL_CARRIER_10;
						else
							cnt_10_value <= cnt_10_value - '1';  -- Down Count
						
					--	if (cnt_1_value = ZERO_CNT) then    -- Zero Count State
						--	cnt_1_seq <= SEQ1;              -- Up Count Order
						--   cnt_1_flag <= '0';              -- Count Flag Initialization
				   	--end if;
							
						end if;
					end if;					
				end if;
			end if;
			
			CNT_10_OUT <= cnt_10_value;
			SEQ_10_OUT <= cnt_10_seq;
			CNT_10_FLAG_OUT <= cnt_10_flag;
		end process;		
		
		
	end arch;	
		