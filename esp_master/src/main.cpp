#include <Arduino.h>
#include <WiFiHandler.h>
#include <Webserver.h>
#include <ESPNOWProtocol.h>

String ssid = "";
String password = "";

WiFiHandler wifi;
ESPNOWProtocol espNow;
WebServer webserver;

void setup() {
    Serial.begin(9600);
    wifi.setupWiFi(STATION, ssid, password);
    espNow.begin();
    webserver.begin();
}

void loop() {}