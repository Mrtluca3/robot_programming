# src/ contains all the functionalities
 (file .cpp)

# include/ contains a directory with the NAME OF THE PACKAGE and in
 include/name_of_package/ there would be the header file of your functionalites: 
  in this case there is no "hello_world_name.h", since no declarations of classes/functions are done

# package.xml tells ROS (and colcon):
 -the name of the package
 -who is mantaining it (autore, licenza, descrizione)
 -other packages dependencies (test, compiling, execution)
 -current version used
 -additional tags (e.g. build type or URL of reference)



    
# NOTE: 
 ~/ros2_ws/src/ ros2 pkg create --build-type ament_cmake --node-name hello_world_node hello_world_pkg 
 It is needed to create the package with the name you choose:
es. 
 /ros2_ws/src$ ros2 pkg create --build-type ament_cmake pippo_pkg
   going to create a new package
   package name: pippo_pkg
   destination directory: /home/mrtlu/ros2_ws/src

 (multiplatform_ros2_builder) mrtlu@LAPTOP-VQONFVD8:~/ros2_ws/src$ ls
   Readme.md  cpp_pubsub  hello_world_pkg  pippo_pkg
 (multiplatform_ros2_builder) mrtlu@LAPTOP-VQONFVD8:~/ros2_ws/src$ cd pippo_pkg
 (multiplatform_ros2_builder) mrtlu@LAPTOP-VQONFVD8:~/ros2_ws/src/pippo_pkg$ ls
   CMakeLists.txt  include  package.xml  src

   NOTE: in src/ there is nothing, as in /include/pippo_pkg
