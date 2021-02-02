cmake_minimum_required(VERSION 3.8)
project(lua VERSION 1.0.0 LANGUAGES C)

option(BUILD_SHARED_LIBS "Build as shared library" ON)

set(srcDir src)

set(srcFiles lapi.c lauxlib.c lbaselib.c lcode.c lcorolib.c lctype.c ldblib.c ldebug.c ldo.c
    ldump.c lfunc.c lgc.c linit.c liolib.c llex.c lmathlib.c lmem.c loadlib.c lobject.c lopcodes.c
    loslib.c lparser.c lstate.c lstring.c lstrlib.c ltable.c ltablib.c ltm.c lundump.c
    lutf8lib.c lvm.c lzio.c)

list(TRANSFORM srcFiles PREPEND ${srcDir}/)

add_library(${PROJECT_NAME}
    ${srcFiles})

target_compile_definitions(${PROJECT_NAME}
    PRIVATE
    $<$<PLATFORM_ID:Linux>:LUA_USE_LINUX LUA_COMPAT_5_2>)

if(MSVC)
    if (NOT ${USE_MSVC_RUNTIME_LIBRARY_DLL})
        target_compile_options(${PROJECT_NAME}
            PRIVATE
            -Wall
            $<$<CONFIG:Debug>:-MTd>
            $<$<CONFIG:Release>:-O2;-MT>)
    endif()
else()
    target_compile_options(${PROJECT_NAME}
        PRIVATE
        -Wall
        $<$<CONFIG:Debug>:>
        $<$<CONFIG:Release>:-O2>)
endif()

target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/include/lua)
