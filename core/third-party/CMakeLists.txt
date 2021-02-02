cmake_minimum_required(VERSION 3.8)

# OpenGL
find_package(OpenGL 4.5 REQUIRED)
if(NOT OPENGL_FOUND)
    message("Failed to find OpenGl 4.5")
    return()
endif()

# glad
option(BUILD_GLAD_LIB_STATIC "Build glad static" ON)
option(USE_MSVC_RUNTIME_LIBRARY_DLL "Don't use glad runtime dll" OFF)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/glad)

# glfw
set(ENKITS_BUILD_EXAMPLES OFF CACHE BOOL "Build basic example applications")
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_INSTALL OFF CACHE BOOL "GLFW lib only")
set(USE_MSVC_RUNTIME_LIBRARY_DLL OFF CACHE BOOL "Don't use GLFW runtime dll")
option(BUILD_GLFW_LIB_STATIC "Build glfw static" ON)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3.1)

# lua
option(BUILD_SHARED_LIBS "Build as shared library" OFF)
option(USE_MSVC_RUNTIME_LIBRARY_DLL "Don't use glad runtime dll" OFF)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lua-5.4.1)
