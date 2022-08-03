#include<ESP8266WiFi.h>
WiFiClient client;
WiFiServer server(80);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
WiFi.begin("ICE_Innovation_Lab", "beinnovative#");
while(WiFi.status()!= WL_CONNECTED)
{
  Serial.print("..");
  delay(200);
}

Serial.println();
Serial.println("wifi is connected");
Serial.println(WiFi.localIP());
server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
client = server.available();
if(client == 1)
{
  String request = client.readStringUntil('\n');
  Serial.println(request);
}
}
