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
Sheet 7 7
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
L MCP73831 U4
U 1 1 57E06106
P 5250 3050
F 0 "U4" H 5250 2900 60  0000 C CNN
F 1 "MCP73831" H 5250 3600 60  0000 C CNN
F 2 "EMG:sot23-5" H 5250 3600 60  0001 C CNN
F 3 "" H 5250 3600 60  0000 C CNN
	1    5250 3050
	-1   0    0    1   
$EndComp
$Comp
L CP C8
U 1 1 57E06124
P 6400 3350
F 0 "C8" H 6425 3450 50  0000 L CNN
F 1 "CP" H 6425 3250 50  0000 L CNN
F 2 "EMG:C_0805" H 6438 3200 50  0001 C CNN
F 3 "" H 6400 3350 50  0000 C CNN
	1    6400 3350
	1    0    0    -1  
$EndComp
$Comp
L CP C7
U 1 1 57E06133
P 3900 3250
F 0 "C7" H 3925 3350 50  0000 L CNN
F 1 "CP" H 3925 3150 50  0000 L CNN
F 2 "EMG:C_0805" H 3938 3100 50  0001 C CNN
F 3 "" H 3900 3250 50  0000 C CNN
	1    3900 3250
	1    0    0    -1  
$EndComp
$Comp
L R R22
U 1 1 57E0616A
P 6000 3400
F 0 "R22" V 6080 3400 50  0000 C CNN
F 1 "R" V 6000 3400 50  0000 C CNN
F 2 "EMG:R_0805" V 5930 3400 50  0001 C CNN
F 3 "" H 6000 3400 50  0000 C CNN
	1    6000 3400
	1    0    0    -1  
$EndComp
$Comp
L R R21
U 1 1 57E06179
P 4450 3550
F 0 "R21" V 4530 3550 50  0000 C CNN
F 1 "R" V 4450 3550 50  0000 C CNN
F 2 "EMG:R_0805" V 4380 3550 50  0001 C CNN
F 3 "" H 4450 3550 50  0000 C CNN
	1    4450 3550
	0    -1   -1   0   
$EndComp
$Comp
L LED D1
U 1 1 57E06194
P 4150 3350
F 0 "D1" H 4150 3450 50  0000 C CNN
F 1 "LED" H 4150 3250 50  0000 C CNN
F 2 "" H 4150 3350 50  0001 C CNN
F 3 "" H 4150 3350 50  0000 C CNN
	1    4150 3350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4600 3550 4750 3550
Wire Wire Line
	4750 3550 4750 3400
Wire Wire Line
	4300 3550 4150 3550
Wire Wire Line
	4150 3150 4150 3100
Wire Wire Line
	3400 3100 4750 3100
Connection ~ 4150 3100
Wire Wire Line
	5700 3250 6000 3250
$Comp
L +BATT #PWR022
U 1 1 57E062FB
P 6400 3100
F 0 "#PWR022" H 6400 2950 50  0001 C CNN
F 1 "+BATT" H 6400 3240 50  0000 C CNN
F 2 "" H 6400 3100 50  0000 C CNN
F 3 "" H 6400 3100 50  0000 C CNN
	1    6400 3100
	1    0    0    -1  
$EndComp
$Comp
L USB_A P3
U 1 1 57E06354
P 3100 3300
F 0 "P3" H 3300 3100 50  0000 C CNN
F 1 "USB_A" H 3050 3500 50  0000 C CNN
F 2 "" V 3050 3200 50  0001 C CNN
F 3 "" V 3050 3200 50  0000 C CNN
	1    3100 3300
	0    -1   1    0   
$EndComp
Connection ~ 3900 3100
$Comp
L GND #PWR023
U 1 1 57FAD4CF
P 3900 3400
F 0 "#PWR023" H 3900 3150 50  0001 C CNN
F 1 "GND" H 3900 3250 50  0000 C CNN
F 2 "" H 3900 3400 50  0000 C CNN
F 3 "" H 3900 3400 50  0000 C CNN
	1    3900 3400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR024
U 1 1 57FAD4F1
P 6000 3550
F 0 "#PWR024" H 6000 3300 50  0001 C CNN
F 1 "GND" H 6000 3400 50  0000 C CNN
F 2 "" H 6000 3550 50  0000 C CNN
F 3 "" H 6000 3550 50  0000 C CNN
	1    6000 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 3400 3900 3400
Wire Wire Line
	5700 3400 5700 3550
Wire Wire Line
	5700 3550 6400 3550
Wire Wire Line
	6400 3550 6400 3500
Connection ~ 6000 3550
Wire Wire Line
	5700 3100 6400 3100
Wire Wire Line
	6400 3100 6400 3200
NoConn ~ 3400 3200
NoConn ~ 3400 3300
NoConn ~ 3000 3600
$EndSCHEMATC
