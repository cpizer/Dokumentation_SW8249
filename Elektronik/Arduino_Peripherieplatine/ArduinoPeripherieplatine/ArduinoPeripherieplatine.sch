EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L Regulator_Linear:LM7805_TO220 U?
U 1 1 632E597E
P 2250 1550
F 0 "U?" H 2250 1792 50  0000 C CNN
F 1 "LM7805_TO220" H 2250 1701 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 2250 1775 50  0001 C CIN
F 3 "https://www.onsemi.cn/PowerSolutions/document/MC7800-D.PDF" H 2250 1500 50  0001 C CNN
	1    2250 1550
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LM358 U?
U 1 1 632EDACF
P 5100 1100
F 0 "U?" H 5100 1467 50  0000 C CNN
F 1 "LM358" H 5100 1376 50  0000 C CNN
F 2 "" H 5100 1100 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2904-n.pdf" H 5100 1100 50  0001 C CNN
	1    5100 1100
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LM358 U?
U 2 1 632F4730
P 5100 1700
F 0 "U?" H 5100 2067 50  0000 C CNN
F 1 "LM358" H 5100 1976 50  0000 C CNN
F 2 "" H 5100 1700 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2904-n.pdf" H 5100 1700 50  0001 C CNN
	2    5100 1700
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LM358 U?
U 3 1 632F70CD
P 5100 2200
F 0 "U?" V 4775 2200 50  0000 C CNN
F 1 "LM358" V 4866 2200 50  0000 C CNN
F 2 "" H 5100 2200 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2904-n.pdf" H 5100 2200 50  0001 C CNN
	3    5100 2200
	0    1    1    0   
$EndComp
$Comp
L Amplifier_Operational:LM358 U?
U 1 1 6331977C
P 5100 3100
F 0 "U?" H 5100 3467 50  0000 C CNN
F 1 "LM358" H 5100 3376 50  0000 C CNN
F 2 "" H 5100 3100 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2904-n.pdf" H 5100 3100 50  0001 C CNN
	1    5100 3100
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LM358 U?
U 2 1 63319782
P 5100 3700
F 0 "U?" H 5100 4067 50  0000 C CNN
F 1 "LM358" H 5100 3976 50  0000 C CNN
F 2 "" H 5100 3700 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2904-n.pdf" H 5100 3700 50  0001 C CNN
	2    5100 3700
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LM358 U?
U 3 1 63319788
P 5100 4200
F 0 "U?" V 4775 4200 50  0000 C CNN
F 1 "LM358" V 4866 4200 50  0000 C CNN
F 2 "" H 5100 4200 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2904-n.pdf" H 5100 4200 50  0001 C CNN
	3    5100 4200
	0    1    1    0   
$EndComp
Wire Wire Line
	2550 1550 2950 1550
Wire Wire Line
	2950 1550 2950 4550
Wire Wire Line
	3250 1050 3250 1650
Wire Wire Line
	5450 2550 5450 2100
Wire Wire Line
	5450 2100 5400 2100
Wire Wire Line
	5450 4550 5450 4100
Wire Wire Line
	5450 4100 5400 4100
$Comp
L power:GND #PWR?
U 1 1 633215CE
P 4800 4100
F 0 "#PWR?" H 4800 3850 50  0001 C CNN
F 1 "GND" V 4805 3972 50  0000 R CNN
F 2 "" H 4800 4100 50  0001 C CNN
F 3 "" H 4800 4100 50  0001 C CNN
	1    4800 4100
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 63321F51
P 4800 2100
F 0 "#PWR?" H 4800 1850 50  0001 C CNN
F 1 "GND" V 4805 1972 50  0000 R CNN
F 2 "" H 4800 2100 50  0001 C CNN
F 3 "" H 4800 2100 50  0001 C CNN
	1    4800 2100
	0    1    1    0   
$EndComp
Wire Wire Line
	3250 2550 5450 2550
Wire Wire Line
	2950 4550 5450 4550
