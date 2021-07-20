const int RIGHTFORWARD = 7; //Yellow
const int RIGHTREVERSE = 8; //Red
const int RIGHTENABLE = 9; //Blue
const int LEFTFORWARD = 11; //Yellow
const int LEFTREVERSE = 12; //Red
const int LEFTENABLE = 10; //Blue

const int LEFT_FEEDBACK = 2; // Pin numbers on Rover
const int RIGHT_FEEDBACK = 3;
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
   
  if (leftcounter >= 870){
    Serial.println("Counter has reached 870"); // 2 metres finished (435 revolutiosn per metre)
    roverStop(0);
  }
  else {
    forward(0);
    //Just print out the values to show counter operating
    Serial.print("Left Counter ");
    Serial.println(leftcounter); //This is printing then a new Line after
  Serial.print("Right Counter ");
    Serial.println(rightcounter);
  }
}

void forward(int seconds) {
  digitalWrite(RIGHTENABLE, HIGH);
  digitalWrite(RIGHTFORWARD, HIGH); 
  digitalWrite(RIGHTREVERSE, LOW);
  digitalWrite(LEFTENABLE,HIGH);
  digitalWrite(LEFTFORWARD, HIGH);
  digitalWrite(LEFTREVERSE, LOW); 
  delay(seconds);
}  
  
void backward(int seconds){
  digitalWrite(RIGHTENABLE, HIGH);
  digitalWrite(RIGHTFORWARD, LOW);
  digitalWrite(RIGHTREVERSE, HIGH);
  digitalWrite(LEFTENABLE, HIGH);
  digitalWrite(LEFTFORWARD, LOW);
  digitalWrite(LEFTREVERSE, HIGH); 
  delay(seconds);
}
  
  
void roverStop(int seconds)
{
  digitalWrite(RIGHTENABLE, LOW);
  digitalWrite(RIGHTFORWARD, LOW);
  digitalWrite(RIGHTREVERSE, LOW);
  digitalWrite(LEFTENABLE, LOW);
  digitalWrite(LEFTFORWARD, LOW);
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
