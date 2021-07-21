#include <NewPing.h>

#define TRIGGER_PIN  13  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     17  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

const int RIGHTFORWARD = 7; //Yellow
const int RIGHTREVERSE = 8; //Red
const int RIGHTENABLE = 9; //Blue
const int LEFTFORWARD = 11; //Yellow
const int LEFTREVERSE = 12; //Red
const int LEFTENABLE = 10; //Blue

const int LEFT_FEEDBACK = 3; // Pin numbers on Rover
const int RIGHT_FEEDBACK = 2;
volatile int leftcounter = 0; // initiate counter to zero for start
volatile int rightcounter = 0; // counter could always be reset

const int LEFT_LDR = A7;
const int CENTRE_LDR = A6;
const int RIGHT_LDR = A2;

void setup()
{
  pinMode(RIGHTFORWARD, OUTPUT);
  pinMode(RIGHTREVERSE, OUTPUT);
  pinMode(RIGHTENABLE, OUTPUT);
  pinMode(LEFTFORWARD, OUTPUT);
  pinMode(LEFTREVERSE, OUTPUT);
  pinMode(LEFTENABLE, OUTPUT);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK),LeftMotorISR,RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK),RightMotorISR,RISING);
  sonar.ping_cm();
  
  pinMode(LEFT_LDR, INPUT);
  pinMode(CENTRE_LDR, INPUT);
  pinMode(RIGHT_LDR, INPUT);
}

void loop(){
  int leftLight = analogRead(LEFT_LDR);
  int centreLight = analogRead(CENTRE_LDR);
  int rightLight = analogRead(RIGHT_LDR);
  
  if ((leftLight > centreLight) && (leftLight > rightLight)) {
    turnLeft(250,255,255);
  }
  else if ((centreLight >= leftLight)&& (centreLight >= rightLight)){
    forward(250,255);
  }
  else{ 
    turnRight(250,255,255);
  }
}

void forward(int seconds, int speed) {
  analogWrite(RIGHTENABLE, speed); //
  digitalWrite(RIGHTFORWARD, HIGH); 
  digitalWrite(RIGHTREVERSE, LOW);
  analogWrite(LEFTENABLE, speed); //
  digitalWrite(LEFTFORWARD, HIGH);
  digitalWrite(LEFTREVERSE, LOW); 
  delay(seconds);
}  
  
void backward(int seconds, int speed){
  analogWrite(RIGHTENABLE, speed); //
  digitalWrite(RIGHTFORWARD, LOW);
  digitalWrite(RIGHTREVERSE, HIGH);
  analogWrite(LEFTENABLE, speed); //
  digitalWrite(LEFTFORWARD, LOW);
  digitalWrite(LEFTREVERSE, HIGH); 
  delay(seconds);
}
  
  
void roverStop(int seconds)
{
  digitalWrite(RIGHTENABLE, LOW); //
  digitalWrite(RIGHTFORWARD, LOW);
  digitalWrite(RIGHTREVERSE, LOW); 
  digitalWrite(LEFTENABLE, LOW); //
  digitalWrite(LEFTFORWARD, LOW);
  digitalWrite(LEFTREVERSE, LOW);
  delay(seconds);
}

void turnLeft(int seconds, int speedLeft, int speedRight) {
  analogWrite(RIGHTENABLE, speedRight); //
  digitalWrite(RIGHTFORWARD, HIGH); 
  digitalWrite(RIGHTREVERSE, LOW);
  analogWrite(LEFTENABLE, speedLeft); //
  digitalWrite(LEFTFORWARD, LOW);
  digitalWrite(LEFTREVERSE, HIGH); 
  delay(seconds);
}

void turnRight(int seconds, int speedLeft, int speedRight) {
  analogWrite(RIGHTENABLE, speedRight); //
  digitalWrite(RIGHTFORWARD, LOW); 
  digitalWrite(RIGHTREVERSE, HIGH);
  analogWrite(LEFTENABLE, speedLeft); //
  digitalWrite(LEFTFORWARD, HIGH);
  digitalWrite(LEFTREVERSE, LOW); 
  delay(seconds);
}

void LeftMotorISR(){
  // adds one to the counter on each motor revolution
  leftcounter++;
}
void RightMotorISR(){
  // adds one to the counter on each motor revolution
  rightcounter++;
}      
