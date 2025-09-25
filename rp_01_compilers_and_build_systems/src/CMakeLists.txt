add_library(core_library SHARED #not static because there is SHARED
    utils/property_eigen.cpp
    utils/blob.cpp
    utils/deserializer.cpp
    
    utils/property_container_manager.cpp
    messages/pose_message.h
    utils/id_context.cpp
    utils/serializer.cpp
)
    # TODO add other .cpp files:
    # added what I needed


# TODO: Include the current directory ( . ) to the list of directories to search for header files
include_directories(.) #qua non metto core_library 

# target_link_libraries(core_library ${EIGEN3_LIBRARIES})
# TODO: Include the Eigen3 library to the list of libraries to link against
#but it has not any library, it is header only actually!
target_include_directories(core_library PUBLIC ${EIGEN3_INCLUDE_DIRS})
