#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>
#include <ArduinoJson.h>
#include <wifiCenter.h>
#include <sendToAPI.h>
#include <ApiClient.h>

#include <ledCenter.h>

wifiCenter wifi;
ApiClient api;
ledCenter ledCenter;

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN);

String strID;

void setup() {
    Serial.begin(9600);
    if ( ledCenter.startUp()) {
        Serial.println("LEDs are on");
    }

    SPI.begin(); // init SPI bus
    rfid.PCD_Init(); // init MFRC522

    if (!wifi.connect()) {
        Serial.println("Connected to WiFi");
    }

    Serial.println("Tap RFID/NFC Tag on reader");
}

void loop() {
    if (rfid.PICC_IsNewCardPresent()) { // new tag is available
        if (rfid.PICC_ReadCardSerial()) { // NUID has been readed

            Serial.println();
            for (byte i = 0; i < 4; i++) {
                strID +=
                    (rfid.uid.uidByte[i] < 0x10 ? "0" : "") +
                        String(rfid.uid.uidByte[i], HEX) +
                            (i != 3 ? ":" : "");
            }
            strID.toUpperCase();
            ledCenter.throwReqoust("test");

            Serial.print("RFID tag detected: ");
            Serial.println(strID);

            api.scanCard(strID);


            rfid.PICC_HaltA(); // halt PICC
            rfid.PCD_StopCrypto1(); // stop encryption on PCD
        }
    }
}