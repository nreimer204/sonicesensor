#include <Servo.h>
Servo servo1;
int trigPin = 4;
int echoPin = 5;
long distance;
long duration;
 
void setup() 
{
servo1.attach(9); 
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);// put your setup code here, to run once:
}
 
void loop() {
  ultra();
  servo1.write(10);
  if(distance <= 20){
  servo1.write(180);
  delay(800);
    servo1.write(30);
  delay(800);
      servo1.write(180);
  delay(800);
        servo1.write(30);
  }
}
 
void ultra(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  }
