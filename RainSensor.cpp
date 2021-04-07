#include "RainSensor.h"

RainSensor::RainSensor(){
    this->digitalValue = 0;
    this->analogValue = 0;
}

int RainSensor::readDigital(){
    this->digitalValue = digitalRead(RAIN_DO);
    return this->digitalValue;
}

float RainSensor::readAnalog(){
    this->analogValue = analogRead(RAIN_AO);
    return this->analogValue;
}