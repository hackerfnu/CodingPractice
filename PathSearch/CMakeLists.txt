cmake_minimum_required(VERSION 2.8.3)
project(PathSearch)

set (CMAKE_CXX_STANDARD 11)

include_directories(
  include
)

ADD_LIBRARY(planner_lib
  src/planner.cpp
)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME}
  planner_lib
)
