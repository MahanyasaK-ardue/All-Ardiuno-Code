#include <Servo.h>
Servo servo_test;                  
int angle = 0;
int led = 13;
int pin = 2;
int value = 0;
int pirState = LOW;    
void setup() 
{ 
  servo_test.attach(9); 
  pinMode(led, OUTPUT);
  pinMode(pin, INPUT);
  Serial.begin(9600);     
} 
 void loop() 
{ 
  for(angle = 0; angle < 90; angle++)    
  {                                  
    servo_test.write(angle);                 
    delay(15);                       
  } 
 delay(1000);
  for(angle = 90; angle>=1; angle--)      
  {                                
    servo_test.write(angle);              
    delay(5);                       
  } 
  delay(1);
   value = digitalRead(pin);

  if (value == HIGH) {
    digitalWrite(led, HIGH);

    if (pirState == LOW) {
      Serial.println("Motion Detected!");
      pirState = HIGH;
    }
  }else{
    digitalWrite(led, LOW);

    if(pirState == HIGH){
      Serial.println("Motion Ended!");
      pirState = LOW;
      }
    }
}
