#include "ApiClient.h"

ApiClient::ApiClient()
  : _host(apiDomain), _port(apiPort) {}

bool ApiClient::scanCard(const String& cardId) {
    Serial.println("Scanner kort...");
    Serial.println(cardId);
    Serial.println(_host);
    Serial.flush();
    String body = "{\"tag\":\"" + cardId + "\"}";
    return post("/api/cards/scan", body);
}

bool ApiClient::post(const char* path, const String& jsonBody) {
    Serial.println("Forbinder til server...");

    if (!_client.connect(_host, _port)) {
        Serial.println("Kunne ikke forbinde til server!");
        return false;
    }

    _client.println("POST " + String(path) + " HTTP/1.1");
    _client.println("Host: " + String(_host) + ":" + String(_port));
    _client.println("Content-Type: application/json");
    _client.println("Content-Length: " + String(jsonBody.length()));
    _client.println("Connection: close");
    _client.println();
    _client.println(jsonBody);

    String response = readResponse();
    Serial.println("Svar: " + response);

    _client.stop();
    return response.length() > 0;
}

String ApiClient::readResponse() {
    String response = "";
    unsigned long timeout = millis();

    while (_client.connected() && millis() - timeout < 5000) {
        while (_client.available()) {
            char c = _client.read();
            response += c;
            timeout = millis();
        }
    }

    return response;
}