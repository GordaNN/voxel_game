cmake_minimum_required(VERSION 3.8)

project(${PROJECT_GAME_NAME} VERSION ${PROJECT_VERSION} LANGUAGES C)

# Source code
set(PROJECT_CORE_SRC
    src/main.c
)

# Project compilation
add_executable(${PROJECT_NAME} ${PROJECT_CORE_SRC})

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

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_CORE_INCULE_DIR})

target_link_libraries(${PROJECT_NAME} ${PROJECT_CORE_NAME})
