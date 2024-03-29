#include "dispMotor.h"

#include <Arduino.h>

#define PIN_DISPLAY_PWM 5
#define PIN_DISPLAY_DIR 4

static const float linearM = 0.03216666667;
static const float linearC = -47.;
static const float clampMin = -49.;
static const float clampMax = 51.5;

float dispMotorUPM;

/*

Kalibrierung der Anzeige 2023-12-29

bei M=1 und C=0 und clamp auf +-60 ermittelt:
-46 liegt noch nicht auf.
-47 liegt auf.
Verwende daher -47 als 0 U/min
49 ist bisschen ünter 3000
50 ist bisschen über 3000
verwende daher 49.5 als 3000 U/min

Habe damit rechnerisch die Werte für 1000 und 2000 U/min ermittelt und getestst. Passt.

Als Clampwerte wurden die Werte von 0 und 3000 jeweils um 2 erweitert.

*/

void dispMotorSetup()
{
  dispMotorUPM = 0;
  pinMode(PIN_DISPLAY_DIR, OUTPUT);
  pinMode(PIN_DISPLAY_PWM, OUTPUT);
}

void dispMotorLoop()
{
  float y = dispMotorUPM * linearM + linearC;
  if (y < clampMin) y = clampMin;
  if (y > clampMax) y = clampMax;
  int i = y;
  if (i < 0) {
    digitalWrite(PIN_DISPLAY_DIR, LOW);
    analogWrite(PIN_DISPLAY_PWM, -i);
  } else {
    digitalWrite(PIN_DISPLAY_DIR, HIGH);
    analogWrite(PIN_DISPLAY_PWM, 255-i);
  }
}
