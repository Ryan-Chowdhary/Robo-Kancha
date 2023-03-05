#include "Receiver.h"

const int RECEIVER::r = 23;
Servo RECEIVER::R1;
RECEIVER::RECEIVER(){
  R1.attach(r);
}
static void RECEIVER::open() {
  switch (is_open) {
    case true:
      R1.write(0);
      break;
    case false:
      R1.write(90);
      break;
  }
  is_open = !is_open;
}