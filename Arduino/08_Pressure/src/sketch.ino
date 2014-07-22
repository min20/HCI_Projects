#define PIN_LED 9
#define PIN_ASENSOR A0

int sensorValue = 0;
float outputValue = 0;

void setup() {
	Serial.begin(9600);
}

void loop() {
	sensorValue = analogRead(PIN_ASENSOR);

	Serial.print("sensorValue: ");
	Serial.println(sensorValue);

	outputValue = map(sensorValue, 0, 1024, 0, 255);

	Serial.print("outputValue: ");
	Serial.println(outputValue);

	analogWrite(PIN_LED, outputValue);

	delay(100);
}
