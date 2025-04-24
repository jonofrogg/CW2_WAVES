#include <SwitchProBT.h>
#include <usbhub.h>
#include <SPI.h>

USB Usb;
BTD Btd(&Usb);

SwitchProBT SwitchPro(&Btd, PAIR);

//bool printAngle = false;
uint16_t lastMessageCounter = -1;
uint32_t capture_timer;

void setup(){
  Serial.begin(115200);

  if (Usb.Init() == -1){
    Serial.print(F("OSC did not start"));
    while (1);
  }  
  Serial.print(F("Switch Pro Bluetooth Library Started"));
}

void loop(){
  Usb.Task();

  if (SwitchPro.connceted() && lastMessageCounter != SwitchPro.getMessageCounter()){
    lastMessageCounter = SwitchPro.getMessageCounter();
  }
  }