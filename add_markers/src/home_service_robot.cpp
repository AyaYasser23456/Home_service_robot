#include <ros/ros.h>
#include<math.h>
#include <visualization_msgs/Marker.h>
#include<nav_msgs/Odometry.h>
#include<geometry_msgs/PoseWithCovarianceStamped.h>

bool pick_up =false;
bool drop_off =false;

void robot_pose_callback(const nav_msgs::Odometry::ConstPtr& r_pose){
	double robot_x= r_pose->pose.pose.position.x;
	double robot_y= r_pose->pose.pose.position.y;
	
	ROS_INFO("Robot position x:%1.2f, y:%1.2f",robot_x,robot_y);
	if(abs(robot_x - 4.2)<= 0.00002 && abs(robot_y + 4.5)<= 0.00002){
		pick_up=true;
		ROS_INFO("I reacehd to pick up zone :)");	
	}
	
	else if(abs(robot_x + 5.0)<= 0.00002 && abs(robot_y + 3.1) <= 0.00002){
		drop_off= true;
		ROS_INFO("I reacehd to drop off zone :)");
	}

}


int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
  ros::Subscriber odom_sub = n.subscribe("odom",10,robot_pose_callback);

  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE; 
 
  visualization_msgs::Marker marker1;

    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker1.header.frame_id = "map";
    marker1.header.stamp = ros::Time::now();

    
    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker1.ns = "basic_shapes";
    marker1.id = 0;


    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker1.type = shape;
 
    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker1.action = visualization_msgs::Marker::ADD;

    // Set the pick up pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker1.pose.position.x = 4.2;
    marker1.pose.position.y = -4.5;
    marker1.pose.position.z = 0;
    marker1.pose.orientation.x = 0.0;
    marker1.pose.orientation.y = 0.0;
    marker1.pose.orientation.z = 0.0;
    marker1.pose.orientation.w = 1.0;


    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker1.scale.x = 0.3;
    marker1.scale.y = 0.3;
    marker1.scale.z = 0.3;

    // Set the color -- be sure to set alpha to something non-zero!
    marker1.color.r = 0.0f;
    marker1.color.g = 0.0f;
    marker1.color.b = 1.0f;
    marker1.color.a = 1.0;


    marker1.lifetime = ros::Duration();

    while(ros::ok()){

	    while (marker_pub.getNumSubscribers() < 1)
	    {
	      if (!ros::ok())
	      {
		return 0;
	      }
	      ROS_WARN_ONCE("Please create a subscriber to the marker");
	      sleep(1);
	    }
	   
	    if(pick_up== false){
		    marker_pub.publish(marker1);
	            ros::Duration(2).sleep();
	    }
	    else if(drop_off == false){
		    marker1.action = visualization_msgs::Marker::DELETE;
		    marker_pub.publish(marker1);
		    ros::Duration(5).sleep();
	    }
	    else if(pick_up ==true && drop_off == true){
		    //set drop off zone position
		    marker1.pose.position.x = -5.0;
		    marker1.pose.position.y = -3.1;
		    marker1.pose.position.z = 0;
		    marker1.pose.orientation.x = 0.0;
		    marker1.pose.orientation.y = 0.0;
		    marker1.pose.orientation.z = -1.0;
		    marker1.pose.orientation.w = 1.0;

		    marker1.action = visualization_msgs::Marker::ADD;
		   
		    marker_pub.publish(marker1);
		    break;
	    }
     ros::spinOnce();
     }

}
