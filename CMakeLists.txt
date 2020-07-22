cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME "SmallGameFramework")
project(${PROJECT_NAME})

# SmallGameEngine uses C++17 features
set(CMAKE_CXX_STANDARD 17)

# CMake options
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")
set(CMAKE_VERBOSE_MAKEFILE OFF)
set(THOR_ROOT "" CACHE PATH "Thor top-level directory")

# Find SFML
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5 COMPONENTS audio graphics REQUIRED)

if(NOT SFML_FOUND)
    message(FATAL_ERROR "SFML couldn't be located!")
endif()

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

# Static Runtime
if(WIN32 AND MSVC AND ${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.15.0")
	set_property(TARGET ${PROJECT_NAME} PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
endif()

# Link libraries
target_link_libraries(${PROJECT_NAME} ${THOR_LIBRARY} sfml-audio sfml-graphics)

# Install executable
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION .)

# Install game data
install(DIRECTORY bin/
        DESTINATION .)
