#ifndef UNTITLED4_WIFICONNECT_H
#define UNTITLED4_WIFICONNECT_H

#pragma once
#include <WiFiS3.h>
#include "../../include/secrets.h"

class wifiCenter {
    public:
    wifiCenter();
    static bool connect();

private:
    const char* name = wifiName;
    const char* password = wifiPassword;
};

#endif //UNTITLED4_WIFICONNECT_H