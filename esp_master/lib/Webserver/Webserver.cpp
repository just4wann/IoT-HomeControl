#include <Webserver.h>
#include <WebserverRoutes.h>
#include <SPIFFS.h>

AsyncWebServer WebServer::_server = AsyncWebServer(80);

void WebServer::begin() {
    WebServerRoutes routes(&_server);

    if (!SPIFFS.begin(true)) {
        Serial.println("Failed to mount file system");
        return;
    }

    DefaultHeaders::Instance().addHeader("Access-Control-Allow-Origin", "*");
    DefaultHeaders::Instance().addHeader("Access-Control-Allow-Method", "GET, POST");
    DefaultHeaders::Instance().addHeader("Access-Control-Allow-Headers", "Content-Type");
    
    routes.setupRoutes();
    _server.begin();
}