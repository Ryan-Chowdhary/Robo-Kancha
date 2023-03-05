#ifndef RECEIVER_H
#define RECEIVER_H

#include <Arduino.h>
#include <Servo.h>

class RECEIVER {
  public:
  static const int r;
  static bool is_open;
  static Servo R1;
  
  RECEIVER();

  //`MOTOR::open` method is used to open/close the reciver.
  //The state of the reciver is stored in `is_open` bool.
  static void open();
};

#endif