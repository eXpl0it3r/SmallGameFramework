cmake_minimum_required(VERSION 3.2)

set(PROJECT_NAME "SmallGameFramework")
project(${PROJECT_NAME})

# CMake options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")
set(CMAKE_VERBOSE_MAKEFILE OFF)
set(SFML_ROOT "" CACHE PATH "SFML top-level directory")
set(THOR_ROOT "" CACHE PATH "Thor top-level directory")

# Find SFML
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML REQUIRED COMPONENTS audio graphics window system)

if(NOT SFML_FOUND)
    message(FATAL_ERROR "SFML couldn't be located!")
endif()

include_directories(${SFML_INCLUDE_DIR})

# Find Thor
set(THOR_STATIC_LIBRARIES TRUE)
find_package(Thor REQUIRED)

if(NOT THOR_FOUND)
    message(FATAL_ERROR "Thor couldn't be located!")
endif()

include_directories(${THOR_INCLUDE_DIR})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# Compile target
set(SOURCE_FILES
    src/main.cpp
    src/Application.cpp
    src/State.cpp
    src/TestState.cpp
    src/Animation.cpp
    src/TestEntity.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Link libraries
target_link_libraries(${PROJECT_NAME} ${THOR_LIBRARY} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

# Install executable
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION .)

# Install game data
install(DIRECTORY bin
        DESTINATION .)
