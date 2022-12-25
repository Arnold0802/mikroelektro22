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
int value = 0;
char numberArray[20];
String stringOne = "";
String stringTwo = "";

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
 Serial.begin(9600);
 sensors.begin();
}
// the loop routine runs over and over again forever:
void loop() {
  //Serial.print(" Requesting temperatures...");
  //sensors.requestTemperatures(); // Send the command to get temperatures
  //Serial.println("DONE");
  //Serial.print("Temperature is: ");
  //Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"? 
    // You can have more than one IC on the same bus. 
    // 0 refers to the first IC on the wire
  
  value = analogRead(potentiometerPIN);    // It reads the value from the sensor
  value = value/32;
  //itoa(value,numberArray,10);
  stringOne = String(value);  
  if (value<10)
  {
    stringOne = "000"+stringOne;     
  }
  else
  {
    stringOne = "00"+stringOne;    
  }  
  //itoa(value,numberArray,10);
  Serial.println(value); 
  //Reset();// use this function to reset the display
  //printDisplay(stringOne,100);// use this function to print a string (has numbers, characters or phrases) when the length of string is 4 or less than 4, the second variable is the time for printing on display
  
  // printDigit('1',D1);
  // delay(2);  
  // printDigit('2',D2);
  // delay(2);
  // printDigit('3',D3);
  // delay(2);
  // printDigit('4',D4);
  // delay(2);
  
  // digitalWrite(D1, 0);
  // digitalWrite(D2, 0);
  // digitalWrite(D3, 0);
  // digitalWrite(D4, 0);
  
  //delay(1000);
  //Reset();
  
  sensors.requestTemperatures();
  Serial.print(sensors.getTempCByIndex(0));
  //delay(1000);
  
  // digitalWrite(LED, HIGH);
  // delay(500);
  // digitalWrite(LED, LOW);
  // delay(500);

  digitalWrite(D1, 1);
  digitalWrite(D2, 1);
  digitalWrite(D3, 0);
  digitalWrite(D4, 1);
  digitalWrite(pinA, 1);
  digitalWrite(pinB, 1);
  digitalWrite(pinC, 0);
  digitalWrite(pinD, 0);
  delay(500);
  digitalWrite(D1, 0);
  digitalWrite(D2, 1);
  digitalWrite(D3, 1);
  digitalWrite(D4, 1);
  digitalWrite(pinA, 0);
  digitalWrite(pinB, 0);
  digitalWrite(pinC, 1);
  digitalWrite(pinD, 1);
  delay(500);
  digitalWrite(D3, 0);
  

}