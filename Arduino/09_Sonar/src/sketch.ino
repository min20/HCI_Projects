#define trigPin 3
#define echoPin 5
#define LED 9

int maxRange = 200;
int minRange = 0;
long duration;
long distance;
float outputValue = 0.0;

void setup() {
	Serial.begin(9600);
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
}

void loop() {
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);

	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);

	digitalWrite(trigPin, LOW);
	duration = pulseIn(echoPin, HIGH);

	distance = duration / 58.2;

	if (distance >= maxRange || distance <= minRange) {
		Serial.println("-1");
	} else {
		Serial.println(distance);
		outputValue = map(distance, minRange, maxRange, 0, 255);
		analogWrite(LED, outputValue);
	}

	delay(30);
}
