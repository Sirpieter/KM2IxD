cmake_minimum_required(VERSION 3.3)
project(FeatureFinder)
set(APP_NAME FeatureFinder)

# ===================== oF Directory =====================
set(OF_DIRECTORY $ENV{OF_HOME})

# ===================== Compiler Flags =====================
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
set(CMAKE_MODULE_PATH ${OF_DIRECTORY}/cmake)

# =========== OF addons (from addons.make) ==============
include(addons)
include_directories(/usr/include/opencv)

# =========== OF ==============
include(linux64)

# ===================== Project Source Files =====================

set(SOURCE_FILES
        ${ADDON_SOURCE_FILES}
        src/main.cpp
        src/ofApp.cpp
        )

# ============ Compile and Link ==================


add_executable(${APP_NAME} ${SOURCE_FILES} /usr/include/opencv)
add_dependencies(${APP_NAME} of_shared)
target_link_libraries(${APP_NAME} $<TARGET_FILE:of_shared>)
target_link_libraries(${APP_NAME} ${OF_CORE_LIBS})
target_link_libraries(${APP_NAME} opencv_core opencv_features2d opencv_flann opencv_highgui opencv_imgproc opencv_ml opencv_objdetect opencv_photo opencv_stitching opencv_superres opencv_video opencv_videostab)


set_target_properties(${APP_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
