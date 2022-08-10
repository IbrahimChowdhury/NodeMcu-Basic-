#include<ESP8266WiFi.h>
WiFiClient client;
WiFiServer server(80);

#define led1 D6
#define led2 D7

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin("ICE_Innovation_Lab", "beinnovative#");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("..");
    delay(200);
  }
  Serial.println();
  Serial.println("WiFi is connected");
  Serial.println(WiFi.localIP());
  server.begin();

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  client = server.available();

  if (client == 1)
  {
    String request = client.readStringUntil('\n');
    Serial.println(request);
    request.trim();
    if (request == "GET /led1on HTTP/1.1")
    {
        digitalWrite(led1,HIGH);
    }

      if (request == "GET /led1off HTTP/1.1")
    {
        digitalWrite(led1,LOW);
    }

    if (request == "GET /led2on HTTP/1.1")
    {
        digitalWrite(led2,HIGH);
    }

      if (request == "GET /led2off HTTP/1.1")
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
client.println(" <title>NodeMcu server</title>");
client.println(" <h1>Welcome to our Website</h1>");
client.println(" </head>");
client.println("<body>");
client.println("<a href=\"/led1on\"\"><button>LED 1 ON</button></a>");
client.println("<a href=\"/led1off\"\"><button>LED 1 OFF</button></a>");
client.println("<br>");
client.println("<a href=\"/led2on\"\"><button>LED 2 ON</button></a>");
client.println("<a href=\"/led2off\"\"><button>LED 2 OFF</button></a>");
client.println("</body>");
client.println("</html>");


}
