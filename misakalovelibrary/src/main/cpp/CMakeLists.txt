
cmake_minimum_required(VERSION 3.4.1)

add_subdirectory(./opengl)
add_subdirectory(./libcommon)
add_subdirectory(./camera)
add_subdirectory(./libeditcore)
add_subdirectory(./3rdparty)
add_library( # Sets the name of the library.
             native-lib
             SHARED
             jni/ChangbaRecordingPreviewScheduler.cpp )

target_link_libraries( # Specifies the target library.
                       native-lib
                       camera_preview_core
                       )