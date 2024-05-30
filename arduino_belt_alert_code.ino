#include <SoftwareSerial.h>
#include <PulseSensorPlayground.h>

const int PulseWire = 0;       // PulseSensor PURPLE WIRE connected to ANALOG PIN 0
const int LED = LED_BUILTIN;          // The on-board Arduino LED, close to PIN 13.
int Threshold = 550; 
int flag = 0;
int bpm=0;
SoftwareSerial BTserial(10, 11 );
PulseSensorPlayground pulseSensor;
int myBPM = pulseSensor.getBeatsPerMinute();
void setup() {
 BTserial.begin(9600);
  Serial.begin(115200);
  pinMode(7, INPUT);
  pulseSensor.analogInput(PulseWire);   
  pulseSensor.blinkOnPulse(LED);       //auto-magically blink Arduino's LED with heartbeat.
  pulseSensor.setThreshold(Threshold);
  
  if (pulseSensor.begin()) {
    Serial.println("We created a pulseSensor Object !");  //This prints one time at Arduino power-up,  or on Arduino reset.  
  }
}



void loop() {
if (pulseSensor.sawStartOfBeat()){            // Constantly test to see if "a beat happened".
int myBPM = pulseSensor.getBeatsPerMinute();  // Calls function on our pulseSensor object that returns BPM as an "int".
  // "myBPM" hold this BPM value now. 
 Serial.println("♥  A HeartBeat Happened ! "); // If test is "true", print a message "a heartbeat happened".
 Serial.print("BPM: ");                        // Print phrase "BPM: " 
 Serial.println(myBPM);                        // Print the value inside of myBPM. 
}
delay(100);
   Serial.println(digitalRead(7));
      if ((digitalRead(7) == 0 | (pulseSensor.getBeatsPerMinute() < 60 & pulseSensor.getBeatsPerMinute() > 10)) & flag == 0) { 
      delay(15000);
           if (digitalRead(7) == 0|(pulseSensor.getBeatsPerMinute() < 60 & pulseSensor.getBeatsPerMinute() > 10) ) {
        for (int count = 0; count < 3; count++) {
        BTserial.print("SOS");
         Serial.print("alert");
          delay(15000);
       }
      
     }
      delay(60000);
      flag = 0;
   }
 
}
