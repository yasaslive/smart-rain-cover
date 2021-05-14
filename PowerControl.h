#pragma once

#include <Arduino.h>

#define POWER_SUFFICENT 1
#define POWER_INSUFFICENT 0
#define SIGNAL_PIN 1

class PowerControl{
    private:
        float voltage;
    public:
        PowerControl();
        int checkPower();
};