#include <TroykaDHT.h>

// TDS treatment [1]
#define VREF 5.0
#define SCOUNT  30

// Analog pin
const int lightSnPin = A0; 
const int thermistorSnPin = A1;
const int phSnPin = A2;
const int tdsSnPin = A3;
const int dhtSn = 30;
const int pumpPin = 22;

// Global value
unsigned int dhtTemp, dhtHum, lightSn, phSn, tdsSn, thermSn;

// Digital pin
DHT dht(dhtSn, DHT21);

// Motor State
//String motorState = "LOW";
boolean pumpState = true;

// PH treatment
// int sensorValue = 0;
// unsigned long int avgValue;
// int buf[10],temp;

// TDS treatment [2]
int analogBuffer[SCOUNT]; 
int analogBufferTemp[SCOUNT];
int analogBufferIndex = 0,copyIndex = 0;
float averageVoltage = 0,tdsValue = 0,temperature = 25;

void setup() {
	Serial.begin(9600);
  dht.begin();
}

void loop() {
  lightRun(lightSnPin);
  thermistorRun(thermistorSnPin);
  dhtRun();
  phRun(phSnPin);
  tdsRun(tdsSnPin);
//  runPump();

  

  delay(2000);
}
