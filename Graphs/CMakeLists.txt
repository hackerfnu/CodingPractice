cmake_minimum_required(VERSION 2.8.3)
project(Graphs)

include_directories(include)
add_library(mylib
  ${CMAKE_SOURCE_DIR}/src/graph.cpp
)

add_executable(graph_bin src/main.cpp)

target_link_libraries(graph_bin
  mylib
)