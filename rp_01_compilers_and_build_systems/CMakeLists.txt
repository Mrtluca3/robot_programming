cmake_minimum_required(VERSION 3.5-d)
project(mini_core)

set(CMAKE_CXX_STANDARD 11) #define variable
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")

# TODO invokes the routines to find a package called Eigen3
find_package(Eigen3 REQUIRED) #REQUIRED so it stops if not found

#LA SOLUZIONE NON LO METTE!: include_directories(${Eigen3_INCLUDE_DIRS}) 

# add project source code
add_subdirectory(src)

# TODO do the same for executables
add_subdirectory(executables)


