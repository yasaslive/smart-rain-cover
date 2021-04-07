#include <Arduino.h>
#define VOLTAGE_AO A1
#define VOLTAGE_SUFFICIENT 1
#define VOLATGE_INSUFFICIENT 2

class SolarSensor{
    private:
        float voltageRead;

    public:
        SolarSensor();
        float getVoltageRead();
        int checkSufficiency();
};