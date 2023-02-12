#ifndef SHOOTER_H
#define SHOOTER_H

#include <Arduino.h>
#include <Servo.h>

// `SHOOTER` class stores the methods and variables neccassary 
// to control the shooter mechanism
class SHOOTER
{
  protected:
    static const int SHOOTER1;
    static const int SHOOTER2;
    static void set(float angle);

  public:
    static Servo S1;
    static Servo S2;

    // `LOADER` class stores the methods and variables neccessary
    // to control the loader mechanism
    class LOADER {
      protected:
        static const int servo1;  // first servo pin
        static const int servo2;  // second servo pin

        // `set` method is used to control the angle at
        // which the loader mechanism servos should turn
        static void set(float p);

      public:
        static Servo L1;
        static Servo L2;

        LOADER();
        // `load` method is used to load the balls by calling `set` with `90` degrees as its argument.
        // the delay is set to `1 second`
        static void load();
    };

    SHOOTER();
    // `shoot` method is used to make the shooting mechanism shoot the balls.
    void shoot(float f);
};

#endif
