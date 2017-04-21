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

