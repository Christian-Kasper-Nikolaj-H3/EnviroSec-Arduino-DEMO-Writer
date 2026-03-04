#include "ledCenter.h"

ledCenter::ledCenter() = default;

bool ledCenter::startUp() {
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
    return true;
}

void ledCenter::throwReqoust(String mgs) {
    if (mgs.equals("test")) setColor(0, 255, 0);
    else if (mgs.equals("wifi")) setColor(0, 0, 123);
    else if (mgs.equals("wifiConnected")) {

        int swidth;
        unsigned long start = millis();

        while (millis() - start < 1000) {
            if (swidth >= 1){
                setColor(0, 0, 255);
                swidth = 0;
            }
            else {
                setColor(0, 255, 0);
                swidth = 1;
            }
            delay(200);
        }
        setColor(0, 0, 0);
    }
    else if (mgs.equals("cardDetected")) {
        setColor(0, 0, 255);
    }else if (mgs.equals("cardScanned")) {
        setColor(0, 255, 0);
        delay(1000);
        setColor(0, 0, 0);
    }
    else setColor(0, 0, 255);

}

void ledCenter::throwError(String mgs) {

    if (mgs.equals("wifi")) {
        int swidth;
        unsigned long start = millis();

        while (millis() - start < 1000) {
            if (swidth >= 1){
                setColor(0, 0, 255);
                swidth = 0;
            }
            else {
                setColor(255, 0, 0);
                swidth = 1;
            }
            delay(200);
        }
        setColor(123, 0, 0);
    }else if (mgs.equals("cardNotScanned")) {
        setColor(255, 0, 0);
        delay(1000);
        setColor(0, 0, 0);
    }

}

void ledCenter::setColor(const int red, const int green, const int blue) {
    analogWrite(RED_PIN, red);
    analogWrite(GREEN_PIN, green);
    analogWrite(BLUE_PIN, blue);
}
