#include <NewPing.h>
#include <Arduino.h>
#include <Servo.h>
const unsigned int TRIG_PIN = 13;
const unsigned int ECHO_PIN = 12;
const unsigned int BAUD_RATE = 9600;
//L293D
//Motor A
const int rightForward  = 5;  // Pin 14 of L293
const int rightBackward = 4;  // Pin 10 of L293
//Motor B
const int leftForward  = 3; // Pin  7 of L293
const int leftBackward  = 2;  // Pin  2 of L293
int maximum_distance = 200;
int distance = 100;
NewPing sonar(TRIG_PIN, ECHO_PIN, maximum_distance);
Servo myservo;

int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}


//This will run only one time.
void setup(){
  Serial.begin(9600);
  myservo.attach(11);
 
  //Set pins as outputs
  pinMode(rightForward, OUTPUT);
  pinMode(rightBackward, OUTPUT);
  pinMode(leftForward, OUTPUT);
  pinMode(leftBackward, OUTPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  myservo.write(90);
  delay(4000);
   
  
}

void loop()
{
  distance = readPing();
  if (distance == 0)
  {
    Serial.println("Warning: no pulse from sensor");
  }
  else
  {
    if (distance >= 50)
    {
      Serial.println("Got to start motor");
      digitalWrite(rightForward, HIGH);
      digitalWrite(leftForward, HIGH);
      
      digitalWrite(rightBackward, LOW);
      digitalWrite(leftBackward, LOW);

      delay(100); 
    }
    else
    {
      Serial.println("Got to end motor");
      digitalWrite(rightForward, LOW);
      digitalWrite(rightBackward, LOW);
      digitalWrite(leftForward, LOW);
      digitalWrite(leftBackward, LOW);
      delay(500);
      myservo.write(20);
      delay(1000);
      myservo.write(160);
      delay(1000);
      myservo.write(90);
      delay(100);
    }
    Serial.print("distance to nearest object:");
    Serial.println(distance);
    Serial.println(" cm");
    
  }
  delay(100);
}