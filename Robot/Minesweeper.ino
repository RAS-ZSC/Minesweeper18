
float ldistance ;
float rdistance ;
float distance ;
float theta ;
float lastDistance=0 ;
float x ;
float y ;
#include <ros.h>
#include <ros/time.h>
#include <tf/tf.h>
#include <tf/transform_broadcaster.h>
#include <RotaryEncoder.h>
RotaryEncoder lencoder(0, 0.025), rencoder(1, 0.025);
=======
#define BLUETOOTH_CTRL  1
#define JOYSTICK_CTRL   1

#include <HBridge.h>
HBridge hbridge(6, 7, 4, 5, 10, 11);

/* Control Mehtods */
#if BLUETOOTH_CTRL
#include <SoftwareSerial.h>
SoftwareSerial bluetooth(50, 51);
#endif

#if JOYSTICK_CTRL
#include <JoyControl.h>
JoyControl joystick(hbridge);
#endif

/* Compass Connections
 * UNO: SDA -> A4, SCL -> A5
 * MEGA: SDA -> 20, SCL -> 21
 * LEO: SDA -> 2, SCL -> 3
 */
#include <Compass.h>
Compass compass;


ros::NodeHandle  nh;

geometry_msgs::TransformStamped t;
tf::TransformBroadcaster broadcaster;



char base_link[] = "/base_link";
char odom[] = "/odom";

void setup()
{
  nh.initNode();
  broadcaster.init(nh);
}

void loop()
{  
    ldistance = lencoder.getDistance();
   rdistance = rencoder.getDistance();
   distance = (ldistance + rdistance) / 2;

   theta = (compass.getDegree() * PI) / 180;

  x += (distance - lastDistance) * cos(theta);
  y += (distance - lastDistance) * sin(theta);

  lastDistance = distance;
  
    
  // tf odom->base_link
  t.header.frame_id = odom;
  t.child_frame_id = base_link;
  
  t.transform.translation.x = x;
  t.transform.translation.y = y;
  
  t.transform.rotation = tf::createQuaternionFromYaw(theta);
  t.header.stamp = nh.now();
  
  broadcaster.sendTransform(t);
  nh.spinOnce();
  
  delay(10);
=======
/* Constructor: RotaryEncoder(id, mps) ->  mps is Meters Per Second 
 * Connections: Interrupt Pins 
 */

//#include <RotaryEncoder.h>
//RotaryEncoder lencoder(0, 0.025), rencoder(1, 0.025);

//#include <MetalDetector.h>
//MetalDetector rdetector(10), ldetector(11);


//#include <Ultrasonic.h>
//Ultrasonic usonic(10, 9);

// Custom Libs
//#include <Mapper.h>
//#include <RF.h>

//Mapper mapper(encoder, compass, usonic);

//RF radio(49, 48);

void setup() {
  Serial.begin(9600);
  //bluetooth.begin(9600);
  //compass.begin();
  //compass.init();
  
  //radio.begin(1);
}


void loop() {
#if BLUETOOTH_CTRL
  if (bluetooth.available() > 0) {
    int code = bluetooth.read();

    switch (code) {
      case 0x53: hbridge.stop(); break;
      case 0x46: hbridge.forward(); break;
      case 0x42: hbridge.backward(); break;
      case 0x52: hbridge.right(); break;
      case 0x4C: hbridge.left(); break;
    }
  }
#endif

    /* Your code goes here */
}


/*
 * Arduino attaches 'serialEvent()' to 'loop()' function, so using delays
 * inside loop will delay this function
 */
void serialEvent()
{
#if JOYSTICK_CTRL
  byte code = Serial.read();
  joystick.handle(code);
#endif

}
