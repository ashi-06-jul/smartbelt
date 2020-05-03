 // Includes the Servo library
#include <Servo.h>. 
// Defines Tirg pin for output and Echo pins for input of the Ultrasonic Sensor
const int trigPin = 10;
const int echoPin = 11;
// Variables for the duration and the distance
long duration;
int distance;
Servo myServo; // Creates a servo object for controlling the servo motor
Servo myServo2;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
  myServo.attach(12); // Defines on which pin is the servo motor attached
  myServo2.attach(9);
  }
void Print (int R , int T)
{
if(distance<=20){
   Serial.print(R);Serial.print(", ");
   Serial.print(T);Serial.println(".");
   myServo2.write(T); 
   delay(1000);}
}
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}
void loop() {
  // rotates the servo motor from 15 to 165 degrees
  for(int i=30;i<=160;i++){  
  myServo.write(i);
  delay(5);
  //distance = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
  Print(calculateDistance() , i);    
    delay(10);
  }
  /*Serial.print(i); // Sends the current degree into the Serial Port
  Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  Serial.print(distance); // Sends the distance value into the Serial Port
  Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing*/
  // Repeats the previous lines from 165 to 15 degrees
  for(int i=160;i>30;i--){  
  myServo.write(i);
  delay(5);
  Print(calculateDistance() , i);    
    delay(10);
  /*Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");*/
  }
}

// Function for calculating the distance measured by the Ultrasonic sensor
