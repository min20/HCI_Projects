int LED = 9;
int BUTTON = 2;

int message;
boolean isOn = false;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  if (Serial.available()) {
    message = Serial.read();
    
    if (message == '1') {
      Serial.println("LED is TURNED ON.");
      isOn = true;
    } else {
      Serial.println("LED is TRUNED OFF.");
      isOn = false;
    }
    
    if (isOn) {
      digitalWrite(LED, HIGH);
    } else {
      digitalWrite(LED, LOW);
    }
  }
  
  if (digitalRead(BUTTON) == HIGH) {
    Serial.println("BUTTON is CLICKED.");
  }  

}
