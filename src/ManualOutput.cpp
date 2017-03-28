/*
 * ManualInput.cpp
 *
 *  Created on: Apr 16, 2016
 *      Author: zeeuwe01
 */

#include "../include/nautonomous_actuation_selector/OutputMultiplexer.hpp"

/**
 *\brief Callback for the topic on manual propulsion, adds priority MSG_PRIO_HIGH, calls propulsionCallback()
 *\param geometry_msgs::Twist msg
 */
void manualPropulsionCallback(const geometry_msgs::Twist::ConstPtr& msg)
{
	ROS_INFO("Manual Propulsion received : linear [%f, %f, %f] and angular [%f, %f, %f]", msg->linear.x, msg->linear.y, msg->linear.z, msg->angular.x, msg->angular.y, msg->angular.z);
	propulsionCallback(msg, MessagePriority::MSG_PRIO_HIGH);
}

/**
 *\brief Callback for the topic on manual conveyor, adds priority MSG_PRIO_HIGH, calls conveyorCallback()
 *\param geometry_msgs::Twist msg
 */
void manualConveyorCallback(const geometry_msgs::Twist::ConstPtr& msg)
{
	//ROS_INFO("Manual Conveyor received : linear [%f, %f, %f] and angular [%f, %f, %f]", msg->linear.x, msg->linear.y, msg->linear.z, msg->angular.x, msg->angular.y, msg->angular.z);
	conveyorCallback(msg, MessagePriority::MSG_PRIO_HIGH);
}

/**
 *\brief Callback for the topic on manual lighting, adds priority MSG_PRIO_HIGH, calls lightingCallback()
 *\param std_msgs::Bool msg
 */
void manualLightingCallback(const std_msgs::Bool::ConstPtr& msg)
{
	//ROS_INFO("Manual Lighting received: [%d]", msg->data);
	lightingCallback(msg, MessagePriority::MSG_PRIO_HIGH);
}

