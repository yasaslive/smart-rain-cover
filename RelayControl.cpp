#include "RelayControl.h"

void RelayControl::shortCircuit(){
    digitalWrite(TRIGGER_RELAY, HIGH);
    delay(500);
    digitalWrite(TRIGGER_RELAY, LOW);
}