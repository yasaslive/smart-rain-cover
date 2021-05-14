#pragma once
#define A 3
#define B 4
#define C 5
#define D 6
#define NUMBER_OF_STEPS_PER_REV 2048
#include <Arduino.h>
#include <Stepper.h>

class StepperControl{
    private:
        bool isActive;
        Stepper myStepper = Stepper(NUMBER_OF_STEPS_PER_REV, A, B, C, D);
    public:
        StepperControl();
        bool getStatus();
        void openStepper();
        void closeStepper();
};
