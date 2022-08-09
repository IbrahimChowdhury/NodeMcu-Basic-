
#include<ESP8266WiFi.h>
void setup()
{
Serial.begin(9600);
WiFi.begin("ICE_Innovation_Lab", "beinnovative#");
  while(WiFi.status()!= WL_CONNECTED)
  {
    Serial.print("..");
    delay(200);
  }
  Serial.println();
  Serial.println("WiFi is connected");
  Serial.println(WiFi.localIP());
}


void loop()
{
  
}
