#include <Arduino.h>
#include <espnow.h>

typedef struct payload_type {
    bool state;
    int device;
} payload_type;

class ESPNOWProtocol {
    public:
        ESPNOWProtocol(esp_now_role role);
        void begin();
        void setReceiveCallback(std::function<void(uint8_t*, uint8_t*, uint8_t)> callback);
    private:
        esp_now_role _role;
        static std::function<void(uint8_t*, uint8_t*, uint8_t)> _receiveCallback;

        static void _onReceive(uint8_t* mac, uint8_t* incomingData, uint8_t len);
};