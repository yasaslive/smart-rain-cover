#include "StepperControl.h"

StepperControl::StepperControl(){
    this->isActive = false;
    this->myStepper.setSpeed(10);
}

bool StepperControl::getStatus(){
  return this->isActive;
}
void StepperControl::openStepper(){
    this->myStepper.step(2048*10);
    this->isActive = false;
}

void StepperControl::closeStepper(){
    this->myStepper.step(-2048*10);
    this->isActive = true;
}
