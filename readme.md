# Home Service Robot # 

In this project we created a gazebo environment for a robot and programming a **home service robot**,
which localize it's location and mapping it's environment then go to pre-determind pick-up and drop-off zones.

## packages explaining

### -add_markers:  
  Package contain **add_markers.cpp** node, **add_markers2.cpp** node both nodes publich cubic marker in pick-up and drop-off zones 
and **home_service_robot** node to publish the marker at the pick-up zone then subscribe the robot position, when the robot reachs to 
pick-up zone hide the marker, wait 5 sec to simulate a pickup and when the robot reachs to drop-off zone publish the marker at drop-off 
zone.
### -map: 
  Folder contains worlds and maps files.
### -pgm_map_creator: 
  To create map.yaml files
### -pick_objects:
  Package contains **pick_objects.cpp** node which publiches two goals, one at pick-up zone, when the robot reach to the frist goal 
the node publishes anther goal at drop-off zone.
### -rvizConfig:
  Contains screenshots for mapping and slaming tests and navigation1.rviz containing markers to show the markers in rviz. 
### -scripts:
  Contains shell scripts files
### -turtlebot:
  **turtlebot_teleop** package: With the keyboard_teleop.launch file, you can manually control a robot using keyboard commands.
### -slam_gmapping:
  **gmapping** package: With the gmapping_demo.launch file, you can easily perform SLAM and build a map of the environment with a robot equipped
with laser range finder sensors or RGB-D cameras.
### -turtlebot_simulator:
  **turtlebot_gazebo** package: With the turtlebot_world.launch you can deploy a turtlebot in a gazebo environment by linking the world file to
it.
### -turtlebot_interactions:
  **turtlebot_rviz_launchers** package: With the view_navigation.launch file, you can load a preconfigured rviz workspace. You’ll save a lot of 
timeby launching this file,because it will automatically load the robot model, trajectories, and map for you.
