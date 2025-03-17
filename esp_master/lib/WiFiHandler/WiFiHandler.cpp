#include <WiFiHandler.h>

BuiltinLED WiFiHandler::_led = BuiltinLED(2);

WiFiHandler::WiFiHandler(): _localIP(192, 168, 100, 140), _subnet(255, 255, 255, 0), _gateway(192, 168, 100, 1) {};

void WiFiHandler::setupWiFi(wifi_mode_type mode, String ssid, String password) {
    if (mode == ACCESS_POINT) {
        Serial.println("Setting up WiFi to ACCESS POINT mode....");
        _led.blink(5, 100);
        WiFi.disconnect(true, true);
        String macAddr = WiFi.macAddress();
        String lastFourChar = macAddr.substring(macAddr.length() - 4);
        String fullSsid = ssid + "-" + lastFourChar;
        if (!WiFi.softAP(fullSsid, password, 6)) {
            Serial.println("Create Wi-Fi AP Failed!");
            return;
        }
        _led.steady();
        Serial.println("Wi-Fi AP started successfully");
        Serial.print("Wi-Fi AP IP Address : ");
        Serial.println(WiFi.softAPIP());
    }
    if (mode == STATION) {
        Serial.println("Setting up WiFi to STATION mode....");
        _led.blink(10, 50);
        if (!WiFi.config(_localIP, _gateway, _subnet)) {
            Serial.println("Failed config");
            return;
        }
        WiFi.mode(WIFI_STA);
        WiFi.begin(ssid, password);
        if (WiFi.waitForConnectResult() != WL_CONNECTED) {
            Serial.printf("WiFi Failed!\n");
            return;
        }
        _led.steady();
        Serial.print("IP Address: ");
        Serial.println(WiFi.localIP());
    }
}
