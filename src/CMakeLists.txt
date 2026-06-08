cmake_minimum_required(VERSION 3.10)
project(libcompat_src C)

add_library(compat SHARED pthread.c qsort.c getenv.c progname.c strverscmp.c versionsort.c)
set_target_properties(compat PROPERTIES VERSION 1.0 SOVERSION 1)
target_include_directories(compat PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(compat_static STATIC pthread.c qsort.c getenv.c progname.c strverscmp.c versionsort.c)
set_target_properties(compat_static PROPERTIES OUTPUT_NAME compat)
target_include_directories(compat_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

install(TARGETS compat compat_static
        LIBRARY DESTINATION lib COMPONENT lib
        ARCHIVE DESTINATION lib COMPONENT lib)

install(FILES include/compat.h DESTINATION include COMPONENT headers)
install(FILES include/libcompat/pthread.h include/libcompat/qsort.h include/libcompat/getenv.h include/libcompat/progname.h include/libcompat/strverscmp.h include/libcompat/versionsort.h DESTINATION include/libcompat COMPONENT headers)

install(CODE "execute_process(COMMAND \${CMAKE_COMMAND} -E create_symlink compat.h \"\$ENV{DESTDIR}\${CMAKE_INSTALL_PREFIX}/include/libcompat.h\")" COMPONENT headers)

add_custom_target(install_lib
    COMMAND ${CMAKE_COMMAND} -DCMAKE_INSTALL_COMPONENT=lib -P ${CMAKE_BINARY_DIR}/cmake_install.cmake
    DEPENDS compat compat_static
)

add_custom_target(install_headers
    COMMAND ${CMAKE_COMMAND} -DCMAKE_INSTALL_COMPONENT=headers -P ${CMAKE_BINARY_DIR}/cmake_install.cmake
)
