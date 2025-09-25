# TODO: compile executable that will be run
cmake_minimum_required(VERSION 3.5)
project(first_project)

# QUESTI NON SONO NECESSARIO SE AL TERGET AGGIUNGO LINK LIBRARIES
# find_package(deserializer REQUIRED) 
# find_package(property_container_manager REQUIRED)
# find_package(pose_message REQUIRED)

# include_directories(${deserializer_include_dirs} ${property_container_manager_include_dirs} ${pose_message_include_dirs})


add_executable(first_program
    many_object_in_stack_example.cpp
)
# TODO: link the executable against the core_library
target_link_libraries(core_library)

