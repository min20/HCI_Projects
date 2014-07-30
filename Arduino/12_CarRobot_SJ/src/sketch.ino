/*
  NAVER Software Education Project(Arduino): Car Robot
 Copyright (C) 2014  Kyoungchin SEO, NHN NEXT
 
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

//#include "Ultrasonic.h"

int MOTOR_A_DIR = 12;
int MOTOR_A_BRAKE = 9;
int MOTOR_A_PWM = 3;

int MOTOR_B_DIR = 13;
int MOTOR_B_BRAKE = 8;
int MOTOR_B_PWM = 11;

int MOTOR_SPEED = 100;
int delayTime = 300;

//Ultrasonic ultrasonic(7);

#define echoPin 7 // Echo Pin 
#define trigPin 8 // Trigger Pin

int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed

long distance,duration;

void setup() 
{
  Serial.begin(9600);

  pinMode(MOTOR_A_DIR,OUTPUT);
  pinMode(MOTOR_A_BRAKE, OUTPUT);  
  pinMode(MOTOR_B_DIR,OUTPUT);
  pinMode(MOTOR_B_BRAKE,OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() 
{  
  //distance = ultrasonic.MeasureInCentimeters();
  getDistance();
  //distance = 30;
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

int getDistance() 
{
  
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  //Calculate the distance (in cm) based on the speed of sound. 
  distance = duration/58.2;
  
  if (distance >= maximumRange || distance <= minimumRange){ 
    Serial.println("-1");
  }
  
  return distance;

} 


