int AXIS_X = A4;
int AXIS_Y = A2;
int AXIS_Z = A0;

int valueX = 0;
int valueY = 0;
int valueZ = 0;

int LED_R = 9;
int LED_G = 5;
int LED_B = 3;

float valueR = 0;
float valueG = 0;
float valueB = 0;

void setup() {
	Serial.begin(9600);
}

void loop() {
	valueX = analogRead(AXIS_X);
	valueY = analogRead(AXIS_Y);
	valueZ = analogRead(AXIS_Z);

	Serial.print("X: ");
	Serial.print(valueX);
	Serial.print(", Y: ");
	Serial.print(valueY);
	Serial.print(", Z: ");
	Serial.println(valueZ);

	valueR = map(valueX, 260, 410, 0, 255);
	valueG = map(valueY, 260, 410, 0, 255);
	valueB = map(valueZ, 260, 410, 0, 150);

	Serial.print("RED: ");
	Serial.print(valueR);
	Serial.print(", GREEN: ");
	Serial.print(valueG);
	Serial.print(", BLUE: ");
	Serial.println(valueB);

	analogWrite(LED_R, valueR);
	analogWrite(LED_G, valueG);
	analogWrite(LED_B, valueB);

	delay(100);
}
