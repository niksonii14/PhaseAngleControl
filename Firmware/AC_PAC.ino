int triacPin = 2; //Gate Pulse pin 
long trigerTime = 0;
int incomingByte = 0;

const int acPeriod = 10000; // For 50Hz, one cycle = 20ms, half cycle = 10ms = 10000us

void IRAM_ATTR angle() {
  delayMicroseconds(trigerTime);
  digitalWrite(triacPin, HIGH);
  delayMicroseconds(10); // Pulse duration
  digitalWrite(triacPin, LOW);
}

void setup() {
  pinMode(triacPin, OUTPUT);
  digitalWrite(triacPin, LOW);
  pinMode(4, INPUT_PULLUP);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(4), angle, FALLING); // Zero crossing
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
  }

  switch (incomingByte) {
    case 49: // Press '1' for 50V output
      trigerTime = mapVoltageToDelay(20);
      Serial.println("20V selected, trigerTime: " + String(trigerTime));
      break;
    case 50: // Press '2' for 100V output
      trigerTime = mapVoltageToDelay(40);
      Serial.println("40V selected, trigerTime: " + String(trigerTime));
      break;
    case 51: // Press '3' for 100V output
      trigerTime = mapVoltageToDelay(60);
      Serial.println("60V selected, trigerTime: " + String(trigerTime));
      break;
    case 52: // Press '4' for 100V output
      trigerTime = mapVoltageToDelay(80);
      Serial.println("80V selected, trigerTime: " + String(trigerTime));
      break;
    case 53: // Press '5' for 100V output
      trigerTime = mapVoltageToDelay(90);
      Serial.println("90V selected, trigerTime: " + String(trigerTime));
      break;
    default:
      
      break;
  }
}

long mapVoltageToDelay(int voltage) {
  // Map voltage to delay time (assume linear approximation)
  float phaseAngle = acos(voltage / 100.0) * 180 / PI; // Calculate phase angle //100 is input peak voltage.(change this according to you)
  return (phaseAngle / 180.0) * acPeriod; // Convert phase angle to microseconds
}
