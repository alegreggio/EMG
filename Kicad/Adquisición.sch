EESchema Schematic File Version 2
LIBS:conn
LIBS:device
LIBS:Gajda_amplif
LIBS:tlc2274
LIBS:power
LIBS:msp430
LIBS:nrf24l01
LIBS:bat
LIBS:batn
LIBS:MCP73831
LIBS:maxim
LIBS:max8881
LIBS:EMG-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 7
Title ""
Date "19 sep 2016"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L TLC2274 U2
U 1 1 57DD6904
P 3700 1950
F 0 "U2" H 3850 2150 60  0000 C CNN
F 1 "TLC2274" H 3950 1750 60  0000 C CNN
F 2 "EMG:TSSOP-14_4.4x5mm_Pitch0.65mm" H 3700 1950 60  0001 C CNN
F 3 "" H 3700 1950 60  0000 C CNN
	1    3700 1950
	1    0    0    -1  
$EndComp
$Comp
L TLC2274 U2
U 2 1 57DD690B
P 3700 3450
F 0 "U2" H 3850 3650 60  0000 C CNN
F 1 "TLC2274" H 3950 3250 60  0000 C CNN
F 2 "EMG:TSSOP-14_4.4x5mm_Pitch0.65mm" H 3700 3450 60  0001 C CNN
F 3 "" H 3700 3450 60  0000 C CNN
	2    3700 3450
	1    0    0    1   
$EndComp
$Comp
L TLC2274 U3
U 1 1 57DD6912
P 5750 2050
F 0 "U3" H 5900 2250 60  0000 C CNN
F 1 "TLC2274" H 6000 1850 60  0000 C CNN
F 2 "EMG:TSSOP-14_4.4x5mm_Pitch0.65mm" H 5750 2050 60  0001 C CNN
F 3 "" H 5750 2050 60  0000 C CNN
	1    5750 2050
	1    0    0    -1  
$EndComp
$Comp
L TLC2274 U3
U 2 1 57DD6919
P 5750 3350
F 0 "U3" H 5900 3550 60  0000 C CNN
F 1 "TLC2274" H 6000 3150 60  0000 C CNN
F 2 "EMG:TSSOP-14_4.4x5mm_Pitch0.65mm" H 5750 3350 60  0001 C CNN
F 3 "" H 5750 3350 60  0000 C CNN
	2    5750 3350
	1    0    0    1   
$EndComp
$Comp
L R R3
U 1 1 57DD6920
P 3650 2450
F 0 "R3" V 3730 2450 50  0000 C CNN
F 1 "43K" V 3650 2450 50  0000 C CNN
F 2 "EMG:R_0805" V 3580 2450 50  0001 C CNN
F 3 "" H 3650 2450 50  0000 C CNN
	1    3650 2450
	0    1    1    0   
$EndComp
$Comp
L R R4
U 1 1 57DD6927
P 3650 2950
F 0 "R4" V 3730 2950 50  0000 C CNN
F 1 "43K" V 3650 2950 50  0000 C CNN
F 2 "EMG:R_0805" V 3580 2950 50  0001 C CNN
F 3 "" H 3650 2950 50  0000 C CNN
	1    3650 2950
	0    1    1    0   
$EndComp
$Comp
L R R1
U 1 1 57DD692E
P 3350 2700
F 0 "R1" V 3430 2700 50  0000 C CNN
F 1 "10K" V 3350 2700 50  0000 C CNN
F 2 "EMG:R_0805" V 3280 2700 50  0001 C CNN
F 3 "" H 3350 2700 50  0000 C CNN
	1    3350 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 2050 3350 2550
Wire Wire Line
	3350 2450 3500 2450
Wire Wire Line
	3350 2950 3500 2950
Wire Wire Line
	3350 2850 3350 3350
Wire Wire Line
	3800 2450 4050 2450
Wire Wire Line
	4050 2450 4050 1950
Wire Wire Line
	3800 2950 4050 2950
Wire Wire Line
	4050 2950 4050 3450
