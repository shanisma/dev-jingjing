#include <ArduinoJson.h>

const int analogInPin0 = A0;  
const int analogInPin1 = A1;  


int sensorValue0 = 0; 
float outputValue0 = 0; 
float pa0 = 0;

int sensorValue1 = 0; 
float outputValue1 = 0; 
float pa1 = 0;

DynamicJsonDocument doc(1024);


void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

void loop() {
  // read the analog in value:
  sensorValue0 = analogRead(analogInPin0);
  outputValue0 = map(sensorValue0, 0, 1023, 0, 10);
  pa0 = map(sensorValue0, 0, 1023, 0, 500) ;
  
  sensorValue1 = analogRead(analogInPin1);
  outputValue1 = map(sensorValue1, 0, 1023, 0, 10);
  pa1 = map(sensorValue1, 0, 1023, 0, 500) ;
  
  doc["A0_RAW_ADC"] = sensorValue0;
  doc["A1_RAW_ADC"]   = sensorValue1;
  doc["A0_0_10_V"] = outputValue0;
  doc["A1_0_10_V"]   = outputValue1;
  doc["PA_0"]   = pa0;
  doc["PA_1"]   = pa1;
  

  serializeJson(doc, Serial);
  Serial.println();
  delay(200);

}
