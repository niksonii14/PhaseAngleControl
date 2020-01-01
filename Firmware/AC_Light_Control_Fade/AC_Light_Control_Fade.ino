int triacPin = 3;
long trigerTimeValue;
long trigerTime;

int incomingByte = 0;


void setup() {
  pinMode(triacPin, OUTPUT);
  digitalWrite(triacPin, LOW);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2), angle, RISING);
}

void loop() {

  //  if (Serial.available() > 0)
  //  {
  //    incomingByte = Serial.read();
  //    Serial.print("I received: ");
  //    Serial.println(incomingByte, DEC);
  //  }

  delay(2000);

  for (int i = 49; i < 57; i++)
  {
    incomingByte = i;
    delay(1000);
    switch (incomingByte) {
      case 49:
        trigerTimeValue = 1000;
        Serial.println(trigerTimeValue);
        break;
      case 50:
        trigerTimeValue = 2000;
        Serial.println(trigerTimeValue);
        break;
      case 51:
        trigerTimeValue = 3000;
        Serial.println(trigerTimeValue);
        break;
      case 52:
        trigerTimeValue = 4000;
        Serial.println(trigerTimeValue);
        break;
      case 53:
        trigerTimeValue = 5000;
        Serial.println(trigerTimeValue);
        break;
      case 54:
        trigerTimeValue = 6000;
        Serial.println(trigerTimeValue);
        break;
      case 55:
        trigerTimeValue = 7000;
        Serial.println(trigerTimeValue);
        break;
      case 56:
        trigerTimeValue = 8000;
        Serial.println(trigerTimeValue);
        break;
      case 57:
        trigerTimeValue = 9000;
        Serial.println(trigerTimeValue);
        break;
      case 58:
        trigerTimeValue = 10000;
        Serial.println(trigerTimeValue);
        break;
      default:
        trigerTimeValue = 9000;
        break;
    }
  }

}



void angle()
{
  trigerTime = trigerTimeValue;
  delayMicroseconds(trigerTime);
  digitalWrite(triacPin, HIGH);
  delayMicroseconds(100);
  digitalWrite(triacPin, LOW);
}