$Comp
L R R5
U 1 1 57DD693D
P 4350 2100
F 0 "R5" V 4430 2100 50  0000 C CNN
F 1 "22K" V 4350 2100 50  0000 C CNN
F 2 "EMG:R_0805" V 4280 2100 50  0001 C CNN
F 3 "" H 4350 2100 50  0000 C CNN
	1    4350 2100
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 57DD6944
P 4350 3300
F 0 "R6" V 4430 3300 50  0000 C CNN
F 1 "22K" V 4350 3300 50  0000 C CNN
F 2 "EMG:R_0805" V 4280 3300 50  0001 C CNN
F 3 "" H 4350 3300 50  0000 C CNN
	1    4350 3300
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 57DD694B
P 5000 2100
F 0 "R7" V 5080 2100 50  0000 C CNN
F 1 "10M" V 5000 2100 50  0000 C CNN
F 2 "EMG:R_0805" V 4930 2100 50  0001 C CNN
F 3 "" H 5000 2100 50  0000 C CNN
	1    5000 2100
	1    0    0    -1  
$EndComp
$Comp
L R R8
U 1 1 57DD6952
P 5000 3300
F 0 "R8" V 5080 3300 50  0000 C CNN
F 1 "10M" V 5000 3300 50  0000 C CNN
F 2 "EMG:R_0805" V 4930 3300 50  0001 C CNN
F 3 "" H 5000 3300 50  0000 C CNN
	1    5000 3300
	1    0    0    -1  
$EndComp
$Comp
L R R13
U 1 1 57DD6959
P 5550 2500
F 0 "R13" V 5630 2500 50  0000 C CNN
F 1 "430K" V 5550 2500 50  0000 C CNN
F 2 "EMG:R_0805" V 5480 2500 50  0001 C CNN
F 3 "" H 5550 2500 50  0000 C CNN
	1    5550 2500
	0    1    1    0   
$EndComp
Connection ~ 3350 2450
Connection ~ 3350 2950
$Comp
L R R14
U 1 1 57DD6962
P 5550 2900
F 0 "R14" V 5630 2900 50  0000 C CNN
F 1 "430K" V 5550 2900 50  0000 C CNN
F 2 "EMG:R_0805" V 5480 2900 50  0001 C CNN
F 3 "" H 5550 2900 50  0000 C CNN
	1    5550 2900
	0    1    1    0   
$EndComp
$Comp
L R R12
U 1 1 57DD6969
P 5400 2700
F 0 "R12" V 5480 2700 50  0000 C CNN
F 1 "43K" V 5400 2700 50  0000 C CNN
F 2 "EMG:R_0805" V 5330 2700 50  0001 C CNN
F 3 "" H 5400 2700 50  0000 C CNN
	1    5400 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 2150 5400 2550
Connection ~ 5400 2500
Wire Wire Line
	5400 2850 5400 3250
Connection ~ 5400 2900
Wire Wire Line
	5700 2500 6100 2500
Wire Wire Line
	6100 2500 6100 2050
Wire Wire Line
	5700 2900 6100 2900
Wire Wire Line
	6100 2900 6100 3350
Wire Wire Line
	4050 1950 4500 1950
Wire Wire Line
	4800 1950 5400 1950
Wire Wire Line
	4050 3450 4500 3450
Wire Wire Line
	4800 3450 5400 3450
Wire Wire Line
	4350 2250 4350 3150
Wire Wire Line
	5000 2250 5000 3150
$Comp
L C C2
U 1 1 57DD697E
P 4650 1950
F 0 "C2" H 4675 2050 50  0000 L CNN
F 1 "0.33uF" H 4675 1850 50  0000 L CNN
F 2 "EMG:C_0805" H 4688 1800 50  0001 C CNN
F 3 "" H 4650 1950 50  0000 C CNN
	1    4650 1950
	0    1    1    0   
$EndComp
$Comp
L C C3
U 1 1 57DD6985
P 4650 3450
F 0 "C3" H 4675 3550 50  0000 L CNN
F 1 "0.33uF" H 4675 3350 50  0000 L CNN
F 2 "EMG:C_0805" H 4688 3300 50  0001 C CNN
F 3 "" H 4650 3450 50  0000 C CNN
	1    4650 3450
	0    1    1    0   
