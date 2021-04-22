--------------------------------------------------Description-------------------------------------------------------------------
--==============================================================================================================================

-- 상위제어기로 data 송신 시 사용, data 입력은 dsp에서 external interface의 write access 를 통해 fpga로 보낸 data를 latch를 통해 입력 받음 
-- tx data 프로토콜은 dsp main함수 참고
-- 1. 각 통신 상태일 때 발생하는 조건이 어떻게 동작하는지에 대한 동작 설정 => 아레에 1번 설명 부분 
-- 2. 통신 상태가 IDLE, WAITING, SENDING에 따라 해당하는 동작 수행 => 아래에 2번 설명 부분 
---------------------------------------------------------------------------------------------------------------------------------





Library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;

entity UART_Tx is
	port(nRst, Clk	:in std_logic;
			ByteReady, Tbyte	: in std_logic;
			LoadXMTDataReg	: in std_logic;
			DataBus	: in std_logic_vector(7 downto 0);
			SerialOut,outend : out std_logic);
end entity UART_Tx;


architecture transmit of UART_Tx is
	signal XMTdatareg : std_logic_vector(7 downto 0); -- Tx data register
	signal XMTshftreg : std_logic_vector(8 downto 0); -- transmit Shift
	signal LoadXMTshftreg : std_logic; -- Flag to load the XMTshftreg
	signal BitCount : unsigned (3 downto 0);
	signal Clear : std_logic; -- clears bit_count after last bit sent
	signal Shift : std_logic; -- Causes shift of data in XMTshftreg;
	signal Start : std_logic; -- Signals start of transmission

	Type StateType is (IDLE, WAITING, SENDING );
	signal State, NextState : StateType;
	
	
--====================== DESCRIPTION 1번 설명 ============================
--======================================================================= 	
begin
	SerialOut <= XMTshftreg(0); -- LSB of Shift register
	outend <= '0' WHEN State=IDLE ELSE '1';
	REG_TRANSFER: process (Clk, nRst)
		begin
			if (nRst = '0') then
				XMTshftreg <= (others => '1');
				State <= IDLE;
				BitCount <= (others => '0');
			elsif ( Clk'event and Clk = '1') then
				State <= NextState;
				if (LoadXMTdatareg = '1') then
					XMTdatareg <= DataBus; -- get the data bus
				end if;

				if (LoadXMTshftreg = '1') then
					XMTshftreg <= XMTdatareg & '1'; --Load shift reg
				end if;
				if (Start = '1') then
					XMTshftreg(0) <= '0'; -- Signal start of transmission
				end if;
				if (Clear = '1') then
					BitCount <= (others => '0');
				elsif (Shift = '1' ) then
					BitCount <= BitCount + 1;
				end if;
				if (Shift = '1') then
					XMTshftreg <= '1' & XMTshftreg(8 downto 1); -- shift right, fill 1's
					--SerialOut <= XMTshftreg(0); -- LSB of Shift register

				end if;
			end if;
		end process;
		
--====================== DESCRIPTION 2번 설명 ============================
--=======================================================================
	STATECOMB: process (State, ByteReady, BitCount, TByte)
		begin
			Clear <= '0';
			LoadXMTshftreg <= '0';
			Shift <= '0';
			Start <= '0';
			case(state) is
				when IDLE =>
					if (ByteReady = '1') then
						LoadXMTshftreg <= '1';
						NextState <= WAITING;
					else
						NextState <= IDLE;
					end if;
			when WAITING =>
			
				if (TByte = '1') then
					Start <= '1';
					NextState <= SENDING;
				else
					NextState <= WAITING;
				end if;
			when SENDING =>
				if (BitCount /= 9 ) then
					Shift <= '1';
					NextState <= SENDING;
				else
					Clear <= '1';
					NextState <= IDLE;
				end if;
			when others =>
					NextState <= IDLE;
			end case;
		end process;

end architecture transmit;


