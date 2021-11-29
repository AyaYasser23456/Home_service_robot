#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  // Initialize the simple_navigation_goals node
  ros::init(argc, argv, "pick_objects");

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }
  bool pickup=false;
  move_base_msgs::MoveBaseGoal goal_1;
  move_base_msgs::MoveBaseGoal goal_2;
  // set up the frame parameters
  goal_1.target_pose.header.frame_id = "map";
  goal_1.target_pose.header.stamp = ros::Time::now();

  // Define a position and orientation for the robot to reach
  goal_1.target_pose.pose.position.x = 4.2; 
  goal_1.target_pose.pose.position.y = -4.5; 
  goal_1.target_pose.pose.orientation.w = -0.5;
   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending goal_1");
  ac.sendGoal(goal_1);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ROS_INFO("Hooray, the robot reached to pick up zone ");
    pickup=true;
  }
  else
    ROS_INFO("The base failed to reach to pick up zone for some reason");
  
  ros::Duration(5.0).sleep();

  if(pickup){
  goal_2.target_pose.header.frame_id = "map";
  goal_2.target_pose.header.stamp = ros::Time::now();

  // Define a position and orientation for the robot to reach
  goal_2.target_pose.pose.position.x = -5.0; 
  goal_2.target_pose.pose.position.y = -3.1; 
  goal_2.target_pose.pose.orientation.z = -1.0;
  goal_2.target_pose.pose.orientation.w = -0.5;

   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending goal_2");
  ac.sendGoal(goal_2);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Hooray, the robot reached to drop off zone ");
  else
    ROS_INFO("The base failed to reach to drop off zone for some reason");

  }

  ros::Duration(5.0).sleep();

  return 0;
}

