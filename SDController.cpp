#include "SDController.h"

void SDController::logLine(String line){
    if (!SD.begin(10)) {
        while (1);
    }
    this->myFile = SD.open("raindata.txt", FILE_WRITE);
    
    if (this->myFile) {
    this->myFile.println(line);
    
    this->myFile.close();
    } else {
        
    }
}
