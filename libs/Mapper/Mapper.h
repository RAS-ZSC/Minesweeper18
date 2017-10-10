#ifndef _MAPPER_H
#define _MAPPER_H

#include <ros.h>
#include <std_msgs/Char.h>
#include <std_msgs/UInt16MultiArray.h>

#include <RotaryEncoder.h>
#include <Compass.h>
#include <Ultrasonic.h>

ros::NodeHandle nh;

std_msgs::Char str_msg;
std_msgs::UInt16MultiArray coordinates;

ros::Publisher mine_lo("Mine_located", &str_msg);
ros::Publisher mine_pl("Mine_place", &coordinates);

class Mapper {
private:
  char type = 'n';
  int x = 0, y = 0;
  float lastDistance = 0;

  RotaryEncoder &encoder;
  Compass &compass;
  Ultrasonic &usonic;

public:
  Mapper(RotaryEncoder&, Compass&, Ultrasonic&);
  void updateCoordinates();
  void map(bool, bool);
  void publisher();
};

#endif
