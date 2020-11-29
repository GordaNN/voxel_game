# Source code
set(PROJECT_SRC
    "src/graphics/shader/shader.c"
    "src/graphics/shader/shader_program.c"
    "src/graphics/camera.c"
    "src/graphics/graphical_context.c"
    "src/graphics/vertex_array.c"
    "src/graphics/voxel.c"
    "src/graphics/window.c"
    "src/math/frustum_culling.c"
    "src/math/matrix.c"
    "src/math/noise.c"
    "src/math/vector.c"
    "src/utils/containers/octree.c"
    "src/utils/containers/queue_static.c"
    "src/utils/file.c"
    "src/world/chunk.c"
    "src/world/world.c"
    "src/main.c"
)

# Shaders
set(PROJECT_SHADERS
    "shaders/voxel_vertex.glsl"
    "shaders/voxel_geometry.glsl"
    "shaders/voxel_fragment.glsl"
)

# Libraries
# OpenGL
find_package(OpenGL 4.5 REQUIRED)
if(NOT OPENGL_FOUND)
    message("Can't build ${PROJECT_NAME}")
    message("Failed to find OpenGl 4.5")
    return()
endif()

# glad
option(BUILD_GLAD_LIB_STATIC "Build glad static" ON)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third-party/glad)

# glfw
set(ENKITS_BUILD_EXAMPLES OFF CACHE BOOL "Build basic example applications")
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_INSTALL OFF CACHE BOOL "GLFW lib only")

option(BUILD_GLFW_LIB_STATIC "Build glfw static" ON)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/third-party/glfw-3.3.1")

# lua
option(BUILD_SHARED_LIBS "Build as shared library" OFF)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/third-party/lua-5.4.1")

# Project
add_executable(${PROJECT_NAME} ${PROJECT_SRC})

set_target_properties(${PROJECT_NAME} PROPERTIES
    C_STANDARD 11
    C_STANDARD_REQUIRED YES
    C_EXTENSIONS NO
)

target_compile_options(${PROJECT_NAME} PUBLIC
    -Wall
    "$<$<CONFIG:Debug>:-DDEBUG>"
    "$<$<CONFIG:Release>:-O3;-DNDEBUG>"
)

target_include_directories(${PROJECT_NAME} PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/third-party/glad/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/third-party/glfw-3.3.1/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/third-party/lua-5.4.1/include"
)

target_link_libraries(${PROJECT_NAME} 
    ${OPENGL_LIBRARY}
    glad
    glfw
    lua
)

# Copy files to build folder
foreach(FILE IN LISTS PROJECT_SHADERS PROJECT_SCRIPTS)
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/${FILE}"
        "${CMAKE_CURRENT_BINARY_DIR}/${FILE}"
        COPYONLY
    )
endforeach()
