#include <Servo.h>
Servo servo_test;                  
int angle = 0;
int IRSensor = 2; // connect ir sensor to arduino pin 2
int LED = 13; // conect Led to arduino pin 13

void setup() 
{
  pinMode (IRSensor, INPUT); // sensor pin INPUT
  pinMode (LED, OUTPUT); // Led pin OUTPUT
  servo_test.attach(9);
}

void loop()
{
  int statusSensor = digitalRead (IRSensor);
  
  if (statusSensor == 0){
    digitalWrite(LED, LOW); // LED LOW
    for(angle = 90; angle > 0; angle--)    
  {                                  
    servo_test.write(angle);                 
    delay(10);                       
  } 
 delay(100);
    for(angle = 0; angle > 90; angle++)    
  {                                  
    servo_test.write(angle);                 
    delay(10);                       
  } 
  }
  else
  {
    digitalWrite(LED, HIGH); // LED High
  }
  
}
