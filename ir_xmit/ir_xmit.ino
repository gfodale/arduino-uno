// include Ken Shirriff IR Remote library
#include <IRremote.h>

const int switchPin=7;
int buttonState=0;

// Pin 3 is set by the library for IR LED output...

// create IR send object
IRsend irsend;


void setup() {
  // put your setup code here, to run once:
pinMode(switchPin,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
// read current button state
buttonState=digitalRead(switchPin);

if (buttonState == HIGH){
  Serial.println("active");
  irsend.sendNEC(0x1A2EEC3B,32);
  irsend.sendNEC(0xFFFFFFFF,32);
  irsend.sendNEC(0xFFFFFFFF,32);  
  }
delay(200);
}
