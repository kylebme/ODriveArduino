
#include <SoftwareSerial.h>
#include <ODriveArduino.h>

// Print with stream operator
template<class T> inline Print &operator <<(Print &obj, T arg) { obj.print(arg); return obj; } 

SoftwareSerial odrive_serial(8, 9); //RX (ODrive TX), TX (ODrive RX)
ODriveArduino odrive(odrive_serial);

void setup() {
  odrive_serial.begin(115200);
  Serial.begin(115200);
  while (!Serial) ; // wait for Arduino Serial Monitor to open
  Serial.println("ODriveArduino alpha.");
  Serial.println("Send the character 's' to exectue test move, 'b' to get bus voltage");
}

void loop() {

  if (Serial.available()) {
    char c = Serial.read();
    if (c == 's') {
      for (float ph = 0.0f; ph < 6.28318530718f; ph += 0.01f) {
        float pos_m0 = 20000.0f * cos(ph);
        float pos_m1 = 20000.0f * sin(ph);
        odrive.SetPosition(0, pos_m0);
        odrive.SetPosition(1, pos_m1);
        delay(5);
      }
    }

    if (c == 'b') {
      Serial << "Vbus voltage: " << odrive.getBusVoltage() << '\n';
    }
  }

}
