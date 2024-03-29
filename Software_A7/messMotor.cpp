#include "messMotor.h"

#include <Arduino.h>

#define PIN_PULSE 3

volatile static unsigned long newPulseIrqDisable; // only access with interrupts disabled!
volatile static bool newPulseDefinedIrqDisable; // only access with interrupts disabled!

static unsigned long lastPulse;
static bool lastPulseDefined;

static const unsigned long maxPulseLength = 3000000;

float messMotorFreq;

/*

Kalibrierung der Messwerte:

Um zu Kalibrieren, schau dass die Werte identisch zur Kardanwelle sind wenn diese nicht gebremst ist.
Achtung, nimm dabei die korrekten Messwerte der Kardanwelle und nicht deren schon um 2,3 reduzierten Werte!

*/


static void pinPulseChangeHandler()
{
  newPulseIrqDisable = micros();
  newPulseDefinedIrqDisable = true;
}


void messMotorSetup()
{
  pinMode(PIN_PULSE, INPUT);
  newPulseDefinedIrqDisable = false;
  lastPulseDefined = false;
  messMotorFreq = 0;
  attachInterrupt(digitalPinToInterrupt(PIN_PULSE), pinPulseChangeHandler, RISING);
}


void messMotorLoop()
{
  noInterrupts();
  const unsigned long newPulse = newPulseIrqDisable;
  const bool newPulseDefined = newPulseDefinedIrqDisable;
  newPulseDefinedIrqDisable = false;
  interrupts();
  
  if (newPulseDefined) {
    if (lastPulseDefined) messMotorFreq = float(1000000) / float(newPulse - lastPulse);
    else lastPulseDefined = true;
    lastPulse = newPulse;  
  } else if (lastPulseDefined && micros() - lastPulse > maxPulseLength) {
    lastPulseDefined = false;
    messMotorFreq = 0;
  }
}
