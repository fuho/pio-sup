# pio-sup
PlatformIO Hello World for NodeMCU (ESP8266)

## First steps

### Driver installation
In the `./assets/` folder you will find a signed driver package you will need to install in order to be able to upload firmware to your board.

### Software installation

`brew update && brew upgrade`
`brew install platformio`

PlatformIO has a great package for Atom if you want to use a free IDE. You can download it here: https://atom.io/
The run: Atom > Preferences > Install and install these three packages:
 - platformio-ide
 - platformio-ide-terminal
 - platformio-ide-debugger

### First project
`mkdir helloesp && cd $_`
`pio init -b nodemcuv2`
Create a file `.src/main.cpp` with the following content:
```cpp
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
```
Check if it compiles with `pio run` or compile and upload with `pio run --target upload`.
You should now see the blue LED flash on and off every 1 second.

### Speed up upload times
Open `platformio.ini` file and add one line specifying the uplaod speed:
```ini
[env:nodemcuv2]
platform = espressif8266
board = nodemcuv2
framework = arduino
upload_speed = 921600
```
