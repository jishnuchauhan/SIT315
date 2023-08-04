// PIR sensor input pin
const int pirPin = 2;

// LED output pin
const int ledPin = 3;

// Variable to store the PIR sensor state
int motionDetected = 0;

void setup() {
  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);

  // Set the PIR sensor pin as an input
  pinMode(pirPin, INPUT);

  // Initialize the Serial communication for debugging
  Serial.begin(9600);

  // Print initial status
  Serial.println("Motion Detection System - Status:");
  Serial.println("===================================");
}

void loop() {
  // Read the PIR sensor state
  motionDetected = digitalRead(pirPin);

  // Print PIR sensor state
  Serial.print("PIR Sensor State: ");
  Serial.println(motionDetected);

  if (motionDetected == HIGH) {
    // Motion detected, turn on the LED
    digitalWrite(ledPin, HIGH);
    Serial.println("Motion detected!");
    delay(1000); // delay to control LED activation duration
  } else {
    // No motion, turn off the LED
    digitalWrite(ledPin, LOW);
    Serial.println("No motion detected.");
  }
}
