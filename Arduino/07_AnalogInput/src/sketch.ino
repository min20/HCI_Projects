int analogSENSOR = A0;
int sensorValue = 0;

void setup() {
	Serial.begin(9600);
}

void loop() {
	sensorValue = analogRead(analogSENSOR);

	Serial.print("Sensor value: ");
	Serial.println(sensorValue);

	delay(100);
}
