#include <ESPAsyncWebServer.h>

class WebServerHandler {
    public:
        WebServerHandler(AsyncWebServer *server);

        static void handlerDevice(AsyncWebServerRequest *request);
    private:
        AsyncWebServer *_server;

        static bool _state;
        static int _device;
};