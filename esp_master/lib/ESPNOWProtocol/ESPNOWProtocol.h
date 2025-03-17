#include <Arduino.h>
#include <esp_now.h>

typedef struct payload_type {
    bool state;
    int device;
} payload_type;

class ESPNOWProtocol {
    public:
        ESPNOWProtocol();
        void begin();

        void sendData(bool state, int device);
        void setSendingCallback(std::function<void(const uint8_t*, esp_now_send_status_t)> callback);
    private:
        static std::function<void(const uint8_t*, esp_now_send_status_t)> _sentCallback;
        static void _onSent(const uint8_t* mac, esp_now_send_status_t status);

        uint8_t _macAddressReceiver[6];
};