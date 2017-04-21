# PlatformIO Hello World for NodeMCU (ESP8266)

## First steps

### Driver installation
In the `./assets/` folder you will find a signed driver package you will need to install in order to be able to upload firmware to your board.
Or download the file directly from [here](https://github.com/fuho/pio-sup/raw/master/assets/CH34x_Install_V1.4.pkg).
Make sure to restart your computer after the driver install.

### Software installation
PlatformIO is a game changer in micro-controller development, it's a first trully open-source multi-platform, multi-framework product with support for multiple IDEs. Let's install it!  
Update/upgrade your brew : `brew update && brew upgrade`  
Install pio `brew install platformio`


PlatformIO has a great package for Atom if you want to use a free IDE. You can download it here: https://atom.io/
The run: Atom > Preferences > Install and install these three packages:
 - platformio-ide
 - platformio-ide-terminal
 - platformio-ide-debugger

 But you can use any editor you please and build and upload to yur board from CLI.

 Hello world time.... :)

### First project
In the microcontroller you don't usually have screen to print to so the equivalent of a classic hello-world program would be to toggle a pin.. we can do better! The boards have a built-in LED on pin 2, let's make it flash.  

Create your prohect folder `mkdir helloesp && cd $_`
Initialize the directory for your board: `pio init -b nodemcuv2`  
And create a file `.src/main.cpp` with the following content:
```cpp
#include <arduino.h>      // All sorts of goodies here...

const uint8_t LED = 2;    // LED is on pin 2

void setup(){             // This is run once and only once at the boot
  pinMode(LED, OUTPUT);   // We intend to write to this pin
  Serial.begin(115200);   // Initialize serial port
}

void loop(){              // All your programs will have an execution loop
  digitalWrite(LED, LOW); // This might look counter-intuitive but the LED ..
  Serial.println("ON");   // .. anode is connected to 3.3V and the cathode is..
  delay(1000);            // .. connected to PIN 2. When we then pull the pin ..
  digitalWrite(LED, HIGH);// .. low (0V), we create a voltage differential and ..
  Serial.println("OFF");  // .. the current flows. When we pull it high (3.3V) ..
  delay(1000);            // .. both LED pins are at 3.3V hence no current flow.
}
}
```
Check if it compiles with `pio run` or compile and upload with `pio run --target upload`.
You should now see the blue LED flash on and off every 1 second.

To see the serial data sent from the board run `screen /dev/$(ls /dev | grep "tty.*usb.*serial") 115200`. When you had enough kill screen with `Ctrl-ak, y`.

### Speed up upload times
Open `platformio.ini` file and add one line specifying the uplaod speed:
```ini
[env:nodemcuv2]
platform = espressif8266
board = nodemcuv2
framework = arduino
upload_speed = 921600
```
