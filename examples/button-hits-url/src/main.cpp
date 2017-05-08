#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include "../.piolibdeps/WifiManager_ID567/WiFiManager.h"
#include <ESP8266HTTPClient.h>

#define LED D4
#define BUTTON D2

WiFiManager wifiManager;
HTTPClient http;


void warnWithLed() {
    int delays[22] = {
            50, 950,
            100, 900,
            150, 850,
            250, 750,
            350, 650,
            500, 500,
            100, 100,
            100, 100,
            100, 100,
            100, 100,
            100, 100
    };
    for (int i = 0; i < 20; i += 2) {
        digitalWrite(LED, LOW);
        delay((unsigned long) delays[i]);
        digitalWrite(LED, HIGH);
        delay((unsigned long) delays[i + 1]);
        if(digitalRead(BUTTON)){
            break;
        }
    }
}

void setup() {
    Serial.begin(115200);
    pinMode(LED, OUTPUT);
    pinMode(BUTTON, INPUT_PULLUP);
    Serial.println();
    wifiManager.setBreakAfterConfig(true);
    if (!digitalRead(BUTTON)) {
        Serial.println("Button held during boot, will reset soon unless released!");
        // If we hold the button during boot for couple seconds reset wifi settings
        warnWithLed();
        if (!digitalRead(BUTTON)) {
            //.. we're still holding it - RESET
            Serial.println("Resetting!!");
            delay(500);
            wifiManager.resetSettings();
            ESP.restart();
        } else {
            Serial.println("Aborting reset!");
        }
    }

    if (!wifiManager.autoConnect()) {
        Serial.println("Failed to connect, we should reset and see if it connects");
        delay(3000);
        ESP.reset();
        delay(5000);
    }
    Serial.println("Connected!");
    Serial.println("local ip");
    Serial.println(WiFi.localIP());
}

void hitWebsite() {
    http.begin("http://requestb.in/1kbsdq11?" + String(ESP.getChipId(), DEC));
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
