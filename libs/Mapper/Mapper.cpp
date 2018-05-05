#include <Mapper.h>
#include <stdint.h>

Mapper::Mapper(RotaryEncoder& lenc, RotaryEncoder& renc, Compass& com, Ultrasonic& lus, Ultrasonic& rus, MetalDetector& lmd, MetalDetector& rmd):
  lencoder(lenc), rencoder(renc), compass(com), lusonic(lus), rusonic(rus), lmd(lmd), rmd(rmd) {
	  
  nh.initNode();
  nh.advertise(mine_lo);
  coordinates.data_length = 3;
  nh.advertise(mine_pl);
}

void Mapper::updateCoordinates() {
  float ldistance = lencoder.getDistance();
  float rdistance = rencoder.getDistance();
  float distance = (ldistance + rdistance) / 2;

  float angle = (compass.getDegree() * PI) / 180;

  y += (distance - lastDistance) * cos(angle);
  x += (distance - lastDistance) * sin(angle);

  lastDistance = distance;
}

void Mapper::map() {

  // if some intrrupt happend form the Ultrasonic 
  // then set type to be 's'
  if(m1){
	  type = 's'
	  publish();
  }
  // then set the type to be 'b'
  else if(m2){
	  type = 'b'
	  publish();
  }

}

void Mapper::publish()
{
  // Publish to ROS the new values of x and y
  // with the type of Mine 
  updateCoordinates();
  coordinates.data[1] = (uint16_t) x;
  coordinates.data[2] = (uint16_t) y;
  str_msg.data = type;
  mine_lo.publish(&str_msg);
  mine_pl.publish(&coordinates);

}
