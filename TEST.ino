//Zero degree should always look to the right
#include <Servo.h>
#define trig 6 //HC-SR04 trig pin
#define echo 5 //HC-SR04 echo pin
#define serv 2 //Servo(knob) pin
#define conf 0 //if conf=0 then servo it is on the right side of HS-SR04 else left side
#define dist 2 //distance between servo and ultrasonic
Servo myservo; //servo object
long duration; //ultrasonic duration
float pos=90; //servo position
float obj=0; //distance between ultrasonic and object
void setup() {
 myservo.attach(serv);
 pinMode(trig,OUTPUT);
 pinMode(echo,INPUT);
 Serial.begin(9600);

}

void loop() {
  //initialisation 
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  obj= duration*0.034/2;  // Calculate the distance:
  if(obj<=400) //400 its max distance for HC-SR04
  {
  Serial.print("Distance = "); // Print the distance on the Serial Monitor 
  Serial.print(obj);
  Serial.println(" cm");
  }
  else
  Serial.println("So far ");
  pos = (atan(obj/dist))*180/PI; //calculate the angle for servo
  Serial.println(pos);
  if(pos>=90)
  Serial.println("So far ");
  if(conf==0)
  myservo.write(180-pos);
  else
  myservo.write(pos);      
  delay (100);

    
}
