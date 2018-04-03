
// Include IR Remote lib by Ken Shirrif
#include <IRremote.h>

// the following variables / constants must be global

// Define sensor pin
const int RECV_PIN=4;

// Define IR Receiver and results objects
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup() {
  // Serial monitor at 9600 baud
  Serial.begin(9600);
  // enable IR reciever
  irrecv.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)){
    // print recieved code in HEX
    Serial.println(results.value, HEX);
    switch(results.decode_type){
      case NEC:
        Serial.println("NEC");
        break;
      case SONY:
        Serial.println("SONY");
        break;
      case RC5:
        Serial.println("RC5");
        break;
      case RC6:
        Serial.println("RC6");
        break;
      case DISH:
        Serial.println("DISH");
        break;
      case SHARP:
        Serial.println("SHARP");
        break;
      case JVC:
        Serial.println("JVC");
        break;
      case SANYO:
        Serial.println("SANYO");
        break;
      case MITSUBISHI:
        Serial.println("MITSUBISHI");
        break;
      case SAMSUNG:
        Serial.println("SAMSUNG");
        break;
      case LG:
        Serial.println("LG");
        break;
      case WHYNTER:
        Serial.println("WHYNTER");
        break;                
      case AIWA_RC_T501:
        Serial.println("AIWA_RC_T501");
        break;
      case PANASONIC:
        Serial.println("PANASONIC");
        break;
      case DENON:
        Serial.println("DENON");
        break;
    default:
      case UNKNOWN:
        Serial.println("UNKNOWN");
        break;        
    }
    irrecv.resume();
  }

}

