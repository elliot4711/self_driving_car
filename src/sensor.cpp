#include <NewPing.h> //Function library for ultrasonic sensor, must be installed
#include <Arduino.h>
#include <Servo.h> //Servo motor library, standard but may need to be installed

//Ultrasonic sensor pins
const unsigned int TRIG_PIN = 13;
const unsigned int ECHO_PIN = 12;

//Communication baud rate
const unsigned int BAUD_RATE = 9600;

//L293D control pins
const int rightForward  = 5;  
const int rightBackward = 4;  
const int leftForward  = 3; 
const int leftBackward  = 2;  

//Maximum distance, over this the sensor does not need to measure exact and will return 0
int maximum_distance = 200;

//Bolean to check if car is moving forward
boolean goesForward = false;

//Distance variable for storing sensor distance measurment
int distance = 100;

NewPing sonar(TRIG_PIN, ECHO_PIN, maximum_distance); //sensor function using NewPing library

Servo myservo; //servo name

int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}

//Function to look right and return distance sensor value
int lookRight(){ 
  myservo.write(10);
  delay(500);
  int distance = readPing();
  delay(100);
  myservo.write(90);
  return distance;
}

//Function to look left and return distance sensor value
int lookLeft(){
  myservo.write(170);
  delay(500);
  int distance = readPing();
  delay(100);
  myservo.write(90);
  return distance;
  delay(100);
}

//Function to stop all motors
void moveStop(){
  digitalWrite(rightForward, LOW);
  digitalWrite(leftForward, LOW);
  digitalWrite(rightBackward, LOW);
  digitalWrite(leftBackward, LOW);
}

//Function to move forward
void moveForward(){
  if(!goesForward){
    goesForward = true;

    digitalWrite(leftForward, HIGH);
    digitalWrite(rightForward, HIGH);

    digitalWrite(leftBackward, LOW);
    digitalWrite(rightBackward, LOW);
  }
}

//Function to move backwards
void moveBackward(){
  goesForward = false;

  digitalWrite(leftBackward, HIGH);
  digitalWrite(rightBackward, HIGH);

  digitalWrite(leftForward, LOW);
  digitalWrite(rightForward, LOW);
}

//Function to turn right
void turnRight(){
  digitalWrite(leftForward, HIGH);
  digitalWrite(rightBackward, HIGH);

  digitalWrite(leftBackward, LOW);
  digitalWrite(rightForward, LOW);

  delay(500);

  digitalWrite(leftForward, HIGH);
  digitalWrite(rightForward, HIGH);

  digitalWrite(leftBackward, LOW);
  digitalWrite(rightBackward, LOW);
}

//Function to turn left
void turnLeft(){
  digitalWrite(leftBackward, HIGH);
  digitalWrite(rightForward, HIGH);
  
  digitalWrite(leftForward, LOW);
  digitalWrite(rightBackward, LOW);

  delay(500);

  digitalWrite(leftForward, HIGH);
  digitalWrite(rightForward, HIGH);

  digitalWrite(leftBackward, LOW);
  digitalWrite(rightBackward, LOW);
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
  
  myservo.write(90);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
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