$Comp
L Device:R_POT RV?
U 1 1 63338EB1
P 4250 1800
F 0 "RV?" H 4181 1846 50  0000 R CNN
F 1 "R_POT" H 4181 1755 50  0000 R CNN
F 2 "" H 4250 1800 50  0001 C CNN
F 3 "~" H 4250 1800 50  0001 C CNN
	1    4250 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 1800 4800 1800
$Comp
L Device:R_POT RV?
U 1 1 6333C001
P 4250 1200
F 0 "RV?" H 4181 1246 50  0000 R CNN
F 1 "R_POT" H 4181 1155 50  0000 R CNN
F 2 "" H 4250 1200 50  0001 C CNN
F 3 "~" H 4250 1200 50  0001 C CNN
	1    4250 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 1200 4800 1200
$Comp
L power:GND #PWR?
U 1 1 6333C8E0
P 4250 1950
F 0 "#PWR?" H 4250 1700 50  0001 C CNN
F 1 "GND" H 4255 1777 50  0000 C CNN
F 2 "" H 4250 1950 50  0001 C CNN
F 3 "" H 4250 1950 50  0001 C CNN
	1    4250 1950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 6333CDCF
P 4250 1350
F 0 "#PWR?" H 4250 1100 50  0001 C CNN
F 1 "GND" H 4255 1177 50  0000 C CNN
F 2 "" H 4250 1350 50  0001 C CNN
F 3 "" H 4250 1350 50  0001 C CNN
	1    4250 1350
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT RV?
U 1 1 63345986
P 4250 3800
F 0 "RV?" H 4181 3846 50  0000 R CNN
F 1 "R_POT" H 4181 3755 50  0000 R CNN
F 2 "" H 4250 3800 50  0001 C CNN
F 3 "~" H 4250 3800 50  0001 C CNN
	1    4250 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 3800 4800 3800
$Comp
L Device:R_POT RV?
U 1 1 6334598D
P 4250 3200
F 0 "RV?" H 4181 3246 50  0000 R CNN
F 1 "R_POT" H 4181 3155 50  0000 R CNN
F 2 "" H 4250 3200 50  0001 C CNN
F 3 "~" H 4250 3200 50  0001 C CNN
	1    4250 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 3200 4800 3200
$Comp
L power:GND #PWR?
U 1 1 63345994
P 4250 3950
F 0 "#PWR?" H 4250 3700 50  0001 C CNN
F 1 "GND" H 4255 3777 50  0000 C CNN
F 2 "" H 4250 3950 50  0001 C CNN
F 3 "" H 4250 3950 50  0001 C CNN
	1    4250 3950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 6334599A
P 4250 3350
F 0 "#PWR?" H 4250 3100 50  0001 C CNN
F 1 "GND" H 4255 3177 50  0000 C CNN
F 2 "" H 4250 3350 50  0001 C CNN
F 3 "" H 4250 3350 50  0001 C CNN
	1    4250 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 1050 3250 1050
Connection ~ 3250 1050
Wire Wire Line
	4250 1650 3250 1650
Connection ~ 3250 1650
Wire Wire Line
	3250 1650 3250 2550
Wire Wire Line
	3250 2550 3250 3050
Wire Wire Line
	3250 3050 4250 3050
Connection ~ 3250 2550
Wire Wire Line
	3250 3050 3250 3650
Wire Wire Line
	3250 3650 4250 3650
Connection ~ 3250 3050
Wire Notes Line
	4900 2650 5300 2650
Wire Notes Line
	5300 2650 5300 4150
Wire Notes Line
	5300 4150 4900 4150
Wire Notes Line
	4900 4150 4900 2650
Wire Notes Line
	4900 650  5300 650 
Wire Notes Line
	5300 650  5300 2150
Wire Notes Line
	5300 2150 4900 2150
Wire Notes Line
	4900 2150 4900 650 
Wire Wire Line
	5400 3100 5650 3100
Wire Wire Line
	5650 3100 5650 2200
Wire Wire Line
	5650 550  4650 550 
Wire Wire Line
	4650 1000 4800 1000
