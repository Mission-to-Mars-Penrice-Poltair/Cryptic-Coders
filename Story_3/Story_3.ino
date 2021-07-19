const int RIGHTFORWARD = 7;
const int RIGHTREVERSE = 8;
const int RIGHTENABLE = 9;
const int LEFTFORWARD = 11;
const int LEFTREVERSE = 12;
const int LEFTENABLE = 10;

void setup()
{
  pinMode(RIGHTFORWARD, OUTPUT);
  pinMode(RIGHTREVERSE, OUTPUT);
  pinMode(RIGHTENABLE, OUTPUT);
  pinMode(LEFTFORWARD, OUTPUT);
  pinMode(LEFTREVERSE, OUTPUT);
  pinMode(LEFTENABLE, OUTPUT);
}

void loop()
{
  forward(5);
  Stop(1);
  digitalWrite(RIGHTENABLE, HIGH);
  digitalWrite(RIGHTFORWARD, LOW);
  digitalWrite(RIGHTREVERSE, HIGH);
  digitalWrite(LEFTENABLE, HIGH);
  digitalWrite(LEFTFORWARD, LOW);
  digitalWrite(LEFTREVERSE, HIGH);  
  delay(2000); // Wait for 2000 millisecond(s)
}

void forward(int seconds)
{
  digitalWrite(RIGHTENABLE, HIGH);
  digitalWrite(RIGHTFORWARD, HIGH); 
  digitalWrite(RIGHTREVERSE, LOW);
  digitalWrite(LEFTENABLE, HIGH);
  digitalWrite(LEFTFORWARD, HIGH);
  digitalWrite(LEFTREVERSE, LOW); 
  delay(seconds * 1000);
}

void Stop(int seconds)
{
  digitalWrite(RIGHTENABLE, LOW);
  digitalWrite(RIGHTFORWARD, LOW);
  digitalWrite(RIGHTREVERSE, LOW);
  digitalWrite(LEFTENABLE, LOW);
  digitalWrite(LEFTFORWARD, LOW);
  digitalWrite(LEFTREVERSE, LOW); 
  delay(seconds * 1000);
}
void reverse(int seconds)
{
  digitalWrite(RIGHTENABLE, HIGH);
  digitalWrite(RIGHTFORWARD, LOW);
  digitalWrite(RIGHTREVERSE, HIGH);
  digitalWrite(LEFTENABLE, HIGH);
  digitalWrite(LEFTFORWARD, LOW);
  digitalWrite(LEFTREVERSE, HIGH); 
  delay(seconds * 1000);
}
