#include <WebserverHandler.h>
#include <WebserverRoutes.h>

WebServerRoutes::WebServerRoutes(AsyncWebServer *server) {
    this->_server = server;
}

void WebServerRoutes::setupRoutes() {
    _server->serveStatic("/", SPIFFS, "/");
    _server->on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/html/index.html", "text/html");
    });
    _server->on("/api/control", HTTP_POST, WebServerHandler::handlerDevice);
}