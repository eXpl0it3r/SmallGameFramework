cmake_minimum_required(VERSION 3.15)

project(SmallGameFramework LANGUAGES CXX)

# SmallGameFramework uses C++17 features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# CMake options
set(SMALLGAMEFRAMEWORK_STATIC_STD_LIBS FALSE CACHE BOOL "Use statically linked standard/runtime libraries? This option must match the one used for SFML.")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

if(NOT BUILD_SHARED_LIBS)
    set(SFML_STATIC_LIBRARIES TRUE)
endif()

# Find SFML
find_package(SFML 2.5 COMPONENTS audio graphics REQUIRED)

if(NOT SFML_FOUND)
    message(FATAL_ERROR "SFML couldn't be located!")
endif()

# Find Thor
find_package(Thor REQUIRED)

if(NOT THOR_FOUND)
    message(FATAL_ERROR "Thor couldn't be located!")
endif()

include_directories(${THOR_INCLUDE_DIR})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/External)

# Compile target
set(SOURCE_FILES
    "src/main.cpp"
    "src/Core/Application.hpp"
    "src/Core/Application.cpp"
    "src/State/Base/State.hpp"
    "src/State/Base/State.cpp"
    "src/State/PlayState.hpp"
    "src/State/PlayState.cpp"
    "src/State/MenuState.hpp"
    "src/State/MenuState.cpp"
    "src/Entity/Base/Animation.hpp"
    "src/Entity/Base/Animation.cpp"
    "src/Entity/Base/Entity.hpp"
    "src/Entity/Explosion.hpp"
    "src/Entity/Explosion.cpp"
    "src/Entity/Button.hpp"
    "src/Entity/Button.cpp"
    "src/Core/Resources.hpp")
add_executable(SmallGameFramework ${SOURCE_FILES})

# Static Runtime
if(SMALLGAMEFRAMEWORK_STATIC_STD_LIBS)
	if(NOT SFML_STATIC_LIBRARIES)
		message("\n-> If you check SMALLGAMEFRAMEWORK_STATIC_STD_LIBS, you also need to check SFML_STATIC_LIBRARIES.")
		message("-> It would lead to multiple runtime environments which results in undefined behavior.\n")
    elseif(WIN32 AND MSVC AND ${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.15.0")
	    set_property(TARGET SmallGameFramework PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
    endif()
endif()

# Link libraries
target_link_libraries(SmallGameFramework ${THOR_LIBRARY} sfml-audio sfml-graphics)

# Install executable
install(TARGETS SmallGameFramework
        RUNTIME DESTINATION .)

# Install game data
install(DIRECTORY bin/
        DESTINATION .)