cmake_minimum_required(VERSION 3.10)
project(cpp_pubsub)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED) #included
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
find_package(rclcpp REQUIRED) #lo aggiungo io serve (also in package.xml )
find_package(std_msgs REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()
 

if(NOT CMAKE_CXX_STANDARD)
   set(CMAKE_CXX_STANDARD 14)
endif()


add_executable(talker src/publisher_member_function.cpp)
ament_target_dependencies(talker rclcpp std_msgs) #to link to projects together: DEPENDENCIES MUST BE RESOLVED WITH AMENT
# != DA TARGET_LINK_LIBRARIES OR targt_include_directoris

install(TARGETS talker #which of creted targets  (libraries or executables) has to be moved in instal/package_name/lib/project_name
        DESTINATION lib/${PROJECT_NAME}) #OVVERO cpp_pubsub # poteva essere: DEstination share/${}
ament_package()
# Senza ament_package(), un altro pacchetto non potrebbe fare:
# find_package(my_package REQUIRED)