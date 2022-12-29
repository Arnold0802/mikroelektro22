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
#define pinF 17
#define pinG 8
#define pinDP 15
#define D1 6
#define D2 9
#define D3 0
#define D4 1
#define ONE_WIRE_BUS 18
#include "array.h"
#include "functions.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SPI.h>
#include <Ethernet.h>
#include <UbidotsEthernet.h>

char const * TOKEN = "BBFF-8mQkrx1ITKZTQDhsuyqNt2DS9ObFPY"; // Assign your Ubidots TOKEN
char const * VARIABLE_LABEL_1 = "targettemp"; // Assign the unique variable label to send the data
char const * VARIABLE_LABEL_2 = "currenttemp"; // Assign the unique variable label to send the data
char const * VARIABLE_LABEL_3 = "heating"; // Assign the unique variable label to send the data

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
int heatOn = 0;
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(192, 168, 1, 189);
IPAddress dbserver(192, 168, 1, 70);

//EthernetClient ArduinoClient;
//Ubidots client(TOKEN);

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
  //Ethernet.begin(mac, ip);
  // Serial.print(F("Starting ethernet..."));
  // if (!Ethernet.begin(mac)) {
  //   Serial.println(F("failed"));
  // } else {
  //   Serial.println(Ethernet.localIP());
  // }
  // /* Give the Ethernet shield a second to initialize */
  // delay(2000);
  // Serial.println(F("Ready"));
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
  Reset();
  if(doorState)
  {
    digitalWrite(LED, LOW);
    heatOn = 0;   
  }
  else
  {
    if(targetTemp == 0)
    {
      digitalWrite(LED, LOW);
      heatOn = 0;
    }  
    else if(targetTemp>currentTemp)
    {
      digitalWrite(LED, HIGH);
      heatOn = 1;
    }
    else
    {
      digitalWrite(LED, LOW);
      heatOn = 0;
    }
  }
  
  //Ethernet.maintain();
  // /* Sensors readings */
  // float value_1 = targetTemp;
  // float value_2 = currentTemp;
  // float value_3 = heatOn;
  // /* Sending values to Ubidots */
  // client.add(VARIABLE_LABEL_1, value_1);
  // client.add(VARIABLE_LABEL_2, value_2);
  // client.add(VARIABLE_LABEL_3, value_3);
  // client.sendAll();
  delay(500);
}
