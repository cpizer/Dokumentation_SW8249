#include "messSpeed.h"
#include "messMotor.h"
#include "dispSpeed.h"
#include "dispMotor.h"

static unsigned long lastDebug;
static const bool doDebugSpeed = true;
static const bool doDebugMotor = true;


void setup()
{
  Serial.begin(115200);

  messMotorSetup();
  messSpeedSetup();
  dispMotorSetup();
  dispSpeedSetup();
  
  lastDebug = millis();
}


void loop()
{
  messMotorLoop();
  messSpeedLoop();

  const unsigned long now = millis();
  if (now - lastDebug > 1000) {
    if (doDebugSpeed) {
      Serial.print("Speed[Hz]: ");
      Serial.print(messSpeedFreq);
      Serial.print("   ");
    }
    if (doDebugMotor) {
      Serial.print("Motor[Hz]: ");
      Serial.print(messMotorFreq);
      Serial.print("   ");
    }
    if (doDebugSpeed || doDebugMotor) Serial.println();
  
    lastDebug = now;
  }

  dispMotorUPM = messMotorFreq * 3.33;
  dispSpeedKMH = messSpeedFreq * 0.07;
  
  dispMotorLoop();
  dispSpeedLoop();
}
