#define zeroPin 2
#define triacPin 3
int ledPin=13;
int buzzPin=5;
int trigerTime = 9000;
int pulseDelay;

void setup(){
  
  pinMode(triacPin, OUTPUT);
  
  digitalWrite(triacPin, LOW);
  
  attachInterrupt(0, angle, RISING);
  pinMode(5, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  for(int k=0;k<3;k++)
  {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
  }

  for(int k=0;k<3;k++)
  {
    digitalWrite(buzzPin, HIGH);
    delay(100);
    digitalWrite(buzzPin, LOW);
    delay(100);
  }
  
  digitalWrite(ledPin, LOW);
  delay(500);
  digitalWrite(ledPin, HIGH);

}

void loop(){
  
  for (int i=12; i <= 120; i++)
  {
  pulseDelay = i;
  delay(10);
  }

  for (int i=120; i >= 12; i--)
  {
  pulseDelay = i;
  delay(10);
  }
  delay(2000);
}


void angle()
{
  trigerTime = (pulseDelay*75);
  delayMicroseconds(trigerTime);
  digitalWrite(triacPin, HIGH);
  delayMicroseconds(100);
  digitalWrite(triacPin, LOW);
}
