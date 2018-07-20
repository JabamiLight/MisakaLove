
file(GLOB MESSAGE_QUEUQ_SOURCE ./message_queue/*.cpp)
file(GLOB EGL_CORE_SOURCE ./egl_core/*.cpp)
file(GLOB ASSETS_UTIL_SOURCE ./assetsutil/*.cpp)

add_library(libcommon
            STATIC
            ${MESSAGE_QUEUQ_SOURCE}
            ${EGL_CORE_SOURCE}
            ${ASSETS_UTIL_SOURCE}
            )

target_link_libraries(libcommon
                       z
                       android
                       GLESv3
                       EGL
                       log)