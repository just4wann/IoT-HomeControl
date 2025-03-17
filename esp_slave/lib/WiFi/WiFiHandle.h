#ifndef WIFI_HANDLE_H
#define WIFI_HANDLE_H

#include <ESP8266WiFi.h>
#include <LED.h>

class WiFiHandle {
    public:
        WiFiHandle(LED& led);
        void connect(const char *ssid, const char *password);
    private:
        IPAddress _localIP;
        IPAddress _subnet;
        IPAddress _gateway;

        LED _led;
};

#endif