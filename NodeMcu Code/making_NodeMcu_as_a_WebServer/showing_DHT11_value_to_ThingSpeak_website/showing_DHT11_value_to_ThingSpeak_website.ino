#include<ESP8266WiFi.h>
#include<DHT.h>
#include<ThingSpeak.h>
DHT dht(D5,DHT11);
WiFiClient client;
long cnl=1827422;
const char key[]="7UQJUWS8AU8WOVSM"; 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
WiFi.begin("ICE_Innovation_Lab","beinnovative#");
while(WiFi.status()!= WL_CONNECTED)
{
  Serial.println("..");
  delay(200);
}
Serial.println();
Serial.println("WiFi is connected");
Serial.println(WiFi.localIP());
dht.begin();
ThingSpeak.begin(client);

}

void loop() {
  // put your main code here, to run repeatedly:
float h=dht.readHumidity();
float t=dht.readTemperature();
Serial.println("Temperature"+ (String)t);
Serial.println("Humidity"+ (String)h);
ThingSpeak.writeField(cnl,1,t,key);
ThingSpeak.writeField(cnl,2,h,key);
delay(2000);

}