Wire Wire Line
	4650 550  4650 1000
Wire Wire Line
	4800 1600 4600 1600
Wire Wire Line
	4600 1600 4600 500 
Wire Wire Line
	4600 500  5700 500 
Wire Wire Line
	5700 500  5700 2350
Wire Wire Line
	5700 3700 5400 3700
Text Notes 4950 4350 0    50   ~ 0
5V-Out\nOpAmp
Text Notes 4950 2350 0    50   ~ 0
24V-Out\nOpAmp
$Comp
L Connector:Screw_Terminal_01x03 J?
U 1 1 63429B53
P 8150 1200
F 0 "J?" H 8230 1242 50  0000 L CNN
F 1 "Screw_Terminal_01x03" H 8230 1151 50  0000 L CNN
F 2 "" H 8150 1200 50  0001 C CNN
F 3 "~" H 8150 1200 50  0001 C CNN
	1    8150 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 1100 7950 1100
Wire Wire Line
	5400 1700 5750 1700
Wire Wire Line
	5750 1700 5750 1200
Wire Wire Line
	5750 1200 7950 1200
$Comp
L power:GND #PWR?
U 1 1 6342D1B7
P 7950 1300
F 0 "#PWR?" H 7950 1050 50  0001 C CNN
F 1 "GND" H 7955 1127 50  0000 C CNN
F 2 "" H 7950 1300 50  0001 C CNN
F 3 "" H 7950 1300 50  0001 C CNN
	1    7950 1300
	0    1    1    0   
$EndComp
$Comp
L Connector:Conn_01x01_Male J?
U 1 1 634336AF
P 8200 2050
F 0 "J?" H 8172 1982 50  0000 R CNN
F 1 "Conn_01x01_Male" H 8172 2073 50  0000 R CNN
F 2 "" H 8200 2050 50  0001 C CNN
F 3 "~" H 8200 2050 50  0001 C CNN
	1    8200 2050
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J?
U 1 1 63434368
P 8200 2200
F 0 "J?" H 8172 2132 50  0000 R CNN
F 1 "Conn_01x01_Male" H 8172 2223 50  0000 R CNN
F 2 "" H 8200 2200 50  0001 C CNN
F 3 "~" H 8200 2200 50  0001 C CNN
	1    8200 2200
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J?
U 1 1 634347F4
P 8200 2350
F 0 "J?" H 8172 2282 50  0000 R CNN
F 1 "Conn_01x01_Male" H 8172 2373 50  0000 R CNN
F 2 "" H 8200 2350 50  0001 C CNN
F 3 "~" H 8200 2350 50  0001 C CNN
	1    8200 2350
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J?
U 1 1 63434E46
P 8200 2500
F 0 "J?" H 8172 2432 50  0000 R CNN
F 1 "Conn_01x01_Male" H 8172 2523 50  0000 R CNN
F 2 "" H 8200 2500 50  0001 C CNN
F 3 "~" H 8200 2500 50  0001 C CNN
	1    8200 2500
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J?
U 1 1 63435092
P 8200 2650
F 0 "J?" H 8172 2582 50  0000 R CNN
F 1 "Conn_01x01_Male" H 8172 2673 50  0000 R CNN
F 2 "" H 8200 2650 50  0001 C CNN
F 3 "~" H 8200 2650 50  0001 C CNN
	1    8200 2650
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J?
U 1 1 63435409
P 8200 2800
F 0 "J?" H 8172 2732 50  0000 R CNN
F 1 "Conn_01x01_Male" H 8172 2823 50  0000 R CNN
F 2 "" H 8200 2800 50  0001 C CNN
F 3 "~" H 8200 2800 50  0001 C CNN
	1    8200 2800
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J?
U 1 1 634355C3
P 8200 2950
F 0 "J?" H 8172 2882 50  0000 R CNN
F 1 "Conn_01x01_Male" H 8172 2973 50  0000 R CNN
F 2 "" H 8200 2950 50  0001 C CNN
F 3 "~" H 8200 2950 50  0001 C CNN
	1    8200 2950
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J?
U 1 1 63435818
P 8200 3100
F 0 "J?" H 8172 3032 50  0000 R CNN
F 1 "Conn_01x01_Male" H 8172 3123 50  0000 R CNN
F 2 "" H 8200 3100 50  0001 C CNN
F 3 "~" H 8200 3100 50  0001 C CNN
	1    8200 3100
	-1   0    0    1   
