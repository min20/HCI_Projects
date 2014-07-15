//NOTICE: CHECK ANALOG IN/OUTPUT
int PORTS[5] = {3, 5, 6, 9, 11};

//BRIGHTNESS MIN and MAX
int B_MIN = 0;
int B_MAX = 255;

//LED DELAY
float DELAY = 500;

//Current ON
int CURRENT_PORT;

void setup() {
	Serial.begin(9600);
	for (int idx = 0; idx < 5; idx++) {
		pinMode(PORTS[idx], OUTPUT);
	}
}

void loop() {
	if (Serial.available() <= 0) {
		return;
	}
	
	int targetPortIdx = Serial.read();
	if (targetPortIdx == '0') {
		switchTo(PORTS[0]);
	} else if(targetPortIdx == '1') {
		switchTo(PORTS[1]);
	} else if(targetPortIdx == '2') {
		switchTo(PORTS[2]);
	} else if(targetPortIdx == '3') {
		switchTo(PORTS[3]);
	} else if(targetPortIdx == '4') {
		switchTo(PORTS[4]);
	} else {
		//Serial.write("NO Such port.\n\n");
		Serial.println("NO Such port.");
	}
}

void switchTo(int port) {
	lightOff(CURRENT_PORT);
	CURRENT_PORT = port;
	lightOn(CURRENT_PORT);
}

void lighting(int port, boolean isOn) {
	int brightness = 0;
	for (brightness = B_MIN; brightness <= B_MAX; brightness++) {
		analogWrite(port, isOn? brightness : B_MAX - brightness);
		delayMicroseconds(DELAY);
	}
}

void lightOn(int port) {
	lighting(port, true);
}

void lightOff(int port) {
	lighting(port, false);
}

