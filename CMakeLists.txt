#PROJECT NAME
project(me-versus-it)
cmake_minimum_required(VERSION 2.8)
SET(CMAKE_CXX_FLAGS "-std=c++11")

#EXTERNAL PACKAGES (SDL2)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
find_package(SDL2 REQUIRED)

#INCLUDES & SRC FILES
include_directories(${SDL2_INCLUDE_DIR} ${PROJECT_SOURCE_DIR}/me-versus-it)
file(GLOB SRCS me-versus-it/*.cpp)
file(GLOB HDRS me-versus-it/*.h)

#LINKING AND EXECUTABLE
add_executable(${PROJECT_NAME} ${SRCS} ${HDRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARY})
