#pragma once
#include <Arduino.h>
#define CONTROL_RELAY 7
class PIControl{
    private:
        bool status;

    public:
        PIControl();
        void powerOn();
        void powerOff();
        bool getStatus();
};