#include<ESP8266WiFi.h>
#define led1 D5
#define led2 D6
WiFiClient client;
WiFiServer server(80);
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
  Serial.println("WiFI is connected");
  Serial.println(WiFi.localIP()); 
  server.begin();

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
}


void loop()
{
  client = server.available();
  if(client == 1)
  {
    String request = client.readStringUntil('\n');
    request.trim();
    if(request== "GET /led1on HTTP/1.1")
    {
      digitalWrite(led1,HIGH);
    }
    if(request== "GET /led1off HTTP/1.1")
    {
      digitalWrite(led1,LOW);
    }

    if(request== "GET /led2on HTTP/1.1")
    {
      digitalWrite(led2,HIGH);
    }
    if(request== "GET /led2off HTTP/1.1")
    {
      digitalWrite(led2,LOW);
    }
  }
client.println("HTTP/1.1 200 ok");
client.println("Content-Type: text/html");
client.println();

client.println("<!DOCTYPE html>");
client.println("<html>");
client.println("<head>");
client.println("<title>Testing a web site</title>");
client.println("</head>");
client.println("<body>");
client.println("<h1>Led off on section </h1>");
if(led1=='0')
{
  client.println("<a href=\"/led1on\"/><button>Led1on</button></a>");
}
if(led1=='1')
{
client.println("<a href=\"/led1off\"/><button>Led1off</button></a>");
}


client.println("    <br>");
if(led2=='0')
{
client.println(" <a href=\"/led2on\"/><button>Led2on</button></a>");
}

if(led2=='1')
{
client.println("<a href=\"/led2off\"/><button>Led2off</button></a>");
}

client.println("</body>");
client.println("</html>");

  
}
