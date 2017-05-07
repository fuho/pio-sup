#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include "../.piolibdeps/WifiManager_ID567/WiFiManager.h"
#include <ESP8266HTTPClient.h>

#define LED D4
#define BUTTON D2

WiFiManager wifiManager;
HTTPClient http;

void setup() {
    Serial.begin(115200);
    pinMode(LED, OUTPUT);
    pinMode(BUTTON, INPUT_PULLUP);
    Serial.println();
    wifiManager.setBreakAfterConfig(true);
    if (!digitalRead(BUTTON)) {
        wifiManager.resetSettings();
    }

    if (!wifiManager.autoConnect()) {
        Serial.println("failed to connect, we should reset as see if it connects");
        delay(3000);
        ESP.reset();
        delay(5000);
    }
    Serial.println("Connected!");
    Serial.println("local ip");
    Serial.println(WiFi.localIP());
}

void hitWebsite() {
    http.begin("http://requestb.in/1kbsdq11?" + String(ESP.getChipId(),DEC));
    int httpCode = http.GET();
    if (httpCode == HTTP_CODE_OK) {
        Serial.print("HTTP response code ");
        Serial.println(httpCode);
        String response = http.getString();
        Serial.println(response);
    } else {
        Serial.println("Error in HTTP request");
    }
    http.end();
}

void loop() {
    if (!digitalRead(BUTTON)) {
        digitalWrite(LED, LOW);
        Serial.println("Hitting website...");
        hitWebsite();
    } else {
        digitalWrite(LED, HIGH);
    }

}