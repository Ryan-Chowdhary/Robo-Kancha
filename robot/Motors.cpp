#include "Motors.h"

// The `MOTOR` class contains the methods and variables used to control the motors.
// To begin, initialise a class instance inside the `setup` function, this will set the pins nessassary to control the motors as `OUTPUT`.
// Advice, because the class members are mostly static, do not create a new instance other than the one inside `setup` but 
// instead use the class name as the scope specifyer

const int MOTOR::LEFT_FRONT = 13;
const int MOTOR::LEFT_REAR = 12;
const int MOTOR::RIGHT_FRONT = 11;
const int MOTOR::RIGHT_REAR = 10;

MOTOR::MOTOR() {
  pinMode(LEFT_FRONT, OUTPUT);
  pinMode(LEFT_REAR, OUTPUT);
  pinMode(RIGHT_FRONT, OUTPUT);
  pinMode(RIGHT_REAR, OUTPUT);
}

void MOTOR::motor_control(int left_front, int left_rear, int right_front, int right_rear) {
  digitalWrite(LEFT_FRONT, left_front);
  digitalWrite(LEFT_REAR, left_rear);
  digitalWrite(RIGHT_FRONT, right_front);
  digitalWrite(RIGHT_REAR, right_rear);
}
