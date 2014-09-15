#include "ros/ros.h"
#include "geometry_msgs/Wrench.h"

#include <sstream>

/**
 * This file  demonstrates simple sending of messages of youbot wrench msgs  over the ROS system.
 */
int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "youbot_wrench");
  ros::NodeHandle n;


  ros::Publisher chatter_pub = n.advertise<geometry_msgs::Wrench>("cmd_wrench", 1000);

  ros::Rate loop_rate(10);

  while (ros::ok())
  {
  
    geometry_msgs::Wrench wrench;



   // ROS_INFO("%s", msg.data.c_str());

  
    chatter_pub.publish(wrench);

    ros::spinOnce();

    loop_rate.sleep();

  }


  return 0;
}

