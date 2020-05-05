#include <Servo.h>
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3

//Ágúst Birgir
//dc motors
const int motorPin1  = 5;  
const int motorPin2  = 6;  
//Motor B
const int motorPin3  = 10; 
const int motorPin4  = 9;  

//servo motor
Servo vinstri;
Servo haegri;
int motor_pinni_v = 13;
int motor_pinni_h = 12;
int psb1 = 7;
int psb2 = 8;
//ultra sonic
long duration; // variable for the duration of sound wave travel
int distance;

void setup()
{	
  //servo motor
  	vinstri.attach(motor_pinni_v);
  	haegri.attach(motor_pinni_h);
  	pinMode(psb1, INPUT);
  	pinMode(psb2, INPUT);
  //ultra sonic
  	pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
  
}

void loop()
{
  //servo motor
  digitalRead(psb1);
  if(psb1 = 1){
    vinstri.write(30);
    haegri.write(45);
  }
  // ultra sonic
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}