#include <WiFiHandle.h>

WiFiHandle::WiFiHandle(LED& led): _localIP(192, 168, 100, 150), _subnet(255, 255, 255, 0), _gateway(192, 168, 100, 1), _led(led) {};

void WiFiHandle::connect(const char* ssid, const char* password) {
    if (!WiFi.config(_localIP, _gateway, _subnet)) {
        Serial.println("Failed Config WiFi");
        return; 
    }

    _led.blink(3, 100);

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    if (WiFi.waitForConnectResult() != WL_CONNECTED) {
        digitalWrite(2, true);
        Serial.printf("WiFi Failed!\n");
        return;
    }

    _led.blink(5, 100);

    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
}