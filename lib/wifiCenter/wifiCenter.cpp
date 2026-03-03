#include "wifiCenter.h"

wifiCenter::wifiCenter() = default;

bool wifiCenter::connect() {
    WiFi.end();
    delay(100);
    Serial.println("ssid: " + String(wifiName));
    Serial.println("password: " + String(wifiPassword));
    WiFi.begin(wifiName, wifiPassword);

    unsigned long start = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - start < 15000){}
    Serial.println("WiFi: Connected?");
    return WiFi.status() == WL_CONNECTED;
}
