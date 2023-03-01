#ifndef MOTORS_H
#define MOTORS_H

#include <Arduino.h>

// The `MOTOR` class contains the methods and variables used to control the motors.
// To begin, initialise a class instance inside the `setup` function, this will set the pins nessassary to control the motors as `OUTPUT`.
// Advice, because the class members are mostly static, do not create a new instance other than the one inside `setup` but 
// instead use the class name as the scope specifyer

class MOTOR
{
  protected:
    static const int LEFT_FRONT;
    static const int LEFT_REAR;
    static const int RIGHT_FRONT;
    static const int RIGHT_REAR;

  public:
    MOTOR();
    
    /* Used to control the motor output pins.
    If called without arguments, it will set all pins to low */
    static void motor_control(int left_front = LOW, int left_rear = LOW, int right_front = LOW, int right_rear = LOW);
    
    // Used to move as specified in passed char.
    // commands are `F, B, L, R, S` for foreward, backward, left, right, and stop
    static void move(char direction);
};

#endif

