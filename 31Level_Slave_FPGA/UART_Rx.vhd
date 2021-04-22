------------------------------------------------------------------
-- UART Receiver example
--
-- 
-- QuantumBase Inc.
-- TEL: 032-321-0195, FAX: 032-321-0197
------------------------------------------------------------------

--==============================================Description=====================================================================
--==============================================================================================================================

-- 상위 제어기로 부터 data를 받을 때 사용, data입력은 상위 제어기에서 보낸 data UART_RxD가 버퍼를 거친 RS232_RX가 DATA 입력
-- fpga에서 dsp로 data 전달 시 external interface의 read access 를 통해 data 전달 
-- 수신 프로토콜은 main 함수 참고 
-- 1. 통신 상태가 IDLE, STARTING, RECEIVING에 따라 해당하는 동작 수행 => 아래에 1번 설명 부분 
-- 2. 각 통신 상태일 때 발생하는 조건이 어떻게 동작하는지에 대한 동작 설정 => 아래에 2번 설명 부분 
---------------------------------------------------------------------------------------------------------------------------------

Library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

entity UART_Rx is
	port ( nRst, SampleClk  : in std_logic; -- Sample clk is 8x BitClk
		   SerialIn         : in std_logic; 
		   ReadNotReadyIn   : in std_logic; -- Status bit from host processor
		   RCVDataReg       : out std_logic_vector(7 downto 0); --Host data bus
		   ReadNotReadyOut  : out std_logic; -- handshake to processor
		   Error1           : out std_logic; -- host nt ready error
		   Error2           : out std_logic;
			INT2				  : out std_logic;
			starting_time,receiving_time,shift_time,load_time,dataout_time,test : out std_logic); -- Data_in missing stop bit
end entity UART_Rx ;

architecture BEH of UART_Rx is
	constant HALFWORD       : integer := 4; -- word size/2
	constant NUMCOUNTERBITS : integer := 4;
	constant NUMSTATEBITS   : integer := 2;

	signal IncSampleCounter  : std_logic; 
	signal IncBitCounter     : std_logic; 
	signal ClrBitCounter     : std_logic;  
	signal ClrSampleCounter  : std_logic;  
	signal Shift, load       : std_logic;  
	
	signal IncHighCounter	 : std_logic;
	signal ClrHighCounter	 : std_logic;
	signal IncLowCounter	 : std_logic;
	signal ClrLowCounter	 : std_logic;


	signal RCVshftreg        : std_logic_vector(7 downto 0); 
	signal SampleCounter     : unsigned(4 downto 0); 
	signal BitCounter        : unsigned(4 downto 0);
	signal high_count		: unsigned(4 downto 0);  
	signal low_count		: unsigned(4 downto 0); 
	signal high				: std_logic;
	signal low				: std_logic; 

	Type StateType is (IDLE, STARTING, RECEIVING );
	signal State, NextState : StateType;
	
--====================== DESCRIPTION 1번 설명 ============================
--=======================================================================
begin
shift_time<=Shift;
	-- Combinational logic for the next state & comb. output
	STATECOMB: process (State, SerialIn, ReadNotReadyIn,
	                    SampleCounter, BitCounter,high_count,low_count)
	begin
		ReadNotReadyOut  <= '0';
		ClrSampleCounter <= '0';
		ClrBitCounter    <= '0';
		IncSampleCounter <= '0';
		IncBitCounter    <= '0';
		Shift            <= '0';
		Load             <= '0';
		Error1           <= '0';
		Error2           <= '0';
		ClrHighCounter <= '0';
		ClrLowCounter    <= '0';
		IncHighCounter <= '0';
		IncLowCounter    <= '0';

		case(state) is
			when IDLE =>
				if (SerialIn = '0') then
					NextState <= STARTING;
					starting_time<='1';
				else
					NextState <= IDLE;
				end if;
			when STARTING =>
				if (SerialIn = '1') then
					NextState <= IDLE;
					ClrSampleCounter <= '1';
				elsif (SampleCounter = 7) then
					NextState <= RECEIVING;
					ClrSampleCounter <= '1';
					receiving_time<='1';
				else
					NextState <= STARTING;
					IncSampleCounter <= '1';
				end if;
			when Receiving =>
				IncSampleCounter <= '1';
				if (SampleCounter /= 15 ) then
					if(SampleCounter > 8)then
						if (SampleCounter < 13) then
							if(SerialIn='1') then
								IncHighCounter<='1';
							else
								IncLowCounter<='1';
							end if;
						end if;
					end if;
					NextState <= RECEIVING;
				elsif (BitCounter /= 8) then
					NextState <= RECEIVING;
					Shift <= '1';
					--shift_time<='1';
					IncBitCounter <= '1';
					ClrSampleCounter <= '1';
					ClrHighCounter <= '1';
					ClrLowCounter <= '1';
					
					--high_count<=(others =>'0');
					--low_count<=(others =>'0');
				else
					NextState <= IDLE;
					ReadNotReadyOut <= '1';
					ClrSampleCounter <= '1';
					ClrBitCounter <= '1';
					if (ReadNotReadyIn = '1') then
						Error1 <= '1';
					elsif (SerialIn = '0' ) then
						Error2 <= '1';
					else
						Load <= '1';
						load_time<='1';
						
					end if;
				end if;
			when others =>
				NextState <= IDLE;
		end case;

	end process;



--====================== DESCRIPTION 2번 설명 ============================
--=======================================================================	
	-- State transition and Register transfer	
	REG_TRANSFER: process (SampleClk, nRst)
	begin
		if (nRst = '0') then
			State <= IDLE;
			SampleCounter <= (others => '0');
			BitCounter <= (others => '0');
			RCVDataReg <= (others => '0');
			RCVshftreg <= (others => '0');
			high_count<=(others =>'0');
			low_count<=(others =>'0');

		elsif ( SampleClk'event and SampleClk = '1') then
			State <= NextState;
			INT2<='0';
			if (ClrSampleCounter = '1') then
				SampleCounter <= (others => '0');
			elsif ( IncSampleCounter = '1') then
				SampleCounter <= SampleCounter + 1;
			end if;			
			
			if (ClrBitCounter = '1') then
				BitCounter <= (others =>'0');
			elsif(IncBitCounter = '1') then
				BitCounter <= BitCounter + 1;
			end if;									
			
			if (ClrHighCounter = '1') then
				high_count<=(others =>'0');
			elsif(IncHighCounter = '1') then
				high_count <= high_count + 1;
			end if;
			
			if (ClrLowCounter = '1') then
				low_count<=(others =>'0');
			elsif(IncLowCounter = '1') then
				low_count <= low_count + 1;
			end if;

			
           
			if (Shift = '1') then
				if(high_count>low_count) then
					RCVshftreg <= '1' & RCVshftreg(7 downto 1);
				else
					RCVshftreg <= '0' & RCVshftreg(7 downto 1);
				end if;
				
			end if;
			
			if (Load = '1') then
				INT2<='1';
				RCVDataReg <= RCVshftreg;
				dataout_time<='1';
				
				IF RCVshftreg(7 downto 0)="00000001" THEN
					test<='1';
				END IF;
			end if;
		end if;
	end process;
	
end architecture BEH;			
