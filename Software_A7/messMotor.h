#ifndef __MESSMOTOR_H
#define __MESSMOTOR_H

/*

Gemessen wird die Generatorfrequenz am Motor,
diese ist aber dank Generatorwicklungen und Generatorgetriebe
nicht identisch der Motordrehzahl.

*/

extern float messMotorFreq; // Hertz.

void messMotorSetup();
void messMotorLoop();

#endif
