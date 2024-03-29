#include "dispSpeed.h"

#include "idleServo.h"
#include <Arduino.h>

#define PIN_SERVO 6

static idleServo myServo(PIN_SERVO);

static const float linearM = -14.49152542;
static const float linearC = 2330.;
static const float clampMin = 620.;
static const float clampMax = 2330.;

float dispSpeedKMH;

/*

Kalibrierung der Anzeige 2023-12-29

bei M=1 und C=0 und clamp auf 100 und 2900:
ermittle die Werte wo der Servo sein mechanisches Limit hat und geh 50 davon weg.
mechanisch grade noch nicht am Limit sind 570 und 2380
nehme daher 620 und 2330
schraube zeiger auf 0 km/h bei 2330.
bei 620 ist dann 118 km/h

*/

void dispSpeedSetup()
{
  dispSpeedKMH = 0;
  pinMode(PIN_SERVO, OUTPUT);
}

void dispSpeedLoop()
{
  float y = dispSpeedKMH * linearM + linearC;
  if (y < clampMin) y = clampMin;
  if (y > clampMax) y = clampMax;
  myServo.writeMicroseconds(y);
  myServo.loop();
}
