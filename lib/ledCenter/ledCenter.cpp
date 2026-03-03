#include "ledCenter.h"

ledCenter::ledCenter() = default;

bool ledCenter::startUp() {
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
    setColor(0, 0, 255);
    return true;
}

void ledCenter::throwReqoust(String mgs) {
    Serial.println(mgs);
    if (mgs.equals("test")) setColor(0, 255, 0);
    else setColor(0, 0, 255);

}

void ledCenter::throwError(String mgs) {

    if (mgs == "test") setColor(255, 0, 0); delay(1000); setColor(0, 0, 0);

}

void ledCenter::setColor(const int red, const int green, const int blue) {
    Serial.println("setColor");
    Serial.println(RED_PIN);
    Serial.println(GREEN_PIN);
    Serial.println(BLUE_PIN);
    analogWrite(RED_PIN, red);
    analogWrite(GREEN_PIN, green);
    analogWrite(BLUE_PIN, blue);
}
