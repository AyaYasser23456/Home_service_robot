#!/bin/sh
pip install rospkg
path_catkin_ws="/home/workspace/catkin_ws/"
export ROBOT_INITIAL_POSE="-x 1.5 -y -1.5 -Y 1.56"
xterm -e "cd ${path_catkin_ws}; source devel/setup.bash; roslaunch turtlebot_gazebo turtlebot_world.launch world_file:="/home/workspace/catkin_ws/src/map/world/UdacityOFFICE"" &
sleep 15
xterm -e "cd ${path_catkin_ws}; source devel/setup.bash; roslaunch turtlebot_gazebo amcl_demo.launch map_file:="/home/workspace/catkin_ws/src/map/maps/map1.yaml"" &
sleep 10
xterm -e "cd ${path_catkin_ws}; source devel/setup.bash; roslaunch turtlebot_rviz_launchers view_navigation1.launch rviz_config_file:="/home/workspace/catkin_ws/src/rvizConfig/navigation1.rviz"" &
sleep 15
xterm -e "cd ${path_catkin_ws}; source devel/setup.bash; roslaunch pick_objects pick_objects.launch" &

xterm -e "cd ${path_catkin_ws}; source devel/setup.bash; rosrun add_markers home_service_robot"


