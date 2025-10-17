cmake_minimum_required(VERSION 3.8)
project(battery_monitor)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

set(ament_dependencies
  rclcpp
  std_msgs
  sensor_msgs
  geometry_msgs
)

add_executable(battery_simulator src/battery_simulator.cpp)
ament_target_dependencies(battery_simulator ${ament_dependencies})
add_executable(battery_warning src/battery_warning.cpp)
ament_target_dependencies(battery_warning ${ament_dependencies})

install(DIRECTORY launch
  DESTINATION share/${battery_monitor})

install(TARGETS
  battery_simulator
  battery_warning
  DESTINATION lib/${battery_monitor})

ament_package()