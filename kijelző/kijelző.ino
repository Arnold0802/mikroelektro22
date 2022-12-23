#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(192, 168, 1, 189);
IPAddress dbserver(192, 168, 1, 70);
EthernetClient ArduinoClient;
float temp = 10;

void setup() {
  // put your setup code here, to run once:
  Ethernet.begin(mac, ip);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.write("hello");

  float hum = 30;
  float heat_indexC = 35;
  if (ArduinoClient.connect(dbserver, 80))
  {
    Serial.println("connected");
    ArduinoClient.print("GET /Arduinoproj1/Arduino1.php?"); //Connecting and Sending values to database
    ArduinoClient.print("temperature=");
    ArduinoClient.print(temp);
    ArduinoClient.print("&humidity=");
    ArduinoClient.print(hum);
    ArduinoClient.print("&heat_index=");
    ArduinoClient.println(heat_indexC);
  }
  else
  {
    Serial.println("not connected");
  }
  temp++;
  delay(5000);
}
