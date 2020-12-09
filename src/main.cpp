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

//LED control pins
const int rightLed = 8;
const int leftLed = 10;

//Maximum distance, over this the sensor does not need to measure exact and will return 0
int maximum_distance = 200;

//Change this to change the distance from walls the car stops at
int stop_distance = 50;

//Bolean to check if car is moving forward
boolean goesForward = false;

//Distance variable for storing sensor distance measurment
int distance = 100;

NewPing sonar(TRIG_PIN, ECHO_PIN, maximum_distance); //sensor function using NewPing library

Servo myservo; //servo name

int readPing(){
  delay(15);
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
  for (int i = 0; i <= 2; i++) {
    digitalWrite(rightLed, HIGH);
    delay(500);
    digitalWrite(rightLed, LOW);
    delay(500);
  }
  digitalWrite(leftForward, HIGH);
  digitalWrite(rightBackward, HIGH);

  digitalWrite(leftBackward, LOW);
  digitalWrite(rightForward, LOW);

  delay(1000);

  digitalWrite(leftForward, HIGH);
  digitalWrite(rightForward, HIGH);

  digitalWrite(leftBackward, LOW);
  digitalWrite(rightBackward, LOW);
}

//Function to turn left
void turnLeft(){
  for (int i = 0; i <= 2; i++) {
    digitalWrite(leftLed, HIGH);
    delay(500);
    digitalWrite(leftLed, LOW);
    delay(500);
  }

  digitalWrite(leftBackward, HIGH);
  digitalWrite(rightForward, HIGH);
  
  digitalWrite(leftForward, LOW);
  digitalWrite(rightBackward, LOW);

  delay(1000);

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

  pinMode(leftLed, OUTPUT);
  pinMode(rightLed, OUTPUT);


  
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
  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if (distance <= stop_distance){
    moveStop();
    delay(300);

    moveBackward();
    delay(400);

    moveStop();
    delay(300);

    distanceRight = lookRight();
    delay(300);

    distanceLeft = lookLeft();
    delay(300);

    if (distanceRight >= distanceLeft){
      turnRight();
      moveStop();
    }
    else
    {
      turnLeft();
      moveStop();
    }
  }
  else
  {
    moveForward();
  }
  distance = 0;
  for (int i = 0; i <= 2; i++) {
    distance += readPing();
    delay(5);
  }
  distance = distance / 3;
  
}
