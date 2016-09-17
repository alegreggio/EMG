EESchema Schematic File Version 2
LIBS:conn
LIBS:device
LIBS:Gajda_amplif
LIBS:opa4243
LIBS:tlc2274
LIBS:power
LIBS:msp430
LIBS:nrf24l01
LIBS:bat
LIBS:batn
LIBS:microchip
LIBS:nordicsemi
LIBS:Power_Management
LIBS:powerint
LIBS:references
LIBS:rfcom
LIBS:texas
LIBS:EMG-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 7
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MSP430G2231IPW14 U1
U 1 1 57DD899A
P 5400 3200
F 0 "U1" H 4650 3800 50  0000 C CNN
F 1 "MSP430G2231IPW14" H 5900 2650 50  0000 C CNN
F 2 "14PW" H 4700 2650 50  0000 C CIN
F 3 "" H 5400 3200 50  0000 C CNN
	1    5400 3200
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR9
U 1 1 57DD89FE
P 5400 2500
F 0 "#PWR9" H 5400 2350 50  0001 C CNN
F 1 "VCC" H 5400 2650 50  0000 C CNN
F 2 "" H 5400 2500 50  0000 C CNN
F 3 "" H 5400 2500 50  0000 C CNN
	1    5400 2500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR10
U 1 1 57DD8A14
P 5400 3850
F 0 "#PWR10" H 5400 3600 50  0001 C CNN
F 1 "GND" H 5400 3700 50  0000 C CNN
F 2 "" H 5400 3850 50  0000 C CNN
F 3 "" H 5400 3850 50  0000 C CNN
	1    5400 3850
	1    0    0    -1  
$EndComp
Text HLabel 6600 2900 2    60   Input ~ 0
ADCin
Wire Wire Line
	6350 2900 6600 2900
Text HLabel 6600 3000 2    60   Input ~ 0
CE
Text HLabel 6600 3100 2    60   Input ~ 0
CSN
Text HLabel 6600 3200 2    60   Input ~ 0
IRQ
Text HLabel 6600 3400 2    60   Input ~ 0
SCK
Text HLabel 6600 3500 2    60   Input ~ 0
MOSI
Text HLabel 6600 3600 2    60   Input ~ 0
MISO
Wire Wire Line
	6350 3000 6600 3000
Wire Wire Line
	6350 3100 6600 3100
Wire Wire Line
	6350 3200 6600 3200
Wire Wire Line
	6350 3400 6600 3400
Wire Wire Line
	6350 3500 6600 3500
Wire Wire Line
	6350 3600 6600 3600
$EndSCHEMATC