/*
 * AutonomousInput.cpp
 *
 *  Created on: Apr 16, 2016
 *      Author: zeeuwe01
 */

#include "../include/nautonomous_actuation_selector/AutonomousOutput.hpp"

//callback for the topic on autonomous propulsion
void autonomousPropulsionCallback(const geometry_msgs::Twist::ConstPtr& msg) {
	//ROS_INFO("Autonomous propulsion received : linear [%f, %f, %f] and angular [%f, %f, %f]",msg->linear.x, msg->linear.y, msg->linear.z, msg->angular.x,msg->angular.y, msg->angular.z);
	propulsionCallback(msg, MessagePriority::MSG_PRIO_MEDIUM);
}

//callback for the topic on autonomous conveyor belt
void autonomousConveyorCallback(const geometry_msgs::Twist::ConstPtr& msg) {
	//ROS_INFO("Autonomous Conveyor received : linear [%f, %f, %f] and angular [%f, %f, %f]",msg->linear.x, msg->linear.y, msg->linear.z, msg->angular.x,msg->angular.y, msg->angular.z);
	conveyorCallback(msg, MessagePriority::MSG_PRIO_MEDIUM);
}

//callback for the topic on lighting  
void autonomousLightingCallback(const std_msgs::Bool::ConstPtr& msg) {
	//ROS_INFO("Autonomous Lighting received: [%d]", msg->data);
	lightingCallback(msg, MessagePriority::MSG_PRIO_MEDIUM);
}
