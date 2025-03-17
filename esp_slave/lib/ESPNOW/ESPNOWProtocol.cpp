#include <ESPNOWProtocol.h>

ESPNOWProtocol::ESPNOWProtocol(esp_now_role role): _role(role) {};

std::function<void(uint8_t*, uint8_t*, uint8_t)> ESPNOWProtocol::_receiveCallback = nullptr;

void ESPNOWProtocol::begin() {
    if (esp_now_init() != 0) {
        Serial.println("ESP Now Failed");
        return;
    }

    esp_now_set_self_role(_role);
    esp_now_register_recv_cb(_onReceive);
}

void ESPNOWProtocol::setReceiveCallback(std::function<void(uint8_t*, uint8_t*, uint8_t)> callback) {
    _receiveCallback = callback;
}

void ESPNOWProtocol::_onReceive(uint8_t* mac, uint8_t* incomingData, uint8_t len) {
    if (_receiveCallback) {
        _receiveCallback(mac, incomingData, len);
    }
}