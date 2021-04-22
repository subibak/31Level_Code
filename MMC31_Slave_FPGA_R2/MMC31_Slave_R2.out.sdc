## Generated SDC file "MMC31_Slave_R2.out.sdc"

## Copyright (C) 2018  Intel Corporation. All rights reserved.
## Your use of Intel Corporation's design tools, logic functions 
## and other software and tools, and its AMPP partner logic 
## functions, and any output files from any of the foregoing 
## (including device programming or simulation files), and any 
## associated documentation or information are expressly subject 
## to the terms and conditions of the Intel Program License 
## Subscription Agreement, the Intel Quartus Prime License Agreement,
## the Intel FPGA IP License Agreement, or other applicable license
## agreement, including, without limitation, that your use is for
## the sole purpose of programming logic devices manufactured by
## Intel and sold by Intel or its authorized distributors.  Please
## refer to the applicable agreement for further details.


## VENDOR  "Altera"
## PROGRAM "Quartus Prime"
## VERSION "Version 18.1.0 Build 625 09/12/2018 SJ Lite Edition"

## DATE    "Tue Oct 27 14:00:29 2020"

##
## DEVICE  "EP4CE40F23I8L"
##


#**************************************************************
# Time Information
#**************************************************************

set_time_format -unit ns -decimal_places 3



#**************************************************************
# Create Clock
#**************************************************************

create_clock -name {CLK_EMIF} -period 10.000 -waveform { 0.000 5.000 } [get_ports { CLK_EMIF }]
create_clock -name {nEM1WE} -period 70.000 -waveform { 0.000 40.000 } [get_ports { nEM1WE }]


#**************************************************************
# Create Generated Clock
#**************************************************************



#**************************************************************
# Set Clock Latency
#**************************************************************



#**************************************************************
# Set Clock Uncertainty
#**************************************************************

set_clock_uncertainty -rise_from [get_clocks {nEM1WE}] -rise_to [get_clocks {nEM1WE}]  0.020  
set_clock_uncertainty -rise_from [get_clocks {nEM1WE}] -fall_to [get_clocks {nEM1WE}]  0.020  
set_clock_uncertainty -fall_from [get_clocks {nEM1WE}] -rise_to [get_clocks {nEM1WE}]  0.020  
set_clock_uncertainty -fall_from [get_clocks {nEM1WE}] -fall_to [get_clocks {nEM1WE}]  0.020  
set_clock_uncertainty -rise_from [get_clocks {CLK_EMIF}] -rise_to [get_clocks {nEM1WE}]  0.040  
set_clock_uncertainty -rise_from [get_clocks {CLK_EMIF}] -fall_to [get_clocks {nEM1WE}]  0.040  
set_clock_uncertainty -rise_from [get_clocks {CLK_EMIF}] -rise_to [get_clocks {CLK_EMIF}]  0.020  
set_clock_uncertainty -rise_from [get_clocks {CLK_EMIF}] -fall_to [get_clocks {CLK_EMIF}]  0.020  
set_clock_uncertainty -fall_from [get_clocks {CLK_EMIF}] -rise_to [get_clocks {nEM1WE}]  0.040  
set_clock_uncertainty -fall_from [get_clocks {CLK_EMIF}] -fall_to [get_clocks {nEM1WE}]  0.040  
set_clock_uncertainty -fall_from [get_clocks {CLK_EMIF}] -rise_to [get_clocks {CLK_EMIF}]  0.020  
set_clock_uncertainty -fall_from [get_clocks {CLK_EMIF}] -fall_to [get_clocks {CLK_EMIF}]  0.020  


#**************************************************************
# Set Input Delay
#**************************************************************



#**************************************************************
# Set Output Delay
#**************************************************************



#**************************************************************
# Set Clock Groups
#**************************************************************



#**************************************************************
# Set False Path
#**************************************************************

set_false_path -from [get_keepers {GPIOx:inst1|Dir_Reg[1]}] -to [get_keepers {GPIOx:inst1|Out_Reg[1]}]
set_false_path -from [get_keepers {GPIOx:inst1|Dir_Reg[3]}] -to [get_keepers {GPIOx:inst1|Out_Reg[3]}]
set_false_path -from [get_keepers {GPIOx:inst1|Dir_Reg[2]}] -to [get_keepers {GPIOx:inst1|Out_Reg[2]}]
set_false_path -from [get_keepers {GPIOx:inst1|Dir_Reg[0]}] -to [get_keepers {GPIOx:inst1|Out_Reg[0]}]
set_false_path -from [get_keepers {GPIOx:inst1|Out_Reg[1]}] -to [get_keepers {GPIOx:inst1|Out_Reg[1]}]
set_false_path -from [get_keepers {GPIOx:inst1|Out_Reg[3]}] -to [get_keepers {GPIOx:inst1|Out_Reg[3]}]
set_false_path -from [get_keepers {GPIOx:inst1|Out_Reg[2]}] -to [get_keepers {GPIOx:inst1|Out_Reg[2]}]
set_false_path -from [get_keepers {GPIOx:inst1|Out_Reg[0]}] -to [get_keepers {GPIOx:inst1|Out_Reg[0]}]


#**************************************************************
# Set Multicycle Path
#**************************************************************



#**************************************************************
# Set Maximum Delay
#**************************************************************



#**************************************************************
# Set Minimum Delay
#**************************************************************



#**************************************************************
# Set Input Transition
#**************************************************************

