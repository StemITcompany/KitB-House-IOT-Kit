const int ledPin = 3;
const int analogPin = A0;
int analogValue = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  analogValue = analogRead(analogPin);
  int dutyCycle = map(analogValue, 0, 1023, 0, 255);
  analogWrite(ledPin, dutyCycle);
  delay(100);
}
