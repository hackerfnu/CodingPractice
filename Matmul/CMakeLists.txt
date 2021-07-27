cmake_minimum_required(VERSION 2.8.3)
project(Matmul)

include_directories(
  include
)

ADD_LIBRARY(mylib
  src/matmul.cpp
)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME}
  mylib
)
