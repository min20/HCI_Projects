const int DATA = 11;
const int LATCH = 9;
const int CLK = 7;

void setup(){
	pinMode(DATA, OUTPUT);
	pinMode(LATCH, OUTPUT);
	pinMode(CLK, OUTPUT);

	digitalWrite(LATCH,LOW);
	shiftOut(DATA, CLK, MSBFIRST, B10000001);
	digitalWrite(LATCH, HIGH);
}

void loop() {

}
