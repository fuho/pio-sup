#include <arduino.h>			// All sorts of goodies here...

const uint8_t LED = 2; 		// LED is on pin 2

void setup(){							// This is run once and only once at the boot
	pinMode(LED, OUTPUT); 	// We intend to write to this pin
	Serial.begin(115200);		// Initialize serial port
}

void loop(){							// All your programs will have an execution loop
	digitalWrite(LED, LOW);	// This might look counter-intuitive but the LED ..
	Serial.println("ON");		// .. anode is connected to 3.3V and the cathode is..
	delay(1000);						// .. connected to PIN 2. When we then pull the pin ..
	digitalWrite(LED, HIGH);// .. low (0V), we create a voltage differential and ..
	Serial.println("OFF");	// .. the current flows. When we pull it high (3.3V) ..
	delay(1000);						// .. both LED pins are at 3.3V hence no current flow.
}
