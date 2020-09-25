
#include <Arduino.h>
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

//This will run only one time.
void setup(){
  Serial.begin(9600);
 
  //Set pins as outputs
  pinMode(rightForward, OUTPUT);
  pinMode(rightBackward, OUTPUT);
  pinMode(leftForward, OUTPUT);
  pinMode(leftBackward, OUTPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
    
   
  
}

void loop()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  const unsigned long duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration / 29.1 / 2;
  if (duration == 0)
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

      delay(2000); 
    }
    else
    {
      Serial.println("Got to end motor");
      digitalWrite(rightForward, LOW);
      digitalWrite(rightBackward, LOW);
      digitalWrite(leftForward, LOW);
      digitalWrite(leftBackward, LOW);
      delay(2000);
    }
  Serial.print("distance to nearest object:");
  Serial.println(distance);
  Serial.println(" cm");
    
  }
  delay(100);
}