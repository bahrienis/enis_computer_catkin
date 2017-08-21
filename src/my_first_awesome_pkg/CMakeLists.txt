cmake_minimum_required(VERSION 2.8.3)
project(my_first_awesome_pkg)

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
  roscpp
  sensor_msgs
  std_msgs
)

find_package(OpenCV REQUIRED)

catkin_package()

include_directories(
  ${OPENCV_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
)

add_executable(talker_node src/talker_node.cpp)
target_link_libraries(talker_node
   ${OpenCV_LIBRARIES}
   ${catkin_LIBRARIES}
   )
   
add_executable(listener_node src/listener_node_v0.0.4.cpp)
target_link_libraries(listener_node
   ${OpenCV_LIBRARIES}
   ${catkin_LIBRARIES}
   )
   
   
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX14)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()
