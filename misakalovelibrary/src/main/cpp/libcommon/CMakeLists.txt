
file(GLOB_RECURSE COMMON_SOURCE *.c*)
add_library(libcommon
            STATIC
            ${COMMON_SOURCE})


target_link_libraries(libcommon
                       z
                       lib_png
                       android
                       GLESv3
                       EGL
                       log)