#ifndef UNTITLED4_SENDTOAPI_H
#define UNTITLED4_SENDTOAPI_H

#include <wifiS3.h>
#include <WiFiSSLClient.h>
#include "../../include/secrets.h"

class sendToAPI {
    public:
    sendToAPI();

    void sendData(const char *data);

private:
    IPAddress ip = apiDomain;
    uint16_t port = apiPort;

    WiFiSSLClient wifiClient;
};


#endif //UNTITLED4_SENDTOAPI_H