#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>

class WebServerRoutes {
    public:
        WebServerRoutes(AsyncWebServer *server);

        void setupRoutes();
    private:
        AsyncWebServer *_server;
};