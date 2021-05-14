#include "SerialEncoder.h"

SerialEncoder::SerialEncoder(){
    this->linkStatus = DISCONNECTED;
    this->powerStatus = REQUEST_POWERTCUT;
}

void SerialEncoder::waitForClient(){
    do{
        if(Serial.available()){
            this->linkStatus = Serial.read();
        }
    }while(this->linkStatus == CONNECTED);
}

bool SerialEncoder::sendData(){
    //Handles by Serial Interface
}

void SerialEncoder::requestPowerCut(RelayControl relayControl){
    for(int x = 0; x < 60; x++){
        if(Serial.available()){
            this->powerStatus = Serial.read();
            if(this->powerStatus == POWERCUT_RESPONSE){
                relayControl.shortCircuit();
                break;
            }
        }
        delay(1000);
    }
}