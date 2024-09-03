/*
ESP32 SD Card (SPI) write test 

https://soar130650.net/2021/02/11/esp32-cmicrosd/

Rev 0.1 2024.09.04  Initial. add delay(3000) for Serial.print

Jay Teramoto 
*/

#include "FS.h"
#include "SD.h"
#include "SPI.h"

void writeFile(fs::FS &fs, const char * path, const char * message){
    Serial.printf("Writing file: %s\n", path);

    File file = fs.open(path, FILE_WRITE);
    if(!file){
        Serial.println("Failed to open file for writing");
        return;
    }
    if(file.print(message)){
        Serial.println("File written");
    } else {
        Serial.println("Write failed");
    }
    file.close();
}

void appendFile(fs::FS &fs, const char * path, const char * message){
    Serial.printf("Appending to file: %s\n", path);

    File file = fs.open(path, FILE_APPEND);
    if(!file){
        Serial.println("Failed to open file for appending");
        return;
    }
    if(file.print(message)){
        Serial.println("Message appended");
    } else {
        Serial.println("Append failed");
    }
    file.close();
}

void setup() {
    Serial.begin(9600);
    while (!Serial) {
    }
    
    delay(3000);

    if(!SD.begin()){
        Serial.println("Card Mount Failed");
        return;
    }
    writeFile(SD, "/hello.txt", "hello ");
    appendFile(SD, "/hello.txt", "World!\n");
}

void loop() {

}