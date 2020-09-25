
// #include <Arduino.h>
// const unsigned int TRIG_PIN = 13;
// const unsigned int ECHO_PIN = 12;
// const unsigned int BAUD_RATE = 9600;
// //L293D
// //Motor A
// const int rightForward  = 4;  // Pin 14 of L293
// const int rightBackward = 5;  // Pin 10 of L293
// //Motor B
// const int leftForward  = 3; // Pin  7 of L293
// const int leftBackward  = 2;  // Pin  2 of L293


// //This will run only one time.
// void setup(){
//     Serial.begin(9600);
 
//     //Set pins as outputs
//     pinMode(rightForward, OUTPUT);
//     pinMode(rightBackward, OUTPUT);
//     pinMode(leftForward, OUTPUT);
//     pinMode(leftBackward, OUTPUT);

//     pinMode(TRIG_PIN, OUTPUT);
//     pinMode(ECHO_PIN, INPUT);

//     Serial.println("Got to motor Bc");
//     digitalWrite(rightForward, LOW);
//     digitalWrite(rightBackward, LOW);
//     digitalWrite(leftForward, HIGH);
//     digitalWrite(leftBackward, LOW);
//     delay(2000); 
   
  
// }


// void loop(){
//   //Motor Control - Motor A: rightForward,leftForward & Motor B: leftForward,leftBackward

//   //This code  will turn Motor A clockwise for 2 sec.
//   Serial.println("Got to motor Ac");
//   digitalWrite(rightForward, HIGH);
//   digitalWrite(rightBackward, LOW);
//   digitalWrite(leftForward, LOW);
//   digitalWrite(leftBackward, LOW);
//   delay(2000); 
//   //This code will turn Motor A counter-clockwise for 2 sec.
//   Serial.println("Got to motor Acc");
//   digitalWrite(rightForward, LOW);
//   digitalWrite(rightBackward, HIGH);
//   digitalWrite(leftForward, LOW);
//   digitalWrite(leftBackward, LOW);
//   delay(2000);
  
//   //This code will turn Motor B clockwise for 2 sec.
//   Serial.println("Got to motor Bc");
//   digitalWrite(rightForward, LOW);
//   digitalWrite(rightBackward, LOW);
//   digitalWrite(leftForward, HIGH);
//   digitalWrite(leftBackward, LOW);
//   delay(2000); 
//   //This code will turn Motor B counter-clockwise for 2 sec.
//   Serial.println("Got to motor Bcc");
//   digitalWrite(rightForward, LOW);
//   digitalWrite(rightBackward, LOW);
//   digitalWrite(leftForward, LOW);
//   digitalWrite(leftBackward, HIGH);
//   delay(2000);    
    
//   //And this code will stop motors
//   Serial.println("Got to motor stop");
//   digitalWrite(rightForward, LOW);
//   digitalWrite(rightBackward, LOW);
//   digitalWrite(leftForward, LOW);
//   digitalWrite(leftBackward, LOW);
//   delay(2000);  
//}