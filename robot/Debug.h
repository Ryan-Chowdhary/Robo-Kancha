#ifndef DEBUG_H
#define DEBUG_H

#include <Arduino.h>

// `DEBUG` class is used for debugging purposes.
// set the `::IsDebug` variable to true to enable the execution of its methods,
// Make sure to Define it at the beginning of the Program otherwise you will experience UndefinedBehaviour.
class DEBUG
{
  public:
    // The `::IsDebug` boolean determines wether methods of `DEBUG` class will execute or not.
    // Make sure to Define it at the beginning of the Program otherwise you will experience UndefinedBehaviour.
    static const bool IsDebug;
    // The `DEBUG::print` method is used to print an unknown number of variables.
    // Specify the number of variables to print as the first argument
    static void print(int argCount, ...);
};

#endif
