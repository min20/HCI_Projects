//NOTICE: CHECK ANALOG IN/OUTPUT
int ports[5] = {3, 5, 6, 9, 11};

//BRIGHTNESS MIN and MAX
int B_MIN = 0;
int B_MAX = 255;

//LED DELAY
float DELAY = 500;
void setup() {
	for (int idx = 0; idx < 5; idx++) {
		pinMode(ports[idx], OUTPUT);
	}
}

void loop() {
	for (int idx = 0; idx < 8; idx++) {
		smoothBlink(ports[idx < 4 ? idx : 8 - idx]);
	}
}

void smoothBlink(int port) {
	lightOn(port);
	lightOff(port);
}

void lighting(int port, boolean isOn) {
	int current = 0;
	for (current = B_MIN; current <= B_MAX; current++) {
		analogWrite(port, isOn? current : B_MAX - current);
		delayMicroseconds(DELAY);
	}

}

void lightOn(int port) {
	lighting(port, true);
}

void lightOff(int port) {
	lighting(port, false);
}

