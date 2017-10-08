
#ifndef ODriveArduino_h
#define ODriveArduino_h

#include "Arduino.h"

class ODriveArduino {
public:
    ODriveArduino(Stream& serial);
    void SetPosition(int motor_number, float position);
private:
    Stream& serial_;
};

#endif //ODriveArduino_h