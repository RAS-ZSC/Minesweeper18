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
}
