cmake_minimum_required(VERSION 3.0)

project(MyProject)

include_directories(../)

set(SOURCE_FILES 
    example_1.cpp
    example_2.cpp
    example_3.cpp
    example_4.cpp)

foreach(SOURCE_FILE ${SOURCE_FILES})
  get_filename_component(PROJECT_NAME ${SOURCE_FILE} NAME_WE)
  add_executable(${PROJECT_NAME} ${SOURCE_FILE})
  target_link_libraries(${PROJECT_NAME} dl)
endforeach(SOURCE_FILE)
