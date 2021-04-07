#include "PIControl.h"
#include "RainSensor.h"
#include "RelayControl.h"
#include "SDContoller.h"
#include "SerialEncoder.h"
#include "SolarSensor.h"

#define RAIN_AO A0
#define RAIN_DO 2

#define STEPPER_STEP 3
#define STEPPER_DIR 4 
#define STEPPER_EN 5



#define CONTROL_RELAY 6

#define TRIGGER_RELAY 7

PIControl picontrol;
SolarSensor solarSensor;

void setup() {
  Serial.begin(11520);
  picontrol = PIControl();
  solarSensor = SolarSensor();
  pinMode(RAIN_AO, INPUT);
  pinMode(RAIN_DO, INPUT_PULLUP);
  pinMode(STEPPER_STEP, OUTPUT);
  pinMode(STEPPER_DIR, OUTPUT);
  pinMode(STEPPER_EN, OUTPUT);
  pinMode(VOLTAGE_AO, INPUT);
  pinMode(CONTROL_RELAY, OUTPUT);

  
}

void loop() {
  if(!picontrol.getStatus()){
    if(solarSensor.checkSufficiency() == VOLTAGE_SUFFICIENT){
      picontrol.powerOn();
    }else{
      //SD logging
    }
  }else{
    //Transmitting data to pi and delete data
  }
}
