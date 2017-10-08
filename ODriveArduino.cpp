
#include "Arduino.h"
#include "ODriveArduino.h"

ODriveArduino::ODriveArduino(Stream& serial)
	: serial_(serial) {}

void ODriveArduino::SetPosition(int motor_number, float position) {
	serial_.print("$p ");
	serial_.print(motor_number);
	serial_.print(" ");
	serial_.print(position);
	serial_.print(" 0 0!");
}