#include "idleServo.h"

#include <Arduino.h>
#include <limits.h>

static const unsigned long maxAgeMillis = 10000; // auf jeden Fall deutlich mehr, als der Speed ermittler braucht um 0 U/min zu erkennen!

idleServo::idleServo(int pin_)
  : oldValue(INT_MIN), pin(pin_)
{
}

void idleServo::writeMicroseconds(int value)
{
  if (oldValue != value) {
    myServo.writeMicroseconds(value);
    if ( ! myServo.attached()) myServo.attach(pin); // do this after writeMicroseconds!
    lastChangeMillis = millis();
    oldValue = value;
  }
}

void idleServo::loop()
{
  if (myServo.attached() && millis() - lastChangeMillis > maxAgeMillis) {
    myServo.detach();
    /*

      detach wird einfach sofort gemacht. Es kann sein, dass es im Moment eines Pulses geschieht oder im Moment einer Pause.
      Die Servo Bibliothek hört einfach auf, als bleibt das Signal einfach high oder low je nachdem wann man detacht.
      Ich dachte das muss ich besser machen und habe manuell nach dem detach auf low geschaltet.
      Dann aber wird falls gerade high war ein zu kurzer Puls ausgegeben und das Servo fährt noch ein bisschen.
      Tatsächlich ist es daher die bessere Variante einfach nichts zu tun, denn
      der Servo fährt nicht, wenn er einen unendlichen high pulse empfängt.

      Eigentlich sollte die Servo library den letzten Puls ausgeben und danach abschalten. Das kann sie aber nicht.
     
    */
  }
}
