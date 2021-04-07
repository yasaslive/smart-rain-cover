#include <Arduino.h>
#define CONTROL_RELAY 6
class PIControl{
    private:
        bool status;

    public:
        PIControl();
        void powerOn();
        void powerOff();
        bool getStatus();
};