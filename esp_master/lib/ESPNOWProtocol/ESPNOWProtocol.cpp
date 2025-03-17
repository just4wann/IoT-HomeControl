#include <ESPNOWProtocol.h>

esp_now_peer_info peerInfo;
payload_type payload;

ESPNOWProtocol::ESPNOWProtocol(): _macAddressReceiver{0x84, 0xF3, 0xEB, 0x99, 0x08, 0xA2} {}

std::function<void(const uint8_t*, esp_now_send_status_t)> ESPNOWProtocol::_sentCallback = nullptr;

void ESPNOWProtocol::begin() {
    if (esp_now_init() != ESP_OK) {
        Serial.println("Failed initialize ESP NOW");
        return;
    }
    esp_now_register_send_cb(_onSent);
    memcpy(peerInfo.peer_addr, _macAddressReceiver, 6);
    peerInfo.channel = 0;
    peerInfo.encrypt = false;
    if (esp_now_add_peer(&peerInfo) != ESP_OK) {
        Serial.println("Failed add peer");
        return;
    }
    Serial.println("ESP NOW Ready!");
}

void ESPNOWProtocol::sendData(bool state, int device) {
    payload.state = state;
    payload.device = device;
    esp_err_t result = esp_now_send(_macAddressReceiver, (uint8_t*)&payload, sizeof(payload));
    if (result != ESP_OK) {
        Serial.println("Send failed!");
        return;
    }
    Serial.println("Send success");
}

void ESPNOWProtocol::setSendingCallback(std::function<void(const uint8_t*, esp_now_send_status_t)> callback) {
    _sentCallback = callback;
}

void ESPNOWProtocol::_onSent(const uint8_t* mac, esp_now_send_status_t status) {
    if (_sentCallback) {
        _sentCallback(mac, status);
    }
}