add_library(compat SHARED pthread.c qsort.c getenv.c progname.c strverscmp.c versionsort.c)
set_target_properties(compat PROPERTIES VERSION 1.0 SOVERSION 1)
target_include_directories(compat PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(compat_static STATIC pthread.c qsort.c getenv.c progname.c strverscmp.c versionsort.c)
set_target_properties(compat_static PROPERTIES OUTPUT_NAME compat)

install(TARGETS compat compat_static
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

install(FILES compat.h compat_pthread.h qsort.h getenv.h progname.h strverscmp.h versionsort.h DESTINATION include)
