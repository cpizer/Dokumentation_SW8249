#include "messSpeed.h"

#include <Arduino.h>

#define PIN_PULSE 2

volatile static unsigned long newPulseIrqDisable; // only access with interrupts disabled!
volatile static bool newPulseDefinedIrqDisable; // only access with interrupts disabled!

static unsigned long lastPulse;
static bool lastPulseDefined;

static const unsigned long maxPulseLength = 3000000;

float messSpeedFreq;

/*

Kalibrierung der Messwerte:

In der technischen Doku der Winde steht, dass die Seiltrommeln 2,3 mal langsamer
laufen als die Kardanwelle (siehe Geschwindigkeitsnachweis).

*/


static void pinPulseChangeHandler()
{
  newPulseIrqDisable = micros();
  newPulseDefinedIrqDisable = true;
}


void messSpeedSetup()
{
  pinMode(PIN_PULSE, INPUT);
  newPulseDefinedIrqDisable = false;
  lastPulseDefined = false;
  messSpeedFreq = 0;
  attachInterrupt(digitalPinToInterrupt(PIN_PULSE), pinPulseChangeHandler, RISING);
}


void messSpeedLoop()
{
  noInterrupts();
  const unsigned long newPulse = newPulseIrqDisable;
  const bool newPulseDefined = newPulseDefinedIrqDisable;
  newPulseDefinedIrqDisable = false;
  interrupts();
  
  if (newPulseDefined) {
    if (lastPulseDefined) messSpeedFreq = float(1000000) / float(newPulse - lastPulse);
    else lastPulseDefined = true;
    lastPulse = newPulse;  
  } else if (lastPulseDefined && micros() - lastPulse > maxPulseLength) {
    lastPulseDefined = false;
    messSpeedFreq = 0;
  }
}
