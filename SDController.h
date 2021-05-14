#pragma once
#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

class SDController{
    private:
        File myFile;
    public:
        void logLine(String line);
};