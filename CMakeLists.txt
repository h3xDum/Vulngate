cmake_minimum_required(VERSION 3.28.3)
project(Vulngate VERSION 0.1)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")


# Add the include directories
include_directories(
    ${PROJECT_SOURCE_DIR}/Engine/include
    ${PROJECT_SOURCE_DIR}/Dependencies/glad/include
    ${PROJECT_SOURCE_DIR}/Dependencies/stb_image
)
# Add subdirectories for external libraries that need to be built
add_subdirectory(Dependencies/glfw)
add_subdirectory(Dependencies/tinyobjloader)
add_subdirectory(Dependencies/glm)


# Collect all source files 
file(GLOB_RECURSE SOURCES
    ${PROJECT_SOURCE_DIR}/Engine/src/*.cpp  
)
list(APPEND SOURCES ${PROJECT_SOURCE_DIR}/Dependencies/glad/src/glad.c)
list(APPEND SOURCES ${PROJECT_SOURCE_DIR}/Dependencies/tinyobjloader/tiny_obj_loader.cc)
list(APPEND SOURCES ${PROJECT_SOURCE_DIR}/Dependencies/stb_image/stb_image.cpp)


# Create the executable
add_executable(GameEngine ${SOURCES})
# Link external libraries
target_link_libraries(GameEngine glfw)


# Configure the output 
set_target_properties(GameEngine PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)


