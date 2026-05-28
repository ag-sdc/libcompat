cmake_minimum_required(VERSION 3.10)
project(libcompat C)

add_compile_definitions(ANDROID)

add_library(compat SHARED compat.c)
set_target_properties(compat PROPERTIES VERSION 1.0 SOVERSION 1)
target_include_directories(compat PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(compat_static STATIC compat.c)
set_target_properties(compat_static PROPERTIES OUTPUT_NAME compat)

install(TARGETS compat compat_static
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

install(FILES compat.h DESTINATION include)
