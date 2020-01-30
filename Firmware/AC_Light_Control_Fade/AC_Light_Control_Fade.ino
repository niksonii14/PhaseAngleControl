int triacPin = 21;
long trigerTime;
int incomingByte = 0;

void IRAM_ATTR angle()
{
  delayMicroseconds(trigerTime);
  digitalWrite(triacPin, HIGH);
  delayMicroseconds(100);
  digitalWrite(triacPin, LOW);
}


void setup() {
  pinMode(triacPin, OUTPUT);
  pinMode(22, INPUT_PULLUP);
  digitalWrite(triacPin, LOW);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(22), angle, FALLING);
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
    delay(5000);
    switch (incomingByte) {
      case 49:
        trigerTime = 1000;
        Serial.println(trigerTime);
        break;
      case 50:
        trigerTime = 2000;
        Serial.println(trigerTime);
        break;
      case 51:
        trigerTime = 3000;
        Serial.println(trigerTime);
        break;
      case 52:
        trigerTime = 4000;
        Serial.println(trigerTime);
        break;
      case 53:
        trigerTime = 5000;
        Serial.println(trigerTime);
        break;
      case 54:
        trigerTime = 6000;
        Serial.println(trigerTime);
        break;
      case 55:
        trigerTime = 7000;
        Serial.println(trigerTime);
        break;
      case 56:
        trigerTime = 8000;
        Serial.println(trigerTime);
        break;
      case 57:
        trigerTime = 9000;
        Serial.println(trigerTime);
        break;
      case 58:
        trigerTime = 10000;
        Serial.println(trigerTime);
        break;
      default:
        trigerTime = 9000;
        break;
    }
  }

}
