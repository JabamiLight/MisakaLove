
file(GLOB RENDER_SOURCE *.cpp)
add_library(render_core
            STATIC
            ${RENDER_SOURCE})

target_link_libraries( render_core
                     GLESv3
                    )