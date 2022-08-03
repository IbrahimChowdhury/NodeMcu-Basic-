#include<ESP8266WiFi.h>
WiFiClient client;
WiFiServer server(80);
void setup()
{
  Serial.begin(9600);

  WiFi.begin("Redmi note","123456789");
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print("..");
    delay(200);
  }
  Serial.println();
  Serial.println("NodeMcu is connected");
  Serial.println(WiFi.localIP());
}

void loop()
{
client=server.available();
if(client==1)
{
  String request=client.readStringUntil('\n');
  Serial.println(request);
}

}
