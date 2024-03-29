#ifndef __IDLESERVO_H
#define __IDLESERVO_H

#include <Servo.h>

class idleServo {
public:
  idleServo(int pin_);
  void writeMicroseconds(int value);
  void loop();
private:
  Servo myServo;  
  unsigned long lastChangeMillis;
  int oldValue;
  const int pin;
};

#endif
