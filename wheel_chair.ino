int rly_1 = 8;// left 1
int rly_2 = 9;// left 2
int rly_3 = 10;// right 1
int rly_4 = 11;// right 2
String voice;
void setup() 
{
  Serial.begin(9600);
  pinMode(rly_1, OUTPUT);
  pinMode(rly_2, OUTPUT);
  pinMode(rly_3, OUTPUT);
  pinMode(rly_4, OUTPUT);
}
 void loop() 
{  
 while(Serial.available()>0)
  {
    delay(10);
    char c=Serial.read();
    Serial.println(voice);
    if(c=='#')
   {
      break;
    }
    voice+=c;
    }
   if(voice=="forward")
   {
    Forward();
    delay(2000);  
 //delay(200);  
     Stop();  
   }
    if(voice=="backward")
    {
    Backward();
    delay(2000);
  //delay(200); 
    Stop(); 
    }
  if(voice=="left")
   {
    Left();
    delay(400);
    Stop();
   }
  if(voice=="right")
  {
    Right();
    delay(400);
    Stop();  
  }

   if(voice=="stop")
  {
    Brake();
    delay(100);
    Stop();
    delay(200);
     
  }
   
     if(voice.length()>0)
 {
      Serial.println(voice);
      voice="";

 }
}

void Forward()
{
    digitalWrite(rly_1, LOW);
    digitalWrite(rly_2, HIGH);
    digitalWrite(rly_3, LOW);
    digitalWrite(rly_4, HIGH); 
}

void Backward()
{
    digitalWrite(rly_1, HIGH);
    digitalWrite(rly_2, LOW);
    digitalWrite(rly_3, HIGH);
    digitalWrite(rly_4, LOW);
}

void Right()
{
    digitalWrite(rly_1, HIGH);
    digitalWrite(rly_2, LOW);
    digitalWrite(rly_3, LOW);
    digitalWrite(rly_4, HIGH);
}

void Left()
{
    digitalWrite(rly_1, LOW);
    digitalWrite(rly_2, HIGH);
    digitalWrite(rly_3, HIGH);
    digitalWrite(rly_4, LOW);
}

void Stop()
{
    digitalWrite(rly_1, LOW);
    digitalWrite(rly_2, LOW);
    digitalWrite(rly_3, LOW);
    digitalWrite(rly_4, LOW);  
}

void Brake()
{
  Forward();
  delay(1);
  Backward();
  delay(1);
    Forward();
  delay(1);
  Backward();
  delay(1);
  Stop();
  delay(100);  
}
