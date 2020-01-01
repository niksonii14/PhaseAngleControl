#define zeroPin 2
#define triacPin 3
int ledPin = 13;
int trigerTime = 300;
int pulseDelay = 0;

void setup() {

  Serial.begin(9600);

  pinMode(triacPin, OUTPUT);
  digitalWrite(triacPin, LOW);

  pinMode(ledPin, OUTPUT);

  attachInterrupt(0, angle, RISING);

  //  for (int k = 0; k < 3; k++)
  //  {
  //    digitalWrite(ledPin, HIGH);
  //    delay(1000);
  //    digitalWrite(ledPin, LOW);
  //    delay(1000);
  //  }

  digitalWrite(ledPin, LOW);
  delay(500);
  digitalWrite(ledPin, HIGH);

  Serial.println("Loop Start...");

}

void loop() {

  if (Serial.available() > 0) {
    // read the incoming byte:
    pulseDelay = Serial.read();

    // say what you got:
//    Serial.print("I received: ");
//    Serial.println(pulseDelay, DEC);
  }
  //pulseDelay = 10;

  //  for (int i = 5; i <= 128; i++)
  //  {
  //    pulseDelay = i;
  //    delay(10);
  //  }
  //
  //  for (int j = 128; j >= 5; j--)
  //  {
  //    pulseDelay = j;
  //    delay(10);
  //  }

}


void angle()
{
  trigerTime = (pulseDelay * 75);
  delayMicroseconds(trigerTime);
  digitalWrite(triacPin, HIGH);
  delayMicroseconds(100);
  digitalWrite(triacPin, LOW);
}
