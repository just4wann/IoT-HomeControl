#ifndef OTA_H
#define OTA_H

#include <ArduinoOTA.h>
#include <LED.h>

class OTA {
    public:
        OTA(const char* host, LED& led);
        void startOTAService();
        static void handleService();
    private:
        const char* _host;
        LED _led;
};

#endif