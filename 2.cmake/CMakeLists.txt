cmake_minimum_required(VERSION 3.0)
project(main)

add_subdirectory(go)

message(STATUS "Entering ${CMAKE_CURRENT_BINARY_DIR}")

set(TARGET main)

include_directories(
  go
)

set(project_common_include_dirs
  "${CMAKE_CURRENT_SOURCE_DIR}/go"
)

set(
  project_source_files
  main.cpp
)

add_executable(
  "${PROJECT_NAME}"
  ${project_source_files}
  ${project_common_include_dirs}
)
target_link_libraries(${TARGET} example pthread)