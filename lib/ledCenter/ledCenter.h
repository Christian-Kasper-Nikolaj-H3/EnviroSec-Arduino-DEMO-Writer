#ifndef UNTITLED4_LEDCENTER_H
#define UNTITLED4_LEDCENTER_H

#pragma once

#include <Arduino.h>
#include <SPI.h>

#define RED_PIN 2
#define GREEN_PIN 3
#define BLUE_PIN 4

// LED timing
#define LED_DURATION 5000
#define RESPONSE_TIMEOUT 5000

class ledCenter {

    public:
        ledCenter();
        bool startUp();
        void throwReqoust(String);
        void throwError(String);


    private:
        void setColor(int red, int green, int blue);

    // LED state
    unsigned long ledOnTime = 0;
    bool ledActive = false;
    bool awaitingResponse = false;
    unsigned long requestSentTime = 0;

};


#endif