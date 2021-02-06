cmake_minimum_required(VERSION 3.8)

project(${PROJECT_GAME_NAME} VERSION ${PROJECT_VERSION} LANGUAGES C)

# Project compilation
add_executable(${PROJECT_NAME} 
    src/application/application.c
    src/application/binder.c
    src/ui/main.c
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
    ${PROJECT_CORE_INCULE_DIR}
)

target_link_libraries(${PROJECT_NAME} ${PROJECT_CORE_NAME})
