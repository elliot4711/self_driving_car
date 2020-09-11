
// #include <Arduino.h>
// const unsigned int TRIG_PIN = 13;
// const unsigned int ECHO_PIN = 12;
// const unsigned int BAUD_RATE = 9600;
// //L293D
// //Motor A
// const int motorPin1  = 5;  // Pin 14 of L293
// const int motorPin2  = 6;  // Pin 10 of L293
// //Motor B
// const int motorPin3  = 10; // Pin  7 of L293
// const int motorPin4  = 9;  // Pin  2 of L293

// void setup()
// {
//   pinMode(TRIG_PIN, OUTPUT);
//   pinMode(ECHO_PIN, INPUT);
  
//   pinMode(motorPin1, OUTPUT);
//   pinMode(motorPin2, OUTPUT);
//   pinMode(motorPin3, OUTPUT);
//   pinMode(motorPin4, OUTPUT);
//   Serial.begin(BAUD_RATE);
// }

// void loop()
// {
//   digitalWrite(TRIG_PIN, LOW);
//   delayMicroseconds(2);
//   digitalWrite(TRIG_PIN, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(TRIG_PIN, LOW);

//   const unsigned long duration = pulseIn(ECHO_PIN, HIGH);
//   int distance = duration / 29.1 / 2;
//   if (duration == 0)
//   {
//     Serial.println("Warning: no pulse from sensor");
//   }
//   else
//   {
//     if (distance >= 50)
//     {
//       Serial.println("Got to start motor");
//       digitalWrite(motorPin1, HIGH);
//       digitalWrite(motorPin2, LOW);
      
//       digitalWrite(motorPin3, LOW);
//       digitalWrite(motorPin4, LOW);

//       delay(2000); 
//     }
//     else
//     {
//       Serial.println("Got to end motor");
//       digitalWrite(motorPin1, LOW);
//       digitalWrite(motorPin2, LOW);
//       digitalWrite(motorPin3, LOW);
//       digitalWrite(motorPin4, LOW);
//       delay(2000);
//     }
//   Serial.print("distance to nearest object:");
//   Serial.println(distance);
//   Serial.println(" cm");
    
//   }
//   delay(100);
// }