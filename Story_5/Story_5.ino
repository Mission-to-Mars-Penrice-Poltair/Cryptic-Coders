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
}

void loop(){
  if (millis() >= 20000){
    roverStop(0);
    exit(0);
  }
  else {
    forward(2000,255);
    turnLeft(3000,80,255);
    forward(2000,255);
    turnRight(3000,255,80);
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
  digitalWrite(LEFTFORWARD, HIGH);
  digitalWrite(LEFTREVERSE, LOW); 
  delay(seconds);
}

void turnRight(int seconds, int speedLeft, int speedRight) {
  analogWrite(RIGHTENABLE, speedRight); //
  digitalWrite(RIGHTFORWARD, HIGH); 
  digitalWrite(RIGHTREVERSE, LOW);
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
