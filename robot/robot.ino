#include <Servo.h>

// `t` is the variable the variable that stores the recived commands
char t;

// `::DEBUG` is read before execution of any method in `DEBUG` class.
// It will only execute if value is set to `true`
const bool DEBUG = true;


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

class DEBUG;
class MOTOR;
class SHOOTER;
class RECEIVER;


// `DEBUG` class is used for debugging purposes.
// set the `::DEBUG` variable to true to enable the execution of its methods
class DEBUG
{
  public:
    // The `DEBUG::print` method is used to print an unknown number of variables.
    // Specify the number of variables to print as the first argument
    static void print(int argCount, ...) {
      if (!(::DEBUG)) {
        return ;
      }
      va_list args;
      va_start(args, argCount);
      for (int i = 0; i < argCount; i++) {
        String arg = va_arg(args, String);
        Serial.print(arg);
      }
      Serial.println();
      va_end(args);
    }
};

// The `MOTOR` class contains the methods and variables used to control the motors.
// To begin, initialise a class instance inside the `setup` function, this will set the pins nessassary to control the motors as `OUTPUT`.
// Advice, because the class members are mostly static, do not create a new instance other than the one inside `setup` but 
// instead use the class name as the scope specifyer
class MOTOR
{
  protected:
    static const int LEFT_FRONT = 8;
    static const int LEFT_REAR = 11;
    static const int RIGHT_FRONT = 12;
    static const int RIGHT_REAR = 13;

  public:
    MOTOR() {
      pinMode(LEFT_FRONT, OUTPUT);
      pinMode(LEFT_REAR, OUTPUT);
      pinMode(RIGHT_FRONT, OUTPUT);
      pinMode(RIGHT_REAR, OUTPUT);
    }

    /* Used to control the motor output pins.
    If called without arguments, it will set all pins to low */
    static void motor_control(int left_front = LOW, int left_rear = LOW, int right_front = LOW, int right_rear = LOW) {
      digitalWrite(LEFT_FRONT, left_front);
      digitalWrite(LEFT_REAR, left_rear);
      digitalWrite(RIGHT_FRONT, right_front);
      digitalWrite(RIGHT_REAR, right_rear);
    }
    static void move(char direction){
      switch(direction)
      {
        case 'F':    //move forward(all motors rotate in forward direction)
          motor_control(HIGH, LOW, HIGH);
          break;
        case 'B':    //move reverse (all   motors rotate in reverse direction)
          motor_control(LOW, HIGH, LOW, HIGH);
          break;
        case 'L':    //turn left (right side motors rotate in forward direction, left side motors go backwards)
          motor_control(LOW, HIGH, HIGH);
          break;
        case 'R':    //turn right (left side motors rotate in forward direction, right side motors go backwards)
          motor_control(HIGH, LOW, LOW, HIGH);
          break;
        case 'S':    //STOP (all motors stop)
          motor_control();
          break;
      }
    }
};

class SHOOTER
{
  protected:
    static const int SHOOTER2 = 10;
    static const int SHOOTER1 = 6;
  public:
    static Servo S1;
    static Servo S2;
    class LOADER {
      protected:
        static const int servo1 = 5; // first servo pin
        static const int servo2 = 6; // second servo pin            
      public:
        static Servo L1;
        static Servo L2;
        LOADER(){
          L1.attach(servo1);
          L2.attach(servo2);
        }
        static void set(float p) {
          L1.write(p);
          L2.write(p);
        }
        static void load() {
          set(90);
          delay(1000);
          set(0);
        }
    };
    SHOOTER(){
      S1.attach(SHOOTER1);
      S2.attach(SHOOTER2);
    }
    void shoot(float f);
};

class RECEIVER {
  public:
  static const int r = 9;
  static bool is_open;
  static Servo R1;
  RECEIVER(){
    R1.attach(r);
  }
  static void open(){
    switch (is_open){
      case true:
        R1.write(0);
        break;
      case false:
        R1.write(90);
        break;
    }
    is_open = !is_open;
  }
};

// Initilisation of Servo objects
Servo SHOOTER::S1, SHOOTER::S2, SHOOTER::LOADER::L1, SHOOTER::LOADER::L2, RECEIVER::R1;

void setup() {
  MOTOR motor;
  SHOOTER shooter;
  RECEIVER reciver;
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
  }
}
