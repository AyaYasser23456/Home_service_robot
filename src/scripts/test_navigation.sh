#!/bin/sh
pip install rospkg
path_catkin_ws="/home/workspace/catkin_ws/"
xterm -e "cd ${path_catkin_ws}; source devel/setup.bash; roslaunch turtlebot_gazebo turtlebot_world.launch world_file:="/home/workspace/catkin_ws/src/map/world/MyWorld.world"" &
sleep 10
xterm -e "cd ${path_catkin_ws}; source devel/setup.bash; roslaunch turtlebot_gazebo amcl_demo.launch map_file:="/home/workspace/catkin_ws/src/map/maps/map.yaml"" &
sleep 10
xterm -e "cd ${path_catkin_ws}; source devel/setup.bash; roslaunch turtlebot_rviz_launchers view_navigation.launch" 
#rviz_config_file:="/home/workspace/catkin_ws/src/rvizConfig/full_map.rviz"
