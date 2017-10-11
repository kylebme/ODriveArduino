
#include "Arduino.h"
#include "ODriveArduino.h"

// Print with stream operator
template<class T> inline Print &operator <<(Print &obj, T arg) { obj.print(arg); return obj; } 

ODriveArduino::ODriveArduino(Stream& serial)
    : serial_(serial) {}

void ODriveArduino::SetPosition(int motor_number, float position) {
    serial_ << "$p " << motor_number << " " << position << " 0 0!";
}

float ODriveArduino::getBusVoltage() {
    serial_ << "$g 0 0!";

    String in_str = "";
    static const unsigned long timeout = 1000;
    unsigned long timeout_start = millis();
    for (;;) {
        while (!serial_.available()) {
            if (millis() - timeout_start >= timeout) {
                return 0.0f;
            }
        }
        char c = serial_.read();
        if (c == '\n')
            break;
        in_str += c;
    }

    return in_str.toFloat();
}