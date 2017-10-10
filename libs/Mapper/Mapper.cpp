#include <Mapper.h>

Mapper::Mapper(RotaryEncoder& enc, Compass& com, Ultrasonic& us):
  encoder(enc), compass(com), usonic(us) {
	  
  nh.initNode();
  nh.advertise(mine_lo);
  coor.data_length =3;
  nh.advertise(mine_pl);

}

void Mapper::updateCoordinates() {
  float distance = encoder.getDistance();
  float angle = (compass.getDegree() * PI) / 180;

  y = y + (distance - lastDistance) * cos(angle);
  x = x + (distance - lastDistance) * sin(angle);

  lastDistance = distance;
}

void Mapper::map(bool m1, bool m2) {

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
  coordinates.data[1]= x;
  coordinates.data[2]= y;
  str_msg.data = type;
  mine_lo.publish(&str_msg);
  mine_pl.publish(&coordinates);

 }


