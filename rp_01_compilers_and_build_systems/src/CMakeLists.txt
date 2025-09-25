add_library(core_library SHARED #not static because there is SHARED
    utils/property_eigen.cpp
    utils/blob.cpp
    utils/id_context.cpp
    utils/serializer.cpp
    utils/property.cpp
    utils/property_identifiable.cpp
    utils/deserializer.cpp
    utils/property_container.cpp
    utils/property_container_manager.cpp
    utils/serializable.cpp
    utils/serialization_context.cpp
    utils/id_placeholder.cpp
    utils/identifiable.cpp
    utils/object_data.cpp
    messages/pose_message.cpp
    messages/base_sensor_message.cpp
    messages/odometry_message.cpp

)
    # TODO add other .cpp files:
    # added what I needed


# TODO: Include the current directory ( . ) to the list of directories to search for header files
# include_directories(.) #se facevo così non funzionava
target_include_directories(core_library PUBLIC .)

# target_link_libraries(core_library ${EIGEN3_LIBRARIES})
# TODO: Include the Eigen3 library to the list of libraries to link against
#but it has not any library, it is header only actually!
target_include_directories(core_library PUBLIC ${EIGEN3_INCLUDE_DIRS})
