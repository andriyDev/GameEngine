cmake_minimum_required (VERSION 3.10)
project(GameEngine)

set (GameEngine_VERSION_MAJOR 1)
set (GameEngine_VERSION_MINOR 0)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR})
include_directories(${GLEW_INCLUDE_DIRS})

file(GLOB GameEngine_SRC src/*.cpp)

message(STATUS ${GameEngine_SRC})

add_executable(GameEngine ${GameEngine_SRC})

target_link_libraries(GameEngine glfw)
target_link_libraries(GameEngine ${OPENGL_gl_LIBRARY})
target_link_libraries(GameEngine ${GLEW_LIBRARIES})

