#ifndef UNTITLED4_APICLIENT_H
#define UNTITLED4_APICLIENT_H

#pragma once
#include <wifiS3.h>
#include "../../include/secrets.h"

class ApiClient {

    public:
    ApiClient();
    bool scanCard(const String& cardId);

private:
    const char* _host;
    int _port;
    WiFiClient _client;

    bool post(const char* path, const String& jsonBody);
    String readResponse();

};


#endif //UNTITLED4_APICLIENT_H