$EndComp
Connection ~ 4350 1950
Connection ~ 5000 1950
Connection ~ 4350 3450
Connection ~ 5000 3450
$Comp
L R R15
U 1 1 57DD6990
P 6400 3350
F 0 "R15" V 6480 3350 50  0000 C CNN
F 1 "43K" V 6400 3350 50  0000 C CNN
F 2 "EMG:R_0805" V 6330 3350 50  0001 C CNN
F 3 "" H 6400 3350 50  0000 C CNN
	1    6400 3350
	0    1    1    0   
$EndComp
$Comp
L TLC2274 U3
U 4 1 57DD6997
P 7050 3250
F 0 "U3" H 7200 3450 60  0000 C CNN
F 1 "TLC2274" H 7300 3050 60  0000 C CNN
F 2 "EMG:TSSOP-14_4.4x5mm_Pitch0.65mm" H 7050 3250 60  0001 C CNN
F 3 "" H 7050 3250 60  0000 C CNN
	4    7050 3250
	1    0    0    1   
$EndComp
$Comp
L R R16
U 1 1 57DD699E
P 6700 2550
F 0 "R16" V 6780 2550 50  0000 C CNN
F 1 "43K" V 6700 2550 50  0000 C CNN
F 2 "EMG:R_0805" V 6630 2550 50  0001 C CNN
F 3 "" H 6700 2550 50  0000 C CNN
	1    6700 2550
	1    0    0    -1  
$EndComp
$Comp
L R R18
U 1 1 57DD69A5
P 7000 2700
F 0 "R18" V 7080 2700 50  0000 C CNN
F 1 "215K" V 7000 2700 50  0000 C CNN
F 2 "EMG:R_0805" V 6930 2700 50  0001 C CNN
F 3 "" H 7000 2700 50  0000 C CNN
	1    7000 2700
	0    1    1    0   
$EndComp
Wire Wire Line
	6100 2050 6700 2050
Wire Wire Line
	6700 2050 6700 2400
Wire Wire Line
	6700 2700 6850 2700
Wire Wire Line
	7150 2700 7400 2700
Wire Wire Line
	7400 2700 7400 3700
Wire Wire Line
	6100 3350 6250 3350
Wire Wire Line
	6550 3350 6700 3350
Wire Wire Line
	6700 3150 6700 2700
$Comp
L R R17
U 1 1 57DD69B4
P 6700 3550
F 0 "R17" V 6780 3550 50  0000 C CNN
F 1 "215K" V 6700 3550 50  0000 C CNN
F 2 "EMG:R_0805" V 6630 3550 50  0001 C CNN
F 3 "" H 6700 3550 50  0000 C CNN
	1    6700 3550
	1    0    0    -1  
$EndComp
$Comp
L C C5
U 1 1 57DD69BB
P 6900 3700
F 0 "C5" H 6925 3800 50  0000 L CNN
F 1 "0.68uF" H 6925 3600 50  0000 L CNN
F 2 "EMG:C_0805" H 6938 3550 50  0001 C CNN
F 3 "" H 6900 3700 50  0000 C CNN
	1    6900 3700
	0    1    1    0   
$EndComp
$Comp
L R R19
U 1 1 57DD69C2
P 7250 3700
F 0 "R19" V 7330 3700 50  0000 C CNN
F 1 "10M" V 7250 3700 50  0000 C CNN
F 2 "EMG:R_0805" V 7180 3700 50  0001 C CNN
F 3 "" H 7250 3700 50  0000 C CNN
	1    7250 3700
	0    1    1    0   
$EndComp
Wire Wire Line
	6700 3350 6700 3400
Wire Wire Line
	6350 3700 6750 3700
Wire Wire Line
	7050 3700 7100 3700
Connection ~ 7400 3250
$Comp
L TLC2274 U3
U 3 1 57DD69CD
P 6700 4200
F 0 "U3" H 6850 4400 60  0000 C CNN
F 1 "TLC2274" H 6950 4000 60  0000 C CNN
F 2 "EMG:TSSOP-14_4.4x5mm_Pitch0.65mm" H 6700 4200 60  0001 C CNN
F 3 "" H 6700 4200 60  0000 C CNN
	3    6700 4200
	-1   0    0    1   
$EndComp
Wire Wire Line
	7050 4100 7050 3700
Wire Wire Line
	6350 4200 6350 3700
