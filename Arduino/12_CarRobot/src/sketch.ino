int MOTOR_A_DIR = 12;
int MOTOR_A_BRAKE = 9;
int MOTOR_A_PWM = 3;

int MOTOR_B_DIR = 13;
int MOTOR_B_BRAKE = 8;
int MOTOR_B_PWM = 11;

int MOTOR_SPEED = 100;
int delayTime = 0;

//Ultrasonic ultrasonic(7);
int trigPin = 2;
int echoPin = 5;

long duration = 0;
long distance = 0;

void setup() {
	Serial.begin(9600);

	pinMode(MOTOR_A_DIR,OUTPUT);
	pinMode(MOTOR_A_BRAKE, OUTPUT);  
	pinMode(MOTOR_B_DIR,OUTPUT);
	pinMode(MOTOR_B_BRAKE,OUTPUT);

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

	Serial.println(distance);

	if (distance > 25) 
	{
		digitalWrite(MOTOR_A_DIR,HIGH);
		digitalWrite(MOTOR_A_BRAKE, LOW);
		analogWrite(MOTOR_A_PWM,MOTOR_SPEED);    
		digitalWrite(MOTOR_B_DIR,HIGH);
		digitalWrite(MOTOR_B_BRAKE,LOW);
		analogWrite(MOTOR_B_PWM,MOTOR_SPEED);
		delay(delayTime);
	} 
	else if (distance < 10) 
	{
		digitalWrite(MOTOR_A_BRAKE, HIGH);
		digitalWrite(MOTOR_B_BRAKE, HIGH);
		delay(delayTime);
	} 
	else 
	{       
		digitalWrite(MOTOR_A_DIR,LOW);
		digitalWrite(MOTOR_A_BRAKE, LOW);
		analogWrite(MOTOR_A_PWM,MOTOR_SPEED);    
		digitalWrite(MOTOR_B_DIR,HIGH);
		digitalWrite(MOTOR_B_BRAKE,LOW);
		analogWrite(MOTOR_B_PWM,MOTOR_SPEED);
		delay(delayTime);
	}
}

