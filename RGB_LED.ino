 int rP = 7;
 int gP = 6;
 int bP = 5;
 
 void setup() {
  pinMode(rP, OUTPUT);
  pinMode(gP, OUTPUT);
  pinMode(bP, OUTPUT);

}

void loop() {
digitalWrite(rP, HIGH);
delay(100);
digitalWrite(rP, LOW);
digitalWrite(gP, HIGH);
digitalWrite(bP, LOW);
delay(100);
digitalWrite(rP, LOW);
digitalWrite(gP, LOW);
digitalWrite(bP, HIGH);
delay(100);
digitalWrite(rP, LOW);
digitalWrite(gP, LOW);
digitalWrite(bP, LOW);
delay(100);
}