$EndComp
Wire Wire Line
	5450 4550 6500 4550
Wire Wire Line
	7450 4550 7450 3100
Wire Wire Line
	7450 3100 8000 3100
Connection ~ 5450 4550
$Comp
L power:GND #PWR?
U 1 1 63436912
P 8000 2050
F 0 "#PWR?" H 8000 1800 50  0001 C CNN
F 1 "GND" H 8005 1877 50  0000 C CNN
F 2 "" H 8000 2050 50  0001 C CNN
F 3 "" H 8000 2050 50  0001 C CNN
	1    8000 2050
	0    1    1    0   
$EndComp
Wire Wire Line
	8000 2200 5650 2200
Connection ~ 5650 2200
Wire Wire Line
	5650 2200 5650 550 
Wire Wire Line
	8000 2350 5700 2350
Connection ~ 5700 2350
Wire Wire Line
	5700 2350 5700 3700
$Comp
L Amplifier_Operational:LM358 U?
U 1 1 63492338
P 5100 5150
F 0 "U?" H 5100 5517 50  0000 C CNN
F 1 "LM358" H 5100 5426 50  0000 C CNN
F 2 "" H 5100 5150 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2904-n.pdf" H 5100 5150 50  0001 C CNN
	1    5100 5150
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LM358 U?
U 2 1 63494496
P 5100 5700
F 0 "U?" H 5100 6067 50  0000 C CNN
F 1 "LM358" H 5100 5976 50  0000 C CNN
F 2 "" H 5100 5700 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2904-n.pdf" H 5100 5700 50  0001 C CNN
	2    5100 5700
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LM358 U?
U 3 1 63497476
P 5100 6200
F 0 "U?" V 4775 6200 50  0000 C CNN
F 1 "LM358" V 4866 6200 50  0000 C CNN
F 2 "" H 5100 6200 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2904-n.pdf" H 5100 6200 50  0001 C CNN
	3    5100 6200
	0    1    1    0   
$EndComp
Wire Notes Line
	4900 4700 5300 4700
Wire Notes Line
	5300 6150 4900 6150
$Comp
L Amplifier_Operational:LM358 U?
U 1 1 6349F102
P 5100 6600
F 0 "U?" H 5100 6967 50  0000 C CNN
F 1 "LM358" H 5100 6876 50  0000 C CNN
F 2 "" H 5100 6600 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2904-n.pdf" H 5100 6600 50  0001 C CNN
	1    5100 6600
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LM358 U?
U 2 1 634A1040
P 5100 7150
F 0 "U?" H 5100 7517 50  0000 C CNN
F 1 "LM358" H 5100 7426 50  0000 C CNN
F 2 "" H 5100 7150 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2904-n.pdf" H 5100 7150 50  0001 C CNN
	2    5100 7150
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LM358 U?
U 3 1 634A29AB
P 5100 7700
F 0 "U?" V 4775 7700 50  0000 C CNN
F 1 "LM358" V 4866 7700 50  0000 C CNN
F 2 "" H 5100 7700 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2904-n.pdf" H 5100 7700 50  0001 C CNN
	3    5100 7700
	0    1    1    0   
$EndComp
Wire Notes Line
	4900 4700 4900 7650
Wire Notes Line
	5300 7650 4900 7650
Wire Notes Line
	5300 4700 5300 7650
