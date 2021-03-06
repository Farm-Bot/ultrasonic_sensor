/*
 ***PIN CONNECTION***
  HC-SR04 Module trigger  ----> 2
  HC-SR04 Module echo     ----> 3
*/

#include <ultrasonic_sensor.h>// include the library

ultrasonic_sensor u1(2,3); // the trigger pin is conected to pin 2 and echo is connected to pin 3


void setup(){
	u1.set();
	u1.ultrasonic_sensor_threshold = 10; // defalt threshold distance 6cm
  	u1.ultrasonic_sensor_buffer = 4 // default buffer distance 2 cm
}

void loop(){
	u1.ultrasonic_run();// returns u1.under_limit if it is under the range
                       // returns u1.at_limit if it is inside the range
                       // returns u1.over_limit if it is outside the range
                       // returns u1.invalid if there is a invalid return
}
