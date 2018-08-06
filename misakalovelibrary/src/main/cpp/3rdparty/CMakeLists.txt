
file(GLOB_RECURSE SOURCE *.c*)

add_library(libpng_core
            STATIC
            ${SOURCE})
