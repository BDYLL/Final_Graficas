cmake_minimum_required(VERSION 3.7)
project(graficas_final)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Cubo.cpp
        Cubo.h
        RubikCube.cpp
        )
add_executable(graficas_final ${SOURCE_FILES})

find_package(OpenGL REQUIRED)

find_package(GLUT REQUIRED)

find_package(GLU REQUIRED)

find_package(GLEW REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${GLU_INCLUDE_DIRS})

target_link_libraries(graficas_final ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY} ${GLU_LIBRARY})

