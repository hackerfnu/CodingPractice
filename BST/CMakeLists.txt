cmake_minimum_required(VERSION 2.8.3)
project(BST)

include_directories(
include
  ${catkin_INCLUDE_DIRS}
)

ADD_LIBRARY(mylib
  src/BST.cpp
)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
  mylib
)
