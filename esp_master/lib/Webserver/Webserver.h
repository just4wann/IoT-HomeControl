#include <ESPAsyncWebServer.h>

class WebServer {
    public:
        WebServer() {};
        void begin();
    private:
        static AsyncWebServer _server;
};