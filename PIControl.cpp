#include "PiControl.h"

PIControl::PIControl(){
    this->status = false;
}

void PIControl::powerOn(){
    this->status = true;
    digitalWrite(CONTROL_RELAY, HIGH);
}

void PIControl::powerOff(){
    digitalWrite(CONTROL_RELAY, LOW);
    this->status = false;
}

bool PIControl::getStatus(){
    return this->status;
}