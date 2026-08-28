cmake_minimum_required(VERSION 3.10)
project(libcompat_src C)

set(COMPAT_SOURCES
    pthread.c
    qsort.c
    getenv.c
    progname.c
    strverscmp.c
    versionsort.c
    mntent.c
    memory.c
    spawn.c
    search.c
)

add_library(compat SHARED ${COMPAT_SOURCES})
set_target_properties(compat PROPERTIES VERSION 1.0 SOVERSION 1)
target_include_directories(compat PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(compat_static STATIC ${COMPAT_SOURCES})
set_target_properties(compat_static PROPERTIES OUTPUT_NAME compat)
target_include_directories(compat_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

install(TARGETS compat
        LIBRARY DESTINATION lib COMPONENT lib
        ARCHIVE DESTINATION lib COMPONENT lib)

install(TARGETS compat_static
        LIBRARY DESTINATION lib COMPONENT dev
        ARCHIVE DESTINATION lib COMPONENT dev)

install(FILES include/compat.h DESTINATION include COMPONENT dev)
install(FILES include/compat.h DESTINATION include RENAME libcompat.h COMPONENT dev)
install(FILES
        include/libcompat/pthread.h
        include/libcompat/qsort.h
        include/libcompat/getenv.h
        include/libcompat/progname.h
        include/libcompat/strverscmp.h
        include/libcompat/versionsort.h
        include/libcompat/mntent.h
        include/libcompat/param.h
        include/libcompat/memory.h
        include/libcompat/execinfo.h
        include/libcompat/spawn.h
        include/libcompat/search.h
        DESTINATION include/libcompat COMPONENT dev)

add_custom_target(install_lib
    COMMAND ${CMAKE_COMMAND} -DCMAKE_INSTALL_COMPONENT=lib -P ${CMAKE_BINARY_DIR}/cmake_install.cmake
    DEPENDS compat compat_static
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_custom_target(install_dev
    COMMAND ${CMAKE_COMMAND} -DCMAKE_INSTALL_COMPONENT=dev -P ${CMAKE_BINARY_DIR}/cmake_install.cmake
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