Connection ~ 6700 3700
$Comp
L TLC2274 U2
U 3 1 57DD69D7
P 3850 4500
F 0 "U2" H 4000 4700 60  0000 C CNN
F 1 "TLC2274" H 4100 4300 60  0000 C CNN
F 2 "EMG:TSSOP-14_4.4x5mm_Pitch0.65mm" H 3850 4500 60  0001 C CNN
F 3 "" H 3850 4500 60  0000 C CNN
	3    3850 4500
	-1   0    0    1   
$EndComp
Wire Wire Line
	4200 4600 7050 4600
Wire Wire Line
	7050 4600 7050 4300
Wire Wire Line
	4200 2700 4200 4400
Wire Wire Line
	4200 2700 4350 2700
Connection ~ 4350 2700
$Comp
L R R9
U 1 1 57DD69E3
P 5250 4000
F 0 "R9" V 5330 4000 50  0000 C CNN
F 1 "10M" V 5250 4000 50  0000 C CNN
F 2 "EMG:R_0805" V 5180 4000 50  0001 C CNN
F 3 "" H 5250 4000 50  0000 C CNN
	1    5250 4000
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 57DD69EA
P 3850 3950
F 0 "C1" H 3875 4050 50  0000 L CNN
F 1 "10nF" H 3875 3850 50  0000 L CNN
F 2 "EMG:C_0805" H 3888 3800 50  0001 C CNN
F 3 "" H 3850 3950 50  0000 C CNN
	1    3850 3950
	0    1    1    0   
$EndComp
$Comp
L R R2
U 1 1 57DD69F1
P 3500 4100
F 0 "R2" V 3580 4100 50  0000 C CNN
F 1 "510K" V 3500 4100 50  0000 C CNN
F 2 "EMG:R_0805" V 3430 4100 50  0001 C CNN
F 3 "" H 3500 4100 50  0000 C CNN
	1    3500 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 3850 5250 2700
Wire Wire Line
	5250 2700 5000 2700
Connection ~ 5000 2700
Wire Wire Line
	5250 4150 5250 4600
Connection ~ 5250 4600
Wire Wire Line
	3500 3950 3700 3950
Wire Wire Line
	4000 3950 4200 3950
Connection ~ 4200 3950
Wire Wire Line
	3500 4500 3500 4250
$Comp
L TLC2274 U2
U 4 1 57DD6A01
P 4550 5550
F 0 "U2" H 4700 5750 60  0000 C CNN
F 1 "TLC2274" H 4800 5350 60  0000 C CNN
F 2 "EMG:TSSOP-14_4.4x5mm_Pitch0.65mm" H 4550 5550 60  0001 C CNN
F 3 "" H 4550 5550 60  0000 C CNN
	4    4550 5550
	-1   0    0    1   
$EndComp
$Comp
L VCC #PWR1
U 1 1 57DD6A08
P 4550 5200
F 0 "#PWR1" H 4550 5050 50  0001 C CNN
F 1 "VCC" H 4550 5350 50  0000 C CNN
F 2 "" H 4550 5200 50  0000 C CNN
F 3 "" H 4550 5200 50  0000 C CNN
	1    4550 5200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR2
U 1 1 57DD6A0E
P 4550 5900
F 0 "#PWR2" H 4550 5650 50  0001 C CNN
F 1 "GND" H 4550 5750 50  0000 C CNN
F 2 "" H 4550 5900 50  0000 C CNN
F 3 "" H 4550 5900 50  0000 C CNN
	1    4550 5900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR7
U 1 1 57DD6A14
P 5750 3700
F 0 "#PWR7" H 5750 3450 50  0001 C CNN
F 1 "GND" H 5750 3550 50  0000 C CNN
F 2 "" H 5750 3700 50  0000 C CNN
F 3 "" H 5750 3700 50  0000 C CNN
	1    5750 3700
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR6
U 1 1 57DD6A1A
P 5750 2800
F 0 "#PWR6" H 5750 2650 50  0001 C CNN
F 1 "VCC" H 5750 2950 50  0000 C CNN
F 2 "" H 5750 2800 50  0000 C CNN
F 3 "" H 5750 2800 50  0000 C CNN
	1    5750 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 2800 5750 3000
Wire Wire Line
	4200 4600 4200 5550
