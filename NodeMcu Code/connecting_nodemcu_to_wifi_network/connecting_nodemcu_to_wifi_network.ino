
#include<ESP8266WiFi.h>
void setup()
{
Serial.begin(9600);
WiFi.begin("Redmi note", "123456789");
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
