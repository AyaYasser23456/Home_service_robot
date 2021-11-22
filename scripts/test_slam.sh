#!/bin/sh
#export TURTLEBOT_GAZEBO_WORLD_FILE=$(rospack find my_robot)/world/MyWorld.world
#export PYTHONPATH=$PYTHONPATH:/usr/lib/python2.7/dist-packages
pip install rospkg
path_catkin_ws="/home/workspace/catkin_ws/"
export ROBOT_INITIAL_POSE="-x 1.5 -y -1.5 -Y -1.6 "
xterm -e "cd ${path_catkin_ws}; source devel/setup.bash; roslaunch turtlebot_gazebo turtlebot_world.launch world_file:="/home/workspace/catkin_ws/src/map/world/UdacityOFFICE"" &
sleep 15
xterm -e "cd ${path_catkin_ws}; source devel/setup.bash; roslaunch turtlebot_gazebo gmapping_demo.launch" &
sleep 15
xterm -e "cd ${path_catkin_ws}; source devel/setup.bash; roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 15
xterm -e "cd ${path_catkin_ws}; source devel/setup.bash; roslaunch turtlebot_teleop keyboard_teleop.launch"