$Comp
L power:GND #PWR?
U 1 1 634A712E
P 4800 6100
F 0 "#PWR?" H 4800 5850 50  0001 C CNN
F 1 "GND" V 4805 5972 50  0000 R CNN
F 2 "" H 4800 6100 50  0001 C CNN
F 3 "" H 4800 6100 50  0001 C CNN
	1    4800 6100
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 634A82C9
P 4800 7600
F 0 "#PWR?" H 4800 7350 50  0001 C CNN
F 1 "GND" V 4805 7472 50  0000 R CNN
F 2 "" H 4800 7600 50  0001 C CNN
F 3 "" H 4800 7600 50  0001 C CNN
	1    4800 7600
	0    1    1    0   
$EndComp
Wire Wire Line
	5400 7600 6500 7600
Wire Wire Line
	6500 7600 6500 6100
Connection ~ 6500 4550
Wire Wire Line
	6500 4550 7450 4550
Wire Wire Line
	5400 6100 6500 6100
Connection ~ 6500 6100
Wire Wire Line
	6500 6100 6500 4550
$Comp
L Device:R_POT RV?
U 1 1 634AD3BD
P 4300 5050
F 0 "RV?" H 4231 5096 50  0000 R CNN
F 1 "R_POT" H 4231 5005 50  0000 R CNN
F 2 "" H 4300 5050 50  0001 C CNN
F 3 "~" H 4300 5050 50  0001 C CNN
	1    4300 5050
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT RV?
U 1 1 634ADCA2
P 4300 5600
F 0 "RV?" H 4231 5646 50  0000 R CNN
F 1 "R_POT" H 4231 5555 50  0000 R CNN
F 2 "" H 4300 5600 50  0001 C CNN
F 3 "~" H 4300 5600 50  0001 C CNN
	1    4300 5600
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT RV?
U 1 1 634AE5E4
P 4300 6500
F 0 "RV?" H 4231 6546 50  0000 R CNN
F 1 "R_POT" H 4231 6455 50  0000 R CNN
F 2 "" H 4300 6500 50  0001 C CNN
F 3 "~" H 4300 6500 50  0001 C CNN
	1    4300 6500
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT RV?
U 1 1 634AE8D7
P 4300 7050
F 0 "RV?" H 4231 7096 50  0000 R CNN
F 1 "R_POT" H 4231 7005 50  0000 R CNN
F 2 "" H 4300 7050 50  0001 C CNN
F 3 "~" H 4300 7050 50  0001 C CNN
	1    4300 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 5050 4800 5050
Wire Wire Line
	4450 5600 4800 5600
Wire Wire Line
	4450 6500 4800 6500
Wire Wire Line
	4450 7050 4800 7050
Wire Wire Line
	5400 5150 5450 5150
Wire Wire Line
	5450 5150 5450 5400
Wire Wire Line
	5450 5400 4750 5400
Wire Wire Line
	4750 5400 4750 5250
Wire Wire Line
	4750 5250 4800 5250
Wire Wire Line
	5400 5700 5450 5700
Wire Wire Line
	5450 5700 5450 5950
Wire Wire Line
	5450 5950 4750 5950
Wire Wire Line
	4750 5950 4750 5800
Wire Wire Line
	4750 5800 4800 5800
Wire Wire Line
	5400 6600 5450 6600
Wire Wire Line
	5450 6600 5450 6850
Wire Wire Line
	5450 6850 4750 6850
Wire Wire Line
	4750 6850 4750 6700
Wire Wire Line
	4750 6700 4800 6700
Wire Wire Line
	5400 7150 5450 7150
Wire Wire Line
	5450 7150 5450 7400
Wire Wire Line
	5450 7400 4750 7400
Wire Wire Line
	4750 7400 4750 7250
Wire Wire Line
	4750 7250 4800 7250
Wire Wire Line
	5450 5150 5800 5150
Wire Wire Line
	5800 5150 5800 2500
Wire Wire Line
	5800 2500 8000 2500
Connection ~ 5450 5150
Wire Wire Line
	5450 5700 5850 5700
Wire Wire Line
	5850 5700 5850 2650
Wire Wire Line
	5850 2650 8000 2650
Connection ~ 5450 5700
Wire Wire Line
	5450 6600 5900 6600
Wire Wire Line
	5900 6600 5900 2800
