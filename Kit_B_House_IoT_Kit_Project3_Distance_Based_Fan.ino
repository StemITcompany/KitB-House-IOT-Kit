int TRIGGER_PIN = 9;
int ECHO_PIN = 10;
int MOTOR_ENA = 5;
int MOTOR_IN1 = 7;
int MOTOR_IN2 = 8;

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(MOTOR_ENA, OUTPUT);
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);

  // Start with the fan off
  analogWrite(MOTOR_ENA, 0);
  
  Serial.begin(9600); // Initialize serial communication for debugging
}

void loop() {
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, HIGH);

  // Measure distance
  long duration;
  int distance;

  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2; // Calculate distance in centimeters

  // Adjust fan speed based on distance (reversed mapping)
  int fanSpeed = map(distance, 1, 30, 0, 255); // Adjust the range as needed

  // Make sure fanSpeed stays within valid limits
  fanSpeed = constrain(fanSpeed, 0, 255);

  // Set fan speed
  analogWrite(MOTOR_ENA, fanSpeed);

  // Log distance and fan speed to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm\tFan Speed: ");
  Serial.println(fanSpeed);

  // Add delay to control the update rate
  delay(100); // You can adjust the delay as needed
}
