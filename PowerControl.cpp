#include "PowerControl.h"

PowerControl::PowerControl(){
    this->voltage = 0.0;
}

int PowerControl::checkPower(){
    this->voltage = analogRead(SIGNAL_PIN);
    this->voltage = map(this->voltage, 0, 1023, 0, 25);
    if(this->voltage >= 13){
        return POWER_SUFFICENT;
    }else{
        return POWER_INSUFFICENT;
    }
}