Wire Wire Line
	5900 2800 8000 2800
Connection ~ 5450 6600
Wire Wire Line
	5450 7150 5950 7150
Wire Wire Line
	5950 7150 5950 2950
Wire Wire Line
	5950 2950 8000 2950
Connection ~ 5450 7150
$Comp
L power:GND #PWR?
U 1 1 634C759F
P 4300 5200
F 0 "#PWR?" H 4300 4950 50  0001 C CNN
F 1 "GND" H 4305 5027 50  0000 C CNN
F 2 "" H 4300 5200 50  0001 C CNN
F 3 "" H 4300 5200 50  0001 C CNN
	1    4300 5200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 634C7BC2
P 4300 5750
F 0 "#PWR?" H 4300 5500 50  0001 C CNN
F 1 "GND" H 4305 5577 50  0000 C CNN
F 2 "" H 4300 5750 50  0001 C CNN
F 3 "" H 4300 5750 50  0001 C CNN
	1    4300 5750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 634C7EE6
P 4300 6650
F 0 "#PWR?" H 4300 6400 50  0001 C CNN
F 1 "GND" H 4305 6477 50  0000 C CNN
F 2 "" H 4300 6650 50  0001 C CNN
F 3 "" H 4300 6650 50  0001 C CNN
	1    4300 6650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 634C81C3
P 4300 7200
F 0 "#PWR?" H 4300 6950 50  0001 C CNN
F 1 "GND" H 4305 7027 50  0000 C CNN
F 2 "" H 4300 7200 50  0001 C CNN
F 3 "" H 4300 7200 50  0001 C CNN
	1    4300 7200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 5000 3850 5450
Wire Wire Line
	3850 5450 4300 5450
Wire Wire Line
	3800 5100 3800 6350
Wire Wire Line
	3800 6350 4300 6350
$Comp
L Connector:DB9_Male J?
U 1 1 6361D843
P 1350 3050
F 0 "J?" H 1268 2358 50  0000 C CNN
F 1 "DB9_Male" H 1268 2449 50  0000 C CNN
F 2 "" H 1350 3050 50  0001 C CNN
F 3 " ~" H 1350 3050 50  0001 C CNN
	1    1350 3050
	-1   0    0    1   
$EndComp
Wire Wire Line
	1650 2650 2250 2650
Wire Wire Line
	2250 1850 2250 2650
Wire Wire Line
	1650 2750 2250 2750
Wire Wire Line
	2250 2750 2250 2650
Connection ~ 2250 2650
Wire Wire Line
	1650 3350 1850 3350
Wire Wire Line
	1850 3350 1850 1550
Connection ~ 1850 1550
Wire Wire Line
	1850 1550 1950 1550
Wire Wire Line
	1650 3450 1850 3450
Wire Wire Line
	1850 3450 1850 3350
Connection ~ 1850 3350
Wire Wire Line
	1850 1550 1850 1050
Wire Wire Line
	1850 1050 3250 1050
Wire Wire Line
	1650 2950 4750 2950
Wire Wire Line
	4750 2950 4750 3000
Wire Wire Line
	4750 3000 4800 3000
Wire Wire Line
	1650 3150 3150 3150
Wire Wire Line
	3150 3150 3150 3000
Wire Wire Line
	3150 3000 4700 3000
Wire Wire Line
	4700 3000 4700 3600
Wire Wire Line
	4700 3600 4800 3600
Wire Wire Line
	1650 2850 2250 2850
Wire Wire Line
	2250 2850 2250 4900
Wire Wire Line
	2250 4900 4300 4900
Wire Wire Line
	1650 3050 2200 3050
Wire Wire Line
	2200 3050 2200 5000
Wire Wire Line
	2200 5000 3850 5000
Wire Wire Line
	1650 3250 2150 3250
Wire Wire Line
	2150 3250 2150 5100
Wire Wire Line
	2150 5100 3800 5100
NoConn ~ 3800 6900
Wire Wire Line
	3800 6900 4300 6900
$EndSCHEMATC
