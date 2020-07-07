#ifndef ultrasonic_sensor_h
#define ultrasonic_sensor_h

#include "Arduino.h"


class ultrasonic_sensor
{
  public:
     ultrasonic_sensor(int trigger,int echo);
     ultrasonic_led(s0,s1,s2,pin);
     set();
     set(bool led);
     ultrasonic_run();
     ultrasonic_run(bool led);

     int
      ultrasonic_sensor_threshold = 6;
     int ultrasonic_sensor_buffer = 2;
     int under_limit = -1, at_limit = 0, over_limit = 1,invalid = 111;
     bool led = true;



  private:
     int tr,ech;
     long cm = 0;
     int selectPins[3];
     int c_pin = 0;

};

#endif
