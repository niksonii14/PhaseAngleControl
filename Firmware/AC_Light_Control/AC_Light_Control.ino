int triacPin = 2;
long trigerTime = 0;

int incomingByte = 0;

void IRAM_ATTR angle()
{
  delayMicroseconds(trigerTime);
  digitalWrite(triacPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triacPin, LOW);
}

void setup() {
  pinMode(triacPin, OUTPUT);
  digitalWrite(triacPin, LOW);
  //  pinMode(22, INPUT_PULLUP);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(22), angle, RISING);
}

void loop() {

  if (Serial.available() > 0)
  {
    incomingByte = Serial.read();
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
  }

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
      digitalWrite(triacPin, LOW);
    //      trigerTime = 8000;
    //      Serial.println(trigerTime);
    //      break;
    case 57:
      digitalWrite(triacPin, HIGH);
      //      trigerTime = 0;
      //      Serial.println(trigerTime);
      break;
    case 58:
      //      trigerTime = 10000;
      //      Serial.println(trigerTime);
      digitalWrite(triacPin, LOW);
      break;
    default:
      trigerTime = 9000;
      break;
  }

}
