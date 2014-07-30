int MOTOR_A_DIR = 12;
int MOTOR_A_BRAKE = 9;
int MOTOR_A_PWM = 3;

int MOTOR_B_DIR = 13;
int MOTOR_B_BRAKE = 8;
int MOTOR_B_PWM = 11;

int MOTOR_SPEED = 100;

void setup() {
	pinMode(MOTOR_A_DIR,OUTPUT);
	pinMode(MOTOR_A_BRAKE, OUTPUT);  
	pinMode(MOTOR_B_DIR,OUTPUT);
	pinMode(MOTOR_B_BRAKE,OUTPUT);
}

void loop() {
	digitalWrite(MOTOR_A_DIR,HIGH);
	digitalWrite(MOTOR_A_BRAKE, LOW);
	analogWrite(MOTOR_A_PWM,MOTOR_SPEED);

	digitalWrite(MOTOR_B_DIR,HIGH);
	digitalWrite(MOTOR_B_BRAKE,LOW);
	analogWrite(MOTOR_B_PWM,MOTOR_SPEED);

	delay(3000);

	digitalWrite(MOTOR_A_BRAKE, HIGH);
	digitalWrite(MOTOR_B_BRAKE, HIGH);

	delay(1000);

	digitalWrite(MOTOR_A_DIR,LOW);
	digitalWrite(MOTOR_A_BRAKE,LOW);
	analogWrite(MOTOR_A_PWM,MOTOR_SPEED);

	digitalWrite(MOTOR_B_DIR,LOW);
	digitalWrite(MOTOR_B_BRAKE,LOW);
	analogWrite(MOTOR_B_PWM,MOTOR_SPEED);

	delay(3000);

	digitalWrite(MOTOR_A_BRAKE, HIGH);
	digitalWrite(MOTOR_B_BRAKE, HIGH);

	delay(1000);
}

