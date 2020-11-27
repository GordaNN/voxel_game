cmake_minimum_required(VERSION 3.8)

project(glad)

set(GLAD_LIB_SRC src/glad.c)

if(${BUILD_GLAD_LIB_STATIC})
    add_library(${PROJECT_NAME} STATIC ${GLAD_LIB_SRC})
else()
    add_library(${PROJECT_NAME} SHARED ${GLAD_LIB_SRC})
endif()

target_include_directories(${PROJECT_NAME} PRIVATE include/)
