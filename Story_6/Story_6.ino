const int LEFT_FEEDBACK = 3;
const int RIGHT_FEEDBACK = 2;

volatile int leftcounter = 0;
volatile int rightcounter = 0;

int const FWD_R = 7;
int const RIGHT_REV = 8;
int const RIGHT_ENABLE = 9;
int const LEFT_ENABLE = 10;
int const LEFT_FWD = 11;
int const LEFT_REV = 12;

void setup()
{
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK),LeftMotorISR,RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK),RightMotorISR,RISING);
  pinMode(FWD_R, OUTPUT);
  pinMode(RIGHT_REV, OUTPUT);
  pinMode(RIGHT_ENABLE, OUTPUT);
  pinMode(LEFT_ENABLE, OUTPUT);
  pinMode(LEFT_FWD, OUTPUT);
  pinMode(LEFT_REV, OUTPUT);
}

void loop()
{
  Serial.print("left counter");
  Serial.println(leftcounter);
  Serial.print("right counter");
  Serial.println(rightcounter);
  
  
  //forwards(5000);
  
  //rover_stop(1000);

  //reverse(2000);
  
  //rover_stop(2000);
}

void forwards(int delaytime){
  digitalWrite(RIGHT_ENABLE,HIGH);
  digitalWrite(LEFT_ENABLE,HIGH);
  digitalWrite(FWD_R,HIGH);
  digitalWrite(LEFT_FWD,HIGH);
  delay(delaytime);
}

void rover_stop(int delaytime){
  digitalWrite(RIGHT_ENABLE,LOW);
  digitalWrite(LEFT_ENABLE,LOW)
  digitalWrite(FWD_R,LOW);
  digitalWrite(LEFT_FWD,LOW);
  digitalWrite(LEFT_REV,LOW);
  digitalWrite(RIGHT_REV,LOW);
  delay(delaytime);
}

 void reverse(int delaytime){
 digitalWrite(RIGHT_ENABLE,HIGH);
 digitalWrite(LEFT_ENABLE,HIGH);
 digitalWrite(LEFT_REV,HIGH);
 digitalWrite(RIGHT_REV,HIGH);
 delay(delaytime);
}

void LeftMotorISR(){
  leftcounter++;
}

void RightMotorISR(){
  rightcounter++;
}