Wire Wire Line
	4900 5450 4900 4950
Wire Wire Line
	4900 4950 4200 4950
Connection ~ 4200 4950
$Comp
L C C4
U 1 1 57DD6A25
P 5000 5800
F 0 "C4" H 5025 5900 50  0000 L CNN
F 1 "1uF" H 5025 5700 50  0000 L CNN
F 2 "EMG:C_0805" H 5038 5650 50  0001 C CNN
F 3 "" H 5000 5800 50  0000 C CNN
	1    5000 5800
	1    0    0    -1  
$EndComp
$Comp
L R R11
U 1 1 57DD6A2C
P 5250 5800
F 0 "R11" V 5330 5800 50  0000 C CNN
F 1 "1M" V 5250 5800 50  0000 C CNN
F 2 "EMG:R_0805" V 5180 5800 50  0001 C CNN
F 3 "" H 5250 5800 50  0000 C CNN
	1    5250 5800
	1    0    0    -1  
$EndComp
$Comp
L R R10
U 1 1 57DD6A33
P 5250 5450
F 0 "R10" V 5330 5450 50  0000 C CNN
F 1 "1M" V 5250 5450 50  0000 C CNN
F 2 "EMG:R_0805" V 5180 5450 50  0001 C CNN
F 3 "" H 5250 5450 50  0000 C CNN
	1    5250 5450
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR4
U 1 1 57DD6A3A
P 5250 5300
F 0 "#PWR4" H 5250 5150 50  0001 C CNN
F 1 "VCC" H 5250 5450 50  0000 C CNN
F 2 "" H 5250 5300 50  0000 C CNN
F 3 "" H 5250 5300 50  0000 C CNN
	1    5250 5300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR5
U 1 1 57DD6A40
P 5250 5950
F 0 "#PWR5" H 5250 5700 50  0001 C CNN
F 1 "GND" H 5250 5800 50  0000 C CNN
F 2 "" H 5250 5950 50  0000 C CNN
F 3 "" H 5250 5950 50  0000 C CNN
	1    5250 5950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR3
U 1 1 57DD6A46
P 5000 5950
F 0 "#PWR3" H 5000 5700 50  0001 C CNN
F 1 "GND" H 5000 5800 50  0000 C CNN
F 2 "" H 5000 5950 50  0000 C CNN
F 3 "" H 5000 5950 50  0000 C CNN
	1    5000 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 5650 5250 5650
Connection ~ 5000 5650
Wire Wire Line
	5250 5650 5250 5600
Text HLabel 3000 1850 0    60   Input ~ 0
E1
Text HLabel 3000 3550 0    60   Input ~ 0
E2
Text HLabel 3000 4500 0    60   Input ~ 0
DRL
Wire Wire Line
	3000 3550 3350 3550
Wire Wire Line
	3000 1850 3350 1850
$Comp
L R R20
U 1 1 57DD7E0F
P 7750 3250
F 0 "R20" V 7830 3250 50  0000 C CNN
F 1 "1600K" V 7750 3250 50  0000 C CNN
F 2 "EMG:R_0805" V 7680 3250 50  0001 C CNN
F 3 "" H 7750 3250 50  0000 C CNN
	1    7750 3250
	0    1    1    0   
$EndComp
$Comp
L C C6
U 1 1 57DD7E78
P 8050 3400
F 0 "C6" H 8075 3500 50  0000 L CNN
F 1 "1uF" H 8075 3300 50  0000 L CNN
F 2 "EMG:C_0805" H 8088 3250 50  0001 C CNN
F 3 "" H 8050 3400 50  0000 C CNN
	1    8050 3400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR8
U 1 1 57DD7EDB
P 8050 3550
F 0 "#PWR8" H 8050 3300 50  0001 C CNN
F 1 "GND" H 8050 3400 50  0000 C CNN
F 2 "" H 8050 3550 50  0000 C CNN
F 3 "" H 8050 3550 50  0000 C CNN
	1    8050 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 3250 7600 3250
Wire Wire Line
	7900 3250 8400 3250
Text HLabel 8400 3250 2    60   Input ~ 0
Vout
Connection ~ 8050 3250
Wire Wire Line
	3000 4500 3500 4500
$EndSCHEMATC
