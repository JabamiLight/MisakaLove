
file(GLOB EDIT_SOURCE *.cpp)
add_library(video_edit_core
            STATIC
            ${EDIT_SOURCE})

target_link_libraries(video_edit_core
                     GLESv3
                    )