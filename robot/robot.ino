// REMINDER: classes `SHOOTER` and its respective member methods and classes 
// have yet to be implemented
// And class `COMM` is yet to be defined

#include "Motors.h"
#include "Shooter.h"
#include "Receiver.h"
#include "Debug.h"

// `t` is the variable the variable that stores the recived commands
char t;

// `DEBUG::IsDebug` is read before execution of any method in `DEBUG` class.
// It will only execute if value is set to `true`
const bool DEBUG::IsDebug = false;

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
MAKE_TYPE_INFO( bool )

void setup() {
  MOTOR motor;
  SHOOTER shooter;
  RECEIVER receiver;
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

  switch (t){
    default:
      MOTOR::move(t);
      break;
  }
}
