

#define led D6 
void setup() {
  // put your setup code here, to run once:
pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int i;
for(i=0;i<255;i+=5)
{
  analogWrite(led, i);
  delay(50);
}

for(i=255;i>0;i-=5)
{
  analogWrite(led, i);
  delay(50);
}
}
