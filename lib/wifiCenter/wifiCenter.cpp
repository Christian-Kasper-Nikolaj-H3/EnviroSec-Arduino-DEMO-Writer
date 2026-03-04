#include "wifiCenter.h"

wifiCenter::wifiCenter() = default;

bool wifiCenter::connect() {
    ledCenter led;
    WiFi.end();
    delay(100);
    WiFi.begin(wifiName, wifiPassword);
    unsigned long start = millis();
    led.throwReqoust("wifi");
    while (WiFi.status() != WL_CONNECTED && millis() - start < 15000) {
    }
    return WiFi.status() == WL_CONNECTED;
}
