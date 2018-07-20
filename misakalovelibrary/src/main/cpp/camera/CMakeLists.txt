
file(GLOB SOURCE *.cpp)
add_library(camera_preview_core
            STATIC
            ${SOURCE})



target_link_libraries(  camera_preview_core
                       libcommon
                       render_core
                        )