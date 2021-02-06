cmake_minimum_required(VERSION 3.8)

project(${PROJECT_CORE_NAME} VERSION ${PROJECT_VERSION} LANGUAGES C)

# Third party
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third-party)

# Project compilation
add_library(${PROJECT_NAME} STATIC
    src/graphics/shader/shader.c
    src/graphics/shader/shader_program.c
    src/graphics/camera.c
    src/graphics/graphical_context.c
    src/graphics/vertex_array.c
    src/graphics/voxel.c
    src/graphics/window.c
    src/math/frustum_culling.c
    src/math/matrix.c
    src/math/noise.c
    src/math/vector.c
    src/utils/containers/octree.c
    src/utils/containers/queue_static.c
    src/utils/file.c
    src/utils/string.c
    src/world/chunk.c
    src/world/world.c
    src/system.c
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    C_STANDARD 11
    C_STANDARD_REQUIRED YES
    C_EXTENSIONS NO
)

target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall
    $<$<CONFIG:Debug>:-MTd;-DDEBUG>
    $<$<CONFIG:Release>:-O2;-MT;-DNDEBUG>
)

target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/third-party/glad/include
    ${CMAKE_CURRENT_SOURCE_DIR}/third-party/glfw-3.3.1/include
    ${CMAKE_CURRENT_SOURCE_DIR}/third-party/lua-5.4.1/include
)

target_link_libraries(${PROJECT_NAME} 
    ${OPENGL_LIBRARY}
    glad
    glfw
    lua
)
