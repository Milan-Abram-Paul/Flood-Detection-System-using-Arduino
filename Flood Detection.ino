int redPin= 11;
int greenPin = 9;
int  bluePin = 10;
int trigPin=12;
int echoPin=13;
const int buzzer = 2;
long duration,cm,inches;
void setup()
{

Serial.begin(9600);
  pinMode(redPin,  OUTPUT);              
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
 
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);  
    pinMode(buzzer, OUTPUT);
}
void loop() 
{
 digitalWrite(trigPin,LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin,HIGH);
 delayMicroseconds(4);
 digitalWrite(trigPin,LOW);
 pinMode(echoPin,INPUT);
 duration=pulseIn(echoPin,HIGH);
 cm=(duration/2)/29.1;//MEASUREMENT IN CM
 inches=(duration/2)/74;//MEASUREMENT IN INCHES
 delay(250);
 Serial.print(cm);
 Serial.print("cm");
   if(cm<100)
    
  {
    
  setColor(255,  0, 0); // red
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(1000);         // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);         // ...for 1sec
 
  }
 
  
  else if (cm<225)
  {
   setColor(255,  255, 0); // yellow Color

 
  }
  
 else  if(cm<380)
   { 
     
   
   setColor(0,  255, 0); // Green Color
   }
 delay(1000);
}

void setColor(int redValue, int greenValue,  int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin,  greenValue);
  analogWrite(bluePin, blueValue);
}
