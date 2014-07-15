// Use PIN 9
int led = 9;
int MAX_ANALOG = 255;

// Initialize PINs
void setup() {
  // Declare PIN 9 to be an OUTPUT
  pinMode(led, OUTPUT);
}

// Main logic
void loop() {
  // current brightness
  int current = 0;
  // initial brightness
  int initial = 10;
  
  for (current = initial; current <= MAX_ANALOG; current++) {
    analogWrite(led, current);
    delay(10);
  }
  for (current = MAX_ANALOG; current > initial; current--) {
    analogWrite(led, current);
    delay(10);
  }
}
