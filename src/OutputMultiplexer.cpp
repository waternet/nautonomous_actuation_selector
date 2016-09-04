/*
 * OutputMultiplexer.cpp
 *
 *  Created on: Apr 16, 2016
 *      Author: zeeuwe01
 */

#include "../include/nautonomous_actuation_selector/OutputMultiplexer.hpp"

/**
 * General callback to process both autonomous and manual messages, using the message destination, see AutonomousOutput and ManualOutput
 */
void propulsionCallback(const geometry_msgs::Twist::ConstPtr& msg,
		MessagePriority priority) {

	if(!propulsion_message){
		propulsion_message = new TwistOutputMessage();
	}

	if (priority <= propulsion_message->priority) {
		std_msgs::String name;
		propulsion_message->twist.angular = msg->angular;
		propulsion_message->twist.linear = msg->linear;
		propulsion_message->priority = priority;
	} else {
		//ROS_LOG("incoming message of lower priority %d, ignoring it ...", priority);
	}
}

/**
 * General callback to process both autonomous and manual messages, using the message destination, see AutonomousOutput and ManualOutput
 */
void conveyorCallback(const geometry_msgs::Twist::ConstPtr& msg,
		MessagePriority priority) {
	if(!conveyor_message){
		conveyor_message = new TwistOutputMessage();
	}
	if (priority <= conveyor_message->priority) {
		conveyor_message->twist.angular = msg->angular;
		conveyor_message->twist.linear = msg->linear;
		conveyor_message->priority = priority;
	} else {
		//ROS_LOG("incoming message of lower priority, ignoring it ...");
	}
}

/**
 * General callback to process both autonomous and manual messages, using the message destination, see AutonomousOutput and ManualOutput
 */
void lightingCallback(const std_msgs::Bool::ConstPtr& msg,
		MessagePriority priority) {
	if(!lighting_message){
		lighting_message = new BoolOutputMessage();
	}
	if (priority <= lighting_message->priority) {
		lighting_message->state.data = msg->data;
		lighting_message->priority = priority;
	} else {
		//ROS_LOG("incoming message of lower priority, ignoring it ...");
	}
}

/**
* Check if the messages exist, if they exist send the appropriate message and delete them afterwards.
*/
void publishOutput() {
	std_msgs::String propulsion;

	if(propulsion_message){
		propulsion_publisher.publish(propulsion_message->twist);
		delete propulsion_message;
		propulsion_message = nullptr;
	}
	if(conveyor_message){
		conveyor_publisher.publish(conveyor_message->twist);
		delete conveyor_message;
		conveyor_message = nullptr;
	}
	if(lighting_message){
		lighting_publisher.publish(lighting_message->state);
		delete lighting_message;
		lighting_message = nullptr;
	}

}

int main(int argc, char **argv) {

	ros::init(argc, argv, "output_multiplexer");

	ros::NodeHandle n;

	//Create messages
	propulsion_message = nullptr;
	conveyor_message = nullptr;
	lighting_message = nullptr;

	//Subscribe to topics
	ros::Subscriber manualPropulsionSub = n.subscribe("manual_propulsion", 1000,
			manualPropulsionCallback);
	ros::Subscriber manualConveyorSub = n.subscribe("manual_conveyor", 1000,
			manualConveyorCallback);
	ros::Subscriber manualLightingSub = n.subscribe("manual_lighting", 1000,
			manualLightingCallback);

	ros::Subscriber autonomousPropulsionSub = n.subscribe(
			"autonomous_propulsion", 1000, autonomousPropulsionCallback);
	ros::Subscriber autonomousConveyorSub = n.subscribe("autonomous_conveyor",
			1000, autonomousConveyorCallback);
	ros::Subscriber autonomousLightingSub = n.subscribe("autonomous_lighting",
			1000, autonomousLightingCallback);
	
	//Publish topics
	propulsion_publisher = n.advertise<geometry_msgs::Twist>(
			"multiplexed_propulsion", 1000);
	conveyor_publisher = n.advertise<geometry_msgs::Twist>("multiplexed_conveyor",
			1000);
	lighting_publisher = n.advertise<std_msgs::Bool>("multiplexed_lighting",
			1000);

	ros::Rate rate(9); //TODO: dynamic configuration
	while (ros::ok()) {
	
		publishOutput();

		rate.sleep();
		ros::spinOnce();
	}

	ros::spin();

	return 0;
}

