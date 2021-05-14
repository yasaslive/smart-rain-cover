#include "SolarSensor.h"

SolarSensor::SolarSensor(){
    this->voltageRead = 0;
}

float SolarSensor::getVoltageRead(){
    this->voltageRead = map(analogRead(VOLTAGE_AO), 0, 1023, 0, 25);
    return this->voltageRead;
}

int SolarSensor::checkSufficiency(){
    getVoltageRead();
    if(this->voltageRead > 12.5){
        return VOLTAGE_SUFFICIENT;
    }else{
        return VOLATGE_INSUFFICIENT;
    }
}