#include<ESP8266WiFi.h>
WiFiClient client;
WiFiServer server(80);

#define led1 D5
#define led2 D6

String led1_state="off";
String led2_state="off";

String ssid="ICE_Innovation_Lab";
String password="beinnovative#";




void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);

digitalWrite(led1, LOW);
digitalWrite(led2,LOW);

WiFi.begin(ssid, password);

while(WiFi.status()!=WL_CONNECTED)
{
  Serial.print("..");
  delay(200);
}

Serial.println();
Serial.println("WiFi is connected");
Serial.println(WiFi.localIP());
server.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
client= server.available();
if(client==1)
{
  String request=client.readStringUntil('\n');
  request.trim();

  if(request=="GET /led1on HTTP/1.1")
  {
    led1_state="on";
    digitalWrite(led1,HIGH);
  }
  else if(request=="GET /led1off HTTP/1.1")
  {
    led1_state="off";
    digitalWrite(led1,LOW);
  }

  else if(request=="GET /led2on HTTP/1.1")
  {
    led2_state="on";
    digitalWrite(led2,HIGH);
  }
  else if(request=="GET /led2off HTTP/1.1")
  {
    led2_state="off";
    digitalWrite(led2,LOW);
  }
}

client.println("HTTP/1.1 200 ok");
client.println("Content-Type: text/html");
client.println();
client.println("<!DOCTYPE html>");
client.println("<html>");
client.println("<head>");
client.println(" <title>NodeMcu server</title>");

client.println("<style> .change{background-color: rgb(97, 97, 220);color:rgb(223, 159, 102); font-style: italic;  font-size: 34px;border-radius: 12px;border-color: brown;border-width: 5px;padding:15px;}");
client.println(" .algn {text-align: center;}");
client.println(" .change3{background-color: rgb(87, 177, 177);padding: 10px;font-size: 26px;border-radius: 10px;color: rgb(106, 13, 44);font-weight: bolder;}");

client.println(" .change2{background-color: rgb(129, 187, 136);border-radius: 10px;font-size: 44px;padding: 10px;} </style>" );

client.println("    </head>");
client.println("<body>");
  client.println( " <p class=\"algn\"><span class=\"change2\">controlling two led with NodeMCU</span></p> ");

if(led1_state=="off")
{
  client.println("<p class=\"algn\"><a href=\"/led1on\"><button class=\"change\" >ON</button></a></p>");
  client.println("<p class=\"algn\"><span class=\"change3\">LED 1 is OFF</span></p>");
}
else
{
  client.println("<p class=\"algn\"><a href=\"/led1off\"><button class=\"change\" >OFF</button></a></p>");
   client.println("<p class=\"algn\"><span class=\"change3\">LED 1 is ON</span></p>");
}

client.println("<br>");
client.println("<br>");

if(led2_state=="off")
{
client.println("<p class=\"algn\"><a href=\"/led2on\"><button class=\"change\" >ON</button></a></p>");
 client.println("<p class=\"algn\"><span class=\"change3\">LED 2 is OFF</span></p>");
}
else
{
client.println("<p class=\"algn\"><a href=\"/led2off\"><button class=\"change\" >OFF</button></a></p>");
 client.println("<p class=\"algn\"><span class=\"change3\">LED 2 is ON</span></p>");
}
}
