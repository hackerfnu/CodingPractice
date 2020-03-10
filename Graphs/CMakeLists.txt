cmake_minimum_required(VERSION 2.8.3)
project(Graphs)

include_directories(
include
  ${catkin_INCLUDE_DIRS}
  # ${PROJECT_NAME} include
)

ADD_LIBRARY(mylib
  src/graph.cpp
)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
  mylib
)
