cmake_minimum_required(VERSION 3.3)
project(Quicksort)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        Quicksort/DisplayHandler.cpp
        Quicksort/DisplayHandler.h
        Quicksort/main.cpp
        Quicksort/ProccessHandler.cpp
        Quicksort/ProccessHandler.h
        Quicksort/QuicksortClass.cpp
        Quicksort/QuicksortClass.h
        Quicksort/Settings.cpp
        Quicksort/Settings.h Quicksort/Display.cpp Quicksort/Display.h)


find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(SDL2 REQUIRED)


set(SDL2_LIBRARIES "-L${SDL2_LIBDIR}  -lSDL2")


include_directories(${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIRS} ${SDL2_INCLUDE_DIRS})

add_executable(Quicksort ${SOURCE_FILES})

target_link_libraries(Quicksort ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${SDL2_LIBRARIES})