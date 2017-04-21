#include <arduino.h>

const uint8_t LED = 2;

void setup(){
	pinMode(LED, OUTPUT);
	Serial.begin(115200);
}

void loop(){
	digitalWrite(LED, LOW);
	Serial.println("ON");
	delay(1000);
	digitalWrite(LED, HIGH);
	Serial.println("OFF");
	delay(1000);
}
