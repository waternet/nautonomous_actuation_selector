/*
 * ManualInput.cpp
 *
 *  Created on: Apr 16, 2016
 *      Author: zeeuwe01
 */

#include "../include/nautonomous_actuation_selector/OutputMultiplexer.hpp"

/**
 * Callback for the manual propulsion topic
 */
void manualPropulsionCallback(const geometry_msgs::Twist::ConstPtr& msg)
{
	//ROS_INFO("Manual Propulsion received : linear [%f, %f, %f] and angular [%f, %f, %f]", msg->linear.x, msg->linear.y, msg->linear.z, msg->angular.x, msg->angular.y, msg->angular.z);
	propulsionCallback(msg, MessagePriority::MSG_PRIO_HIGH);
}

/**
 * Callback for the manual conveyor belt topic
 */
void manualConveyorCallback(const geometry_msgs::Twist::ConstPtr& msg)
{
	//ROS_INFO("Manual Conveyor received : linear [%f, %f, %f] and angular [%f, %f, %f]", msg->linear.x, msg->linear.y, msg->linear.z, msg->angular.x, msg->angular.y, msg->angular.z);
	conveyorCallback(msg, MessagePriority::MSG_PRIO_HIGH);
}

/**
 * Callback for the manual lighting topic
 */
void manualLightingCallback(const std_msgs::Bool::ConstPtr& msg)
{
	//ROS_INFO("Manual Lighting received: [%d]", msg->data);
	lightingCallback(msg, MessagePriority::MSG_PRIO_HIGH);
}

