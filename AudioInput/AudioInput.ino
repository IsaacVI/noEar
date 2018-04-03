int l = 4;
int r = 3;
int soundLeft;
int soundRight;
int mutationLevel;
int divitionLevel;
int led1 = 3;
int led2 = 5;
unsigned long lastTime;
float deltaTime;
int left;
int leftPower;
int right;
int rightPower;
int i =10;
float buttonsCoolDown;
float buttonDown;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(led2, OUTPUT);
  lastTime =millis();
}
 //
void loop() {
  deltaTime= millis()-lastTime;
  lastTime= millis();
  soundLeft = analogRead(l)-analogRead(A5);
  soundRight = analogRead(r)-analogRead(A5);
  
  if(soundLeft>i);
  analogWrite(5,map(soundLeft, 0, 1023, 0, 255));
  if(soundRight>i);
  analogWrite(3,map(soundRight, 0, 1023, 0, 255));

  if(buttonsCoolDown<=0 && buttonDown && digitalRead(7)==LOW && digitalRead(6)==LOW)
  {
    buttonDown=false;
  }

  if(buttonsCoolDown<=0 && !buttonDown && digitalRead(7)==HIGH)
  {
    buttonDown=true;
    buttonsCoolDown=50;
    i--;
    if(i<0)
     i=0;
  }

  if(buttonsCoolDown<=0 && !buttonDown && digitalRead(6)==HIGH)
  {
    buttonDown=true;
    buttonsCoolDown=50;
    i++;
    if(i>50)
     i=50;
  }

  if(buttonsCoolDown>0)
    buttonsCoolDown=buttonsCoolDown-deltaTime;
  
  if(soundLeft>i)
  {
    
    soundLeft=soundLeft*(1024/i);
    if(soundLeft>1023)
      soundLeft=1023;
    left=50;
    int temp= map(soundLeft, 0, 1023, 0, 255);
    if(leftPower<temp)
      leftPower =temp;
      
  }
  if(left>0)
    {
      digitalWrite(10,HIGH);
      analogWrite(10,leftPower);
      left-=deltaTime;
      }
      else
      {
        leftPower=0;
        //analogWrite(10,0);
        digitalWrite(10,LOW);
        }
  if(soundRight>i)
  {
    
    soundRight=soundRight*(1024/i);
    if(rightPower>1023)
      rightPower=1023;
    right=50;
    int temp= map(soundRight, 0, 1023, 0, 255);
    if(rightPower<temp)
      rightPower =temp;
      
  }
  if(right>0)
    {
      digitalWrite(11,HIGH);
      //analogWrite(9,rightPower);
      right-=deltaTime;
      }
      else
      {
        rightPower=0;
        //analogWrite(9,0);
        digitalWrite(9,LOW);
        }
  
  
   
  
}

