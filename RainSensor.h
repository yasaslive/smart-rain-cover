#include <Arduino.h>
#define RAIN_AO A0
#define RAIN_DO 2

class RainSensor{
    private:
        int digitalValue;
        float analogValue;
    
    public:
        RainSensor();
        int readDigital();
        float readAnalog();
};