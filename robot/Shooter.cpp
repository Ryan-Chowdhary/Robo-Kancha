// `SHOOTER` class stores the methods and variables neccassary 
// to control the shooter mechanism
#include "Shooter.h"

const int SHOOTER::SHOOTER1 = 5;
const int SHOOTER::SHOOTER2 = 6;
const int SHOOTER::LOADER::servo1 = 3;
const int SHOOTER::LOADER::servo2 = 4;

Servo SHOOTER::S1;
Servo SHOOTER::S2;
Servo SHOOTER::LOADER::L1;
Servo SHOOTER::LOADER::L2;

void SHOOTER::set(float angle) {
  S1.write(angle);
  S2.write(angle);
}

SHOOTER::SHOOTER() {
  S1.attach(SHOOTER1);
  S2.attach(SHOOTER2);
}

void SHOOTER::LOADER::set(float p) {
  L1.write(p);
  L2.write(p);
}

SHOOTER::LOADER::LOADER() {
  L1.attach(servo1);
  L2.attach(servo2);
}

void SHOOTER::LOADER::load() {
  set(90);
  delay(1000);
  set(0);
}

void SHOOTER::shoot(float f) {
  set(90);
}