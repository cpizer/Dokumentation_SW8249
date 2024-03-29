#ifndef __MESSSPEED_H
#define __MESSSPEED_H

/*

Gemeint ist die Seilgeschwindigkeit.
Diese wird entweder von so einem mit Riemen angetriebenen seitlichen Anbauteil ermittelt
oder über einen Hallsensor der über der Turbokupplung hängt.
Einer davon ist blind.
Muss noch ermittelt werden welches Kabel angeschlossen ist.
 
*/

extern float messSpeedFreq; // Hertz

void messSpeedSetup();
void messSpeedLoop();

#endif
