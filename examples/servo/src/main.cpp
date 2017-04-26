#include <arduino.h>	// All sorts of goodies here...
#include "Servo.h"		// Servo library

const uint8_t SERVO = D0; // Servo is on pin D0
Servo servo;

void setup(){							// This is run once and only once at the boot
	pinMode(SERVO, OUTPUT); // We intend to write to this pin
	servo.attach(SERVO);    // Tell the Servo library where it is attached
	Serial.begin(115200);		// Initialize serial port
}

void loop(){
	Serial.println("Servo 0");
	servo.write(0);		// Zero degrees
  delay(1000);			// Wait a sec..
	Serial.println("Servo 179");
	servo.write(179); // 179 degrees
  delay(1000); 			// Wait a sec..
}
