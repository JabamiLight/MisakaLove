
cmake_minimum_required(VERSION 3.4.1)


#定义的绝对路径
set(PATH_TO_NATIVE ${PATH_TO_MEDIACORE}/misakalovelibrary/src/main/cpp)
set(PATH_TO_PRE_BUILT ${PATH_TO_MEDIACORE}/misakalovelibrary/libs/${ANDROID_ABI})
#include_directories(BEFORE ${PATH_TO_MEDIACORE}/misakalovelibrary/libs/include/)
include_directories(./libcommon/)


add_subdirectory(./opengl)
add_subdirectory(./libcommon)
add_subdirectory(./camera)
add_subdirectory(./libeditcore)
add_subdirectory(./3rdparty)
add_library( # Sets the name of the library.
             native-lib
             SHARED
             jni/ChangbaRecordingPreviewScheduler.cpp )

add_definitions(-DDLIB_PNG_SUPPORT)
target_link_libraries( # Specifies the target library.
                       native-lib
                       camera_preview_core
#                       ${PATH_TO_PRE_BUILT}/libdlib.so
#                       ${PATH_TO_PRE_BUILT}/libopencv_java3.so
                       )