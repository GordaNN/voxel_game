cmake_minimum_required(VERSION 3.8)

project(project)

# Project version
set(PROJECT_VERSION 0.0.1)

# Project parts name
set(PROJECT_CORE_NAME core)
set(PROJECT_GAME_NAME game)
set(PROJECT_CORE_INCULE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/core/include)

# Project parts compilation
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/core)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/game)

# Installation
install(TARGETS ${PROJECT_GAME_NAME} DESTINATION ${PROJECT_NAME})
install(DIRECTORY core/shaders DESTINATION ${PROJECT_NAME}) 
