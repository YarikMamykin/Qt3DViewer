cmake_minimum_required(VERSION 3.0)

project(QtWalkthrough)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt5 REQUIRED COMPONENTS 3DCore 3DExtras 3DRender 3DInput)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g -pthread -fPIC")
set(CMAKE_INSTALL_PREFIX "")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(${QT_USE_FILE})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/UILoader.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/3D/ModelView.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/buttons/LoadFileButton.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/buttons/RemoveModelButton.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/labels/LoadFileLabel.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/labels/SelectedFileLabel.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/labels/HeaderLabel.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/labels/CurrentFileLabel.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/layouts/ControlElementsLayout.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/layouts/WindowLayout.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/layouts/HeaderLayout.cpp
)


file(GLOB_RECURSE COMMON_SOURCE "*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})


target_link_libraries(${PROJECT_NAME} ${Qt5Widgets_LIBRARIES})
target_link_libraries(${PROJECT_NAME} Qt5::3DCore Qt5::3DExtras Qt5::3DRender Qt5::3DInput)


configure_file(${CMAKE_CURRENT_SOURCE_DIR}/additional/mesh.stl ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/additional/close_icon.jpg ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
