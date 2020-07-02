#include "Arduino.h"
#include "ultrasonic_sensor.h"


ultrasonic_sensor::ultrasonic_sensor(int trigger,int echo){
	tr = trigger;
	ech = echo;

}

ultrasonic_sensor::set(){
	pinMode(tr,OUTPUT);
	pinMode(ech,OUTPUT);
}


ultrasonic_sensor::ultrasonic_run(){
	// sensor 1 values

     digitalWrite(tr, LOW);
     delayMicroseconds(2);
     digitalWrite(tr, HIGH);
     delayMicroseconds(10);
     digitalWrite(tr, LOW);
	cm = ((pulseIn(ech, HIGH)) / 29 / 2);


	if(ultrasonic_sensor_threshold - ultrasonic_sensor_buffer < cm < ultrasonic_sensor_threshold + ultrasonic_sensor_buffer)
		return at_limit;
	else if(ultrasonic_sensor_threshold - ultrasonic_sensor_buffer > cm  )
	 	return under_limit;
	else if( cm > ultrasonic_sensor_threshold + ultrasonic_sensor_buffer)
		return over_limit;
	else
		return invalid;
}

///*** Source code ***///

//
// ////////////////////*******************///////////
//
//
// // ---------------------------------------------------------------- //
// // Arduino Ultrasoninc Sensor HC-SR04
// // Re-writed by Arbi Abdul Jabbaar
// // Using Arduino IDE 1.8.7
// // Using HC-SR04 Module
// // Tested on 17 September 2019
// // ---------------------------------------------------------------- //
//
// #define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
// #define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04
//
// // defines variables
// long duration; // variable for the duration of sound wave travel
// int distance; // variable for the distance measurement
//
// void setup() {
//   pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
//   pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
//   Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
//   Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
//   Serial.println("with Arduino UNO R3");
// }
// void loop() {
//   // Clears the trigPin condition
//   digitalWrite(trigPin, LOW);
//   delayMicroseconds(2);
//   // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
//   digitalWrite(trigPin, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(trigPin, LOW);
//   // Reads the echoPin, returns the sound wave travel time in microseconds
//   duration = pulseIn(echoPin, HIGH);
//   // Calculating the distance
//   distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
//   // Displays the distance on the Serial Monitor
//   Serial.print("Distance: ");
//   Serial.print(distance);
//   Serial.println(" cm");
// }