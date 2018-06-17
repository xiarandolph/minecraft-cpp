cmake_minimum_required(VERSION 3.1)

#Enable debug symbols by default
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose build type (Debug or Release)" FORCE)
endif()
# command line: -D CMAKE_BUILD_TYPE=RELEASE

project(minecraft-cpp)

find_package(OpenGL REQUIRED)

#SFML files
add_subdirectory(extlibs/SFML)
add_subdirectory(extlibs/glew-cmake)

include_directories(
  extlibs/SFML/include
  extlibs/glew-cmake/include
  extlibs/glew-camke/src
  extlibs/glm
  .
)

include_directories("include")

set(FOLLOW_CPP
  ./src/main.cpp
  ./src/Display.cpp)

set(FOLLOW_HPP
  ./include/Display.h)

source_group("Header Files" FILES $(FOLLOW_HPP))
source_group("Source Files" FILES $(FOLLOW_CPP))

add_executable(minecraft-cpp ${FOLLOW_CPP})

target_link_libraries(minecraft-cpp
  sfml-graphics sfml-window sfml-system
  libglew_static
)
