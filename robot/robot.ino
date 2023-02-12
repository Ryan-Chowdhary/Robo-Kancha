// REMINDER: classes `SHOOTER` and its respective member methods and classes 
// have yet to be implemented
// And class `COMM` is yet to be defined

#include <Servo.h>
#include "Motors.h"
#include "Shooter.h"
#include "Debug.h"

// `t` is the variable the variable that stores the recived commands
char t;

// `DEBUG::IsDebug` is read before execution of any method in `DEBUG` class.
// It will only execute if value is set to `true`
const bool DEBUG::IsDebug = true;

template <typename T_ty> struct TypeInfo {
  static const char * name;
};
template <typename T_ty> const char * TypeInfo<T_ty>::name = "unknown";
// MACRO `TYPE_NAME` is used to obtain the object type of the object supplied.
// To add support for more object types, use the `MAKE_TYPE_INFO` MACRO with the object type you want to add suppport for
#define TYPE_NAME(var) TypeInfo< typeof(var) >::name
#define MAKE_TYPE_INFO(type)  template <> const char * TypeInfo<type>::name = #type;
MAKE_TYPE_INFO( int )
MAKE_TYPE_INFO( float )
MAKE_TYPE_INFO( short )
MAKE_TYPE_INFO( String )
MAKE_TYPE_INFO( char )
MAKE_TYPE_INFO( byte )

class COMM;

void setup() {
  MOTOR motor;
  SHOOTER shooter;
  Serial.begin(9600);
}

void loop() {
  // Recieve the command and store it to char `t`
  if (Serial.available()) {
    t = Serial.read();
    if (isdigit(t)) {
      t = (int) t;
    }
    DEBUG::print(3, t, ", ", TYPE_NAME(t));
  }

  // If "t" is not a motion command then restart loop function
  if (isdigit(t)){return;}
  switch(t)
  {
    case 'F':    //move forward(all motors rotate in forward direction)
      MOTOR::motor_control(HIGH, LOW, HIGH);
      break;
    case 'B':    //move reverse (all   motors rotate in reverse direction)
      MOTOR::motor_control(LOW, HIGH, LOW, HIGH);
      break;
    case 'L':    //turn left (right side motors rotate in forward direction, left side motors go backwards)
      MOTOR::motor_control(LOW, HIGH, HIGH);
      break;
    case 'R':    //turn right (left side motors rotate in forward direction, right side motors go backwards)
      MOTOR::motor_control(HIGH, LOW, LOW, HIGH);
      break;
    case 'S':    //STOP (all motors stop)
      MOTOR::motor_control();
      break;      
  }
}
