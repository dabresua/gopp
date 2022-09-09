cmake_minimum_required(VERSION 3.0)
project(test_go)

set(TARGET example_go)

set(SRCS example.go)
set(LIB example.so)
set(FOLDER go)

message(STATUS "Entering ${CMAKE_CURRENT_BINARY_DIR}")

add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${LIB}
  DEPENDS ${SRCS}
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  COMMAND env GOPATH=${GOPATH} go build -buildmode=c-archive
  -o "${CMAKE_CURRENT_BINARY_DIR}/${LIB}"
  ${CMAKE_GO_FLAGS} ./...
  COMMENT "Building Go library")

add_custom_target(
  ${TARGET}
  DEPENDS ${LIB}
  ${HEADER}
)
add_library(
  example
  STATIC
  IMPORTED
  GLOBAL
)
add_dependencies(
  example
  ${TARGET}
)
set_target_properties(
  example
  PROPERTIES
  IMPORTED_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/${LIB}
  INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_BINARY_DIR}
)