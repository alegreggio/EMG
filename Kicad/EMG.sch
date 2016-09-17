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
Sheet 1 7
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 2900 1000 1800 2200
U 57DD5359
F0 "Adquisición" 60
F1 "Adquisición.sch" 60
F2 "E1" I L 2900 1350 60 
F3 "E2" I L 2900 1700 60 
F4 "DRL" I L 2900 2100 60 
F5 "Vout" I R 4700 1800 60 
$EndSheet
$Sheet
S 5550 1200 1400 1350
U 57DD8947
F0 "Microcontrolador" 60
F1 "Microcontrolador.sch" 60
F2 "ADCin" I L 5550 1800 60 
F3 "CE" I R 6950 1450 60 
F4 "CSN" I R 6950 1550 60 
F5 "IRQ" I R 6950 1650 60 
F6 "SCK" I R 6950 1750 60 
F7 "MOSI" I R 6950 1850 60 
F8 "MISO" I R 6950 1950 60 
$EndSheet
$Sheet
S 8150 1200 1550 1350
U 57DD8FD2
F0 "RF" 60
F1 "RF.sch" 60
F2 "CE" I L 8150 1450 60 
F3 "SCK" I L 8150 1750 60 
F4 "MISO" I L 8150 1950 60 
F5 "IRQ" I L 8150 1650 60 
F6 "MOSI" I L 8150 1850 60 
F7 "CSN" I L 8150 1550 60 
$EndSheet
Wire Wire Line
	6950 1450 8150 1450
Wire Wire Line
	6950 1550 8150 1550
Wire Wire Line
	6950 1650 8150 1650
Wire Wire Line
	6950 1750 8150 1750
Wire Wire Line
	6950 1850 8150 1850
Wire Wire Line
	6950 1950 8150 1950
Wire Wire Line
	4700 1800 5550 1800
$Sheet
S 2550 4150 1500 1300
U 57DDA572
F0 "DC/DC" 60
F1 "DCDC.sch" 60
$EndSheet
$Sheet
S 5100 4150 1700 1300
U 57DDA5A8
F0 "Bateria" 60
F1 "Bateria.sch" 60
$EndSheet
$Sheet
S 7750 4150 1700 1350
U 57DDA5DE
F0 "Cargador" 60
F1 "Cargador.sch" 60
$EndSheet
$EndSCHEMATC
