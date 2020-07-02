#ifndef ultrasonic_sensor_h
#define ultrasonic_sensor_h

#include "Arduino.h"


class ultrasonic_sensor
{
  public:
     ultrasonic_sensor(int trigger,int echo);
     set();
     ultrasonic_run();

     int ultrasonic_sensor_threshold = 6;
     int ultrasonic_sensor_buffer = 2;
     int under_limit = -1, at_limit = 0, over_limit = 1,invalid = 111;



  private:
     int tr,ech;
     long cm = 0;

};

#endif
