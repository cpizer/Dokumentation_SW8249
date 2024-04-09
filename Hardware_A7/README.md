Diese Hardware ist in der Komponente die im Schaltplan A7 heisst installiert.

R4,R6,C3 mit circuitlab etwa auf 1kHz im timedomain eingestellt. R4
und R6 halbieren die Eingangsspannung von den angenommenen 40V auf
20V. Die negative Halbwelle fliest nur durch R4 und D6. Habe mit
maximal 40V gerechnet. Sind dann nur 70mW. also passt 1/8W
Widerstand. Die positive Halbwelle wird auf die 5V Schiene
geladen. Diese wird jedoch von der 2,5V Spannungsteilerschaltung so
stark belastet, dass auf keinen Fall rückgespeist wird.

Schmitttrigger R3 und R5 sind dimensioniert auf 3V ein, 2V
aus. Achtung, die OP-AMPS sind im nicht rail to rail!

teste dass der schmitt trigger ausreichend sicher an geht in den
extremlagen wiel die opamps ja nicht rail to rail sind. wenn nicht,
vergrößere R5.

Ohne R6 kann "Signal Licht" frei floaten. Der Widerstand verhindert
das.

D1 ist interessant, wenn die Versorgungsspannung fehlt. Man kann die
Versorgungsspannung jedoch nicht überhöhen, dagegen schützt D5.

D2 gibt die parasitäre Versorgung dann nach aussen weiter und schützt
U1.

C3 ist so dimensioniert dass 1 kHz Grenzfrequenz überschritten
werden. Weil das Original Arduino Programm mit der millis funktion die
Geschwindigkeiten bestimmt und diese maximal 1kHz aufgelöst sein kann.

R1 und R2 sind ein Spannungsteiler zur Erzeugung von 2,5V. Sie dienen
aber auch einer Grundlast um die parasitäre Erzeugung von 5V zu
unterbinden.

R7 ist der Stromshunt für den Kardansensor. Der Kardansensor soll 7mA
oder 14mA liefern. Also ist der Trennpunkt bei 10,5mA. Die Spannung
soll dabei 2,5V sein. Der nächste Widerstand ist dann 220Ohm. R7 soll
wenn er 12V direkt bekommt nicht durchbrennen. 654mW wäre
theoretisch. Daher ein 1W Widerstand. R8 und C6 sind ein
Tiefpass. Wieder eingestellt auf 1kHz Grenzfrequenz.

Auslegung des Schmitt Triggers U4D: 7mA bei 220 Ohm sind 1,54V. 14mA
bei 220 Ohm sind 3,08V. Den Bereich dazwischen dritteln ergibt die
zwei Schranken 2,05V und 2,57V. Mit dem Onlinetool berechnet:
R10=10k R9=1,5k

VD ist die spannung der mitte des 5V opamp ausgangs. also 0-3,5V also
1,75V. mit realen widerständen ist sie 1,85V

https://www.aaabbb.de/NonInvertingSchmittTrigger/NonInvertingSchmittTrigger_en.php

Bedenke den Stromverbrauch des Servos! Er kann die 5V
runterziehen. Mit dem alten defekten Servo der sich nicht mehr drehte
war die 5V Spannung auf 2,6V oder so zusammengebrochen und der Wandler
wurde heiss. Max Servostrom (des neuen nicht defekten Servos) ist
ca. 200mA. der 5V Linear Wandler wird nach einer Minute Servo
dauerlauf hot und regelt runter. Ist auch logisch bei 24V input. Habe
daher den Servopower entkoppelt mit einem Schaltregler.

Die Drehzahlanzeige hat einen Widerstand von 2,5kOhm.
