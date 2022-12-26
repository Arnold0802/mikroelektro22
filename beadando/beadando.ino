/*
 Showing numbers, chars and phrases
    A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---
    D
*/
#define common_cathode 0
#define common_anode 1
bool mode = common_cathode;
#define pinA 2
#define pinB 3
#define pinC 4
#define pinD 5
#define pinE 7
#define pinF 12
#define pinG 8
#define pinDP 13
#define D1 6
#define D2 9
#define D3 10
#define D4 11
#define ONE_WIRE_BUS 18
#include "array.h"
#include "functions.h"
#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
int LED = 19;
int potentiometerPIN = 2;
int doorOpenPIN = 14;
int value = 0;
char numberArray[20];
String stringOne = "";
String stringTwo = "";
int currentTemp = 0;
int targetTemp = 0;
int doorState = 0;

void setup() {                
 // initialize the digital pins as outputs.
 pinMode(pinA, OUTPUT);     
 pinMode(pinB, OUTPUT);     
 pinMode(pinC, OUTPUT);     
 pinMode(pinD, OUTPUT);     
 pinMode(pinE, OUTPUT);     
 pinMode(pinF, OUTPUT);     
 pinMode(pinG, OUTPUT); 
 pinMode(pinDP, OUTPUT);  
 pinMode(D1, OUTPUT);  
 pinMode(D2, OUTPUT);  
 pinMode(D3, OUTPUT);  
 pinMode(D4, OUTPUT); 
 pinMode(LED, OUTPUT);
 pinMode(doorOpenPIN, INPUT_PULLUP); 
 Serial.begin(9600);
 sensors.begin();
}
// the loop routine runs over and over again forever:
void loop() {
  value = analogRead(potentiometerPIN);    // It reads the value from the potentiometer
  doorState = digitalRead(doorOpenPIN);
  Serial.println(doorState);
  targetTemp = value/32; 
  stringOne = String(targetTemp);  
  if (targetTemp<10) //this part is for the 4 digit display to shift the noumbers
  {
    stringOne = "   "+stringOne;     
  }
  else
  {
    stringOne = "  "+stringOne;    
  }  
  Serial.println(targetTemp); 
  //Reset();// use this function to reset the display
  printDisplay(stringOne,500);
  Reset();
  
  sensors.requestTemperatures();
  //Serial.println(sensors.getTempCByIndex(0));
  currentTemp =   int(sensors.getTempCByIndex(0));
  stringTwo = String(currentTemp);
  Serial.println(stringTwo);  
  //delay(1000);
  printDisplay(stringTwo,500);
  if(doorState)
  {
    digitalWrite(LED, LOW);   
  }
  else
  {
    if(targetTemp == 0)
    {
      digitalWrite(LED, LOW);
    }  
    else if(targetTemp>currentTemp)
    {
      digitalWrite(LED, HIGH);
    }
    else
    {
      digitalWrite(LED, LOW);
    }
  }  
   delay(500);
}