#include <WiFi.h>
#include <BuiltinLED.h>

typedef enum {
    ACCESS_POINT,
    STATION
} wifi_mode_type;

class WiFiHandler {
    public:
        WiFiHandler();
        void setupWiFi(wifi_mode_type mode, String ssid, String password);
    private:
        static BuiltinLED _led;
        IPAddress _localIP;
        IPAddress _subnet;
        IPAddress _gateway;
};