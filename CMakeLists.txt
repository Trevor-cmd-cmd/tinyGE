cmake_minimum_required(VERSION 3.10)

project(MyEngine C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

file(GLOB_RECURSE ENGINE_OPENGL_SOURCES
    CONFIGURE_DEPENDS
    opengl/src/*.cpp
    opengl/src/*.c
)

add_library(engine_opengl STATIC
    ${ENGINE_OPENGL_SOURCES}
)
set_target_properties(engine_opengl PROPERTIES
    OUTPUT_NAME eng    
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/opengl/src/core
)

target_include_directories(engine_opengl PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/opengl/include
    ${CMAKE_CURRENT_SOURCE_DIR}/opengl/include/core
    ${CMAKE_CURRENT_SOURCE_DIR}/opengl/include/graphics
     ${CMAKE_CURRENT_SOURCE_DIR}/opengl/include/components
)

target_link_libraries(engine_opengl PUBLIC
    OpenGL::GL
    glfw
    dl
)

add_executable(MyEngine
    sandbox/snadboc.cpp
)

target_include_directories(MyEngine PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/opengl/include
)

target_link_libraries(MyEngine PRIVATE
    engine_opengl
)

set_target_properties(MyEngine PROPERTIES
    OUTPUT_NAME main
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/sandbox
)
