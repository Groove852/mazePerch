#include <iostream>
#include "ros/ros.h"
#include <string>
#include <sensor_msgs/LaserScan.h>
#include <sensor_msgs/Temperature.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Float32.h>
#include <lolkek/raspberry.h>


using namespace std;

ros::Publisher* publisher;
	
int tmp = 1;

void scan_callback(const sensor_msgs::LaserScan::ConstPtr& msg){
	string idk = "";
	for(int i = 0; i < tmp; i++){
		idk += to_string(msg -> ranges[i]) + ",";
	}
	tmp++;
	const char *cstr = idk.data();
	ROS_INFO("ranges is: [%s]\n", cstr); 
}
/*
void currentSpd_callback(const std_msgs::Float32::ConstPtr& msg){
	
}

void temperature_callback(const sensor_msgs::Temperature::ConstPtr& msg){
	
}

void line_callback(const std_msgs::Float32::ConstPtr& msg){
	
}
*/
int main(int argc, char **argv){

	ros::init(argc,argv,"keklol");
	ros::NodeHandle nh;
	lolkek::raspberry msgR; 
	ros::Publisher chatter_pub = nh.advertise<lolkek::raspberry>("RaspberryArray", 1000);
	ros::Rate loop_rate(10);

	msgR.command = 0;
	msgR.spd = 1;

	while(ros::ok()){
	
		chatter_pub.publish(msgR);
		ros::spinOnce();
	}

}
