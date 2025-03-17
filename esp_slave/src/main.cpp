#include <Arduino.h>
#include <OTA.h>
#include <IR.h>
#include <LED.h>
#include <WiFiHandle.h>
#include <MillisDelay.h>
#include <ESPNOWProtocol.h>

const char* ssid = "";
const char* password = "";
const char* host = "";
typedef enum {
  AC,
  TV
} device_type;

payload_type receivedPayload;

LED led(2);
IR ir(3, led);
WiFiHandle wifi(led);
OTA ota(host, led);
MillisDelay taskDelay;
ESPNOWProtocol espnow(ESP_NOW_ROLE_SLAVE);

void setup() {
  ir.begin(); 
  Serial.end();
  delay(50);
  Serial.begin(9600);
  wifi.connect(ssid, password);
  ota.startOTAService();
  espnow.begin();
  Serial.println("OK");
 
  espnow.setReceiveCallback([](uint8_t* mac, uint8_t* incomingData, uint8_t len) {
    if (len < sizeof(receivedPayload)) {
      Serial.println("Oops, data corrupted!");
      return;
    }
    memcpy(&receivedPayload, incomingData, sizeof(receivedPayload));
    if (receivedPayload.device == AC) {
      ir.irACHandler(receivedPayload.state);
    }
    if (receivedPayload.device == TV) {
      ir.irTVHandler(receivedPayload.state);
    }
  });
}

void loop() {
  taskDelay.executeTask(ota.handleService, 500);
}