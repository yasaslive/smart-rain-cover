#pragma once
#include <Arduino.h>
#include "RelayControl.h"

#define RX_PIN 0
#define TX_PIN 1
#define DISCONNECTED "DIS"
#define CONNECTED "CON"
#define REQUEST_POWERTCUT "PWR"
#define POWERCUT_RESPONSE "PWROFF"

class SerialEncoder{
    private:
        String linkStatus;
        String powerStatus;
    public:
        SerialEncoder();
        void waitForClient();
        bool sendData();
        void requestPowerCut(RelayControl relayControl);
};