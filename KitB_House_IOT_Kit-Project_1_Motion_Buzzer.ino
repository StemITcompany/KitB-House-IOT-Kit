int pirPin = 3;
int buzzerPin = 7;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {

  int checkSensor = digitalRead(pirPin);
  if (checkSensor == HIGH) {
    digitalWrite(buzzerPin, HIGH);
  } 
  
  else {
    digitalWrite(buzzerPin, LOW);
  }
}
