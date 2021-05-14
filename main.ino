#include "PIControl.h"
#include "RainSensor.h"
#include "RelayControl.h"
#include "SDController.h"
#include "SerialEncoder.h"
#include "SolarSensor.h"
#include "StepperControl.h"
#include "PowerControl.h"

#define CONTROL_RELAY 6
#define CLOSE_COVER "CLCVR"
#define OPEN_COVER "OPCVR"
PIControl picontrol;
SolarSensor solarSensor;
RainSensor rainSensor;
StepperControl stepperControl;
PowerControl powerControl;
SerialEncoder serialEncoder;
RelayControl relayControl;
SDController sdController;

void setup() {
  Serial.begin(115200);
  picontrol = PIControl();
  solarSensor = SolarSensor();
  rainSensor = RainSensor();
  stepperControl = StepperControl();
  powerControl = PowerControl();
  serialEncoder = SerialEncoder();
  relayControl = RelayControl();
  sdController = SDController();

  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(RAIN_AO, INPUT);
  pinMode(RAIN_DO, INPUT);
  pinMode(VOLTAGE_AO, INPUT);
  pinMode(CONTROL_RELAY, OUTPUT);
  pinMode(TRIGGER_RELAY, OUTPUT);
}

void loop() {
  String dt = "RainAO: "+ String(rainSensor.readAnalog()) + " RainDO: "+ String(rainSensor.readDigital()) + " SolarSensor: " + solarSensor.getVoltageRead();
  Serial.println(dt);
  int rainVal = rainSensor.readDigital();
  if(rainVal == 0){
    if(!stepperControl.getStatus())
      stepperControl.closeStepper();

    if(powerControl.checkPower() == POWER_SUFFICENT){
    if(!picontrol.getStatus()){
      picontrol.powerOn();
    }
    serialEncoder.waitForClient();
    serialEncoder.sendData();
    serialEncoder.requestPowerCut(relayControl);
    }else{
      String dtline = String("Solar: " + (int)solarSensor.getVoltageRead()) + " RainAO: " + rainSensor.readAnalog() + " RainDO: " + rainSensor.readDigital();
      sdController.logLine(dtline);
    }
  
    if(powerControl.checkPower() == POWER_INSUFFICENT){
      if(picontrol.getStatus())
        picontrol.powerOff();
    }
    delay(1000);
  }else{
    if(stepperControl.getStatus()){
      stepperControl.openStepper();
    }
  }
  if(Serial.available()){
    String dt = Serial.readString();
    dt.trim();
    if(dt.startsWith(POWERCUT_RESPONSE)){
      relayControl.shortCircuit();
    }else if(dt.equalsIgnoreCase(OPEN_COVER)){
      if(stepperControl.getStatus())
        stepperControl.openStepper();
      Serial.println("OK");
    }else if(dt.startsWith(CLOSE_COVER)){
      if(!stepperControl.getStatus())
        stepperControl.closeStepper();
      Serial.println("OK");
    }
    
  }
  delay(1000);
}
