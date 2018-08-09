
file(GLOB_RECURSE EDIT_SOURCE *.c*)
add_library(video_edit_core
            STATIC
            ${EDIT_SOURCE})

target_link_libraries(video_edit_core
                    libcommon
                    lib_png
                    )