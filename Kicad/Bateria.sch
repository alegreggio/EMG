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
Sheet 6 7
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
L BAT P2
U 1 1 57DDA8B8
P 5250 3650
F 0 "P2" H 5250 3750 50  0000 C CNN
F 1 "BAT" H 5250 3550 50  0000 C CNN
F 2 "" H 5250 2450 50  0000 C CNN
F 3 "" H 5250 2450 50  0000 C CNN
	1    5250 3650
	1    0    0    -1  
$EndComp
$Comp
L +BATT #PWR?
U 1 1 57DDA8D2
P 5000 3650
F 0 "#PWR?" H 5000 3500 50  0001 C CNN
F 1 "+BATT" H 5000 3790 50  0000 C CNN
F 2 "" H 5000 3650 50  0000 C CNN
F 3 "" H 5000 3650 50  0000 C CNN
	1    5000 3650
	0    -1   -1   0   
$EndComp
$Comp
L -BATT #PWR?
U 1 1 57DDA938
P 5500 3650
F 0 "#PWR?" H 5500 3500 50  0001 C CNN
F 1 "-BATT" H 5500 3790 50  0000 C CNN
F 2 "" H 5500 3650 50  0000 C CNN
F 3 "" H 5500 3650 50  0000 C CNN
	1    5500 3650
	0    1    1    0   
$EndComp
$EndSCHEMATC
