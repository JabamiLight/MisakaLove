

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DPNG_ARM_NEON_OPT=0") #设置C文件的编译参数
file(GLOB_RECURSE LIB_PNG_SOURCE *.c*)
add_library(lib_png
            STATIC
            ${LIB_PNG_SOURCE})
