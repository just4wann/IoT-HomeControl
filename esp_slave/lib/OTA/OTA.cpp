#include <OTA.h>

OTA::OTA(const char* host, LED& led): _host(host), _led(led) {};

void OTA::startOTAService() {
    ArduinoOTA.setHostname(_host);
    ArduinoOTA.onStart([]() {
        String type = ArduinoOTA.getCommand() == U_FLASH ? "sketch" : "filesystem";
        Serial.println("Start Updating " + type);
    });
    ArduinoOTA.onEnd([]() {
        Serial.println("\n END");
    });
    ArduinoOTA.onProgress([this](unsigned int progress, unsigned int total) {
        this->_led.blink(1, 50);
        Serial.printf("Progress: %u%%\r", (progress * 100) / total);
    });
    ArduinoOTA.onError([](ota_error_t error) {
        Serial.printf("Error[%u]: ", error);
        if (error == OTA_AUTH_ERROR) {
        Serial.println("Auth Failed");
        } else if (error == OTA_BEGIN_ERROR) {
            Serial.println("Begin Failed");
        } else if (error == OTA_CONNECT_ERROR) {
            Serial.println("Connect Failed");
        } else if (error == OTA_RECEIVE_ERROR) {
            Serial.println("Receive Failed");
        } else if (error == OTA_END_ERROR) {
            Serial.println("End Failed");
        }
    });
    ArduinoOTA.begin();
    Serial.println("OTA Service ready");
}

void OTA::handleService() {
    ArduinoOTA.handle();
}