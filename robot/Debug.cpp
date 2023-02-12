#include "Debug.h"

void DEBUG::print(int argCount, ...) {
  if (!(DEBUG::IsDebug)) {
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