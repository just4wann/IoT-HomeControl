#include <WebserverHandler.h>
#include <ESPNOWProtocol.h>

ESPNOWProtocol _espNow;

bool WebServerHandler::_state = false;
int WebServerHandler::_device = 0;

WebServerHandler::WebServerHandler(AsyncWebServer *server) {
    this->_server = server;
}

void WebServerHandler::handlerDevice(AsyncWebServerRequest *request) {
    if (request->hasParam("state", true) && request->hasParam("device", true)) {
        String stringState = static_cast<String>(request->getParam("state", true)->value());
        String device = static_cast<String>(request->getParam("device", true)->value());

        if (device != "tv" && device != "ac") {
            request->send(400, "application/json", "{\"status\" : \"Error\", \"message\" : \"Device to control is not valid\"}");
            return;
        }
        if (stringState != "on" && stringState != "off") {
            request->send(400, "application/json", "{\"status\" : \"Error\", \"message\" : \"Forbidden value\"}");
            return;
        }
        if (device == "tv") {
            request->send(200, "application/json", "{\"status\" : \"OK\", \"message\" : \"TV control successfully\"}");
        }
        if (device == "ac") {
            request->send(200, "application/json", "{\"status\" : \"OK\", \"message\" : \"AC control successfully\"}");
        }

        _state = stringState == "on" ? true : false;
        _device = device == "ac" ? 1 : 2;

        _espNow.sendData(_state, _device);
        _espNow.setSendingCallback([](const uint8_t *mac, esp_now_send_status_t status) {
            Serial.print("Send status : ");
            Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Success" : "Failed");
        });
    }
    else {
        request->send(400, "application/json", "{\"status\" : \"Error\", \"message\" : \"Invalid param\"}");
    }
}