ARTSS PROGRAMS!!!	The bellow contains a collection of programs (in order): //Finalize presentation 3.0, //Metal Detector, //reedswitch ,//Main Servo, //Trapdoor, //Ultrasonic sensor, //reedswitch+mainservo combination)

//Finalize presentation 3.0
#include <Servo.h>
Servo main_wheel;
Servo plastic_sorter;
#include "NewPing.h"//library of ultrasonic sensor
#define TRIGGER_PIN 5 // ultrasonic sensor 
#define ECHO_PIN 6 //ultrasonic sensor
#define MAX_DISTANCE 400 // ultrasonic sensor
NewPing ultrasonic_sensor(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
double ultrasonic_sensor_distance;
int metal_detector = 8; //metal detector
int metal_detector_value;
int plastic_sorter_pos;//trash system servo motor
int reedswitch = 4;
int main_wheel_pin = 9;
int plastic_sorter_pin = 10;
boolean a = false;
boolean onHold = false;
void setup() {
  Serial.begin(9600);
  Serial.print("program activated");
  Serial.print('\n');
  pinMode(metal_detector, INPUT);
  pinMode(reedswitch, INPUT); //reedswitch
  delay(20);
}

void loop() {
  plastic_sorter.attach(plastic_sorter_pin);
  do {
    if (plastic_sorter_pos < 100)
    { plastic_sorter_pos += 1;
      plastic_sorter.write(plastic_sorter_pos);
      delay(20);
    }
    if (plastic_sorter_pos = 100)
    { plastic_sorter.detach();
      delay(500);
      a = true;
    }
  } while ( a == false);
  ultrasonic_sensor_distance = ultrasonic_sensor.ping_cm();
  if ( ultrasonic_sensor_distance != 0 && ultrasonic_sensor_distance <= 15)
  {
    Serial.print("ultrasonic sensor :");
    Serial.println(ultrasonic_sensor_distance);
    digitalWrite(metal_detector, HIGH);
    metal_detector_value = 0;
    delay(1000);
    main_wheel.attach(9); //start rotating until
    main_wheel.write(100);
    Serial.println("main wheel spinning");
    do {
      if (digitalRead(metal_detector) == 1)
      { digitalWrite(metal_detector, LOW);
        metal_detector_value = 1;
      }
      if (digitalRead(reedswitch) == 1)
      {
        main_wheel.detach(); //it takes time to completely stop
        Serial.print("main wheel deteched");
        Serial.print('\n');
        Serial.print("value of metal detector= ");
        Serial.println(metal_detector_value);
        Serial.print('\n');
        delay(1000);
        onHold = true;
      }
    } while ( onHold == false);
    if (metal_detector_value == 0)
    { plastic_sorter.attach(plastic_sorter_pin);
      for (plastic_sorter_pos = 100; plastic_sorter_pos >= 0; plastic_sorter_pos -= 1)
      {
        plastic_sorter.write(plastic_sorter_pos);
        delay(20);
      }
      Serial.print("finish one loop");
    }
      a = false;
      onHold = false;
  }
}
 
//Metal Detector
int metaldetector = 8;

void setup() {
  Serial.begin(9600);

  pinMode(metaldetector, INPUT);
}


void loop() {
  int detectorState = digitalRead(metaldetector);
  Serial.println(detectorState);
  delay(10);
  //detectorState = 0;
  //Serial.println(detectorState);
}
 
//reedswitch
int a= 4;

void setup() {
  Serial.begin(9600);

  pinMode(a, INPUT);
}


void loop() {
  int detectorState = digitalRead(a);
  Serial.println(detectorState);
  delay(10);
  //detectorState = 0;
  //Serial.println(detectorState);
    
}
 
//Main Servo
#include <Servo.h> 
String readString; //String captured from serial port
Servo myservo;  // create servo object to control a servo 
String n;
int a;

void setup() {
  Serial.begin(9600);
  myservo.writeMicroseconds(1500); //set initial servo position if desired
  myservo.attach(9, 500, 2500);  //the pin for the servo control, and range if desired
  Serial.println("servo all-in-one test code 12-25-13"); // so I can keep track of what is loaded
  Serial.println();
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read();  //gets one byte from serial buffer
    n += c; //makes the string readString
    delay(2);  //slow looping to allow buffer to fill with next character
  }

  if (n >0) {
    Serial.println(n);  //so you can see the captured string 

      // attach or detach servo if desired
    if (n == "d") { 
      while (digitalRead(9)) {} //delay loop until pin 7 is low
      myservo.detach(); //detach servo
      Serial.println("servo detached");
      goto bailout; //jump over writing to servo
    }
    if (n == "a") {
      myservo.attach(9); //reattach servo to pin 7
      Serial.println("servo attached");
      goto bailout;
    }    

    a = n.toInt();  //convert readString into a number
    if( 1<=a<=180 )
    {Serial.print("writing Angle: ");
      Serial.println(a);
      myservo.write(a);}
 /*if(n >= 500)
    {
      Serial.print("writing Microseconds: ");
      Serial.println(n);
      myservo.writeMicroseconds(n);
    }
    else
    {   
      Serial.print("writing Angle: ");
      Serial.println(n);
      myservo.write(n); 
    } */
    

bailout: //reenter code loop
    Serial.print("Last servo command position: ");    
    Serial.println(myservo.read());
    Serial.println();
    readString=""; //empty for next input
  }
}
 
//Trapdoor
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
              // a maximum of eight servo objects can be created
int pos = 0;    // variable to store the servo position
void setup() {
 myservo.attach(10);  // attaches the servo on pin 9 to the servo object
}
void loop() {
 for(pos = 0; pos < 80; pos += 1) 
 {                                  // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(20);                       // waits 15ms for the servo to reach the position
 }
}
 for(pos = 100; pos>=0; pos-=1)     // goes from 180 degrees to 0 degrees
 {
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(20);                       // waits 15ms for the servo to reach the position
 }
 delay(500);
}
 
//Ultrasonic sensor
// This uses Serial Monitor to display Range Finder distance readings

// Include NewPing Library
#include "NewPing.h"

// Hook up HC-SR04 with Trig to Arduino Pin 9, Echo to Arduino pin 10
#define TRIGGER_PIN 5
#define ECHO_PIN 6

// Maximum distance we want to ping for (in centimeters).
#define MAX_DISTANCE 400

// NewPing setup of pins and maximum distance.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
double duration, distance;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // Send ping, get distance in cm
  distance = sonar.ping_cm();

  Serial.print("Distance = ");

  if ( distance != 0 && distance <= 21)
  {
    Serial.print("                ");
    Serial.println(distance);
  }
  else
  { Serial.println("error");
  }
 
//reedswitch+mainservo combination
int a= 4;
unsigned long currentMillis;
unsigned long previousMillis = 0;
#include <Servo.h>
Servo ms;
void setup() {
  Serial.begin(9600);

  pinMode(a, INPUT);
}


void loop() {
  int detectorState = digitalRead(a);
  Serial.println(detectorState);
  ms.attach(9);
  ms.write(86);
unsigned long currentMillis = millis();
  if ((unsigned long)(currentMillis - previousMillis) >= 2300 )
  {
    ms.detach();
    Serial.println(detectorState);
    delay(2000);
    previousMillis = currentMillis;
  }
  
  //detectorState = 0;
  //Serial.println(detectorState);
    
}
