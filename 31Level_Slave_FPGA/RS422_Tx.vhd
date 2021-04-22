--31Lv Groupmodule_Data Acquizition Block 
--Tranceiver 


Library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;

entity RS422_TX is
	port(nRst, Clk	:in std_logic;
			ByteReady, Tbyte	: in std_logic;
			LoadXMTDataReg	: in std_logic;
			DataBus	: in std_logic_vector(7 downto 0);
			SerialOut,outend : out std_logic);
end entity RS422_TX;