cmake_minimum_required(VERSION 3.18)

add_executable(test main.c)

target_link_libraries(test PRIVATE freelibc)

target_include_directories(test PRIVATE ${CMAKE_SOURCE_DIR}/lib)

target_compile_options(test PRIVATE -fno-stack-protector -ffreestanding -nostdlib -nostartfiles -nodefaultlibs -nostdinc)
target_link_options(test PRIVATE -fno-stack-protector -ffreestanding -nostdlib -nostartfiles -nodefaultlibs -nostdinc)
