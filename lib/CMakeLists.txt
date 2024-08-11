file(GLOB_RECURSE LIB_SOURCES *.c)
add_library(freelibc STATIC ${LIB_SOURCES})
set_target_properties(freelibc PROPERTIES OUTPUT_NAME "freelibc")
target_include_directories(freelibc PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_options(freelibc PRIVATE -Wall -Wextra -ffreestanding)

install(TARGETS freelibc
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/
        DESTINATION include/freelibc
        FILES_MATCHING PATTERN "*.h")
