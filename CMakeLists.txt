cmake_minimum_required(VERSION 3.28)

project(dxfviewer VERSION 0.1 LANGUAGES CXX)

set(LIBDXFRW_BUILD_LIBRARY ON)
set(LIBDXFRW_BUILD_DOC OFF)
set(LIBDXFRW_BUILD_DWG2DXF OFF)
set(LIBDXFRW_BUILD_TESTS OFF)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

add_library(core INTERFACE
    core/entities.h
)

add_subdirectory(external/libdxfrw)

qt_add_executable(dxfviewer
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

target_compile_options(dxfviewer PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Wall -Wextra>
)

target_link_libraries(dxfviewer PRIVATE Qt6::Widgets)
target_link_libraries(dxfviewer PRIVATE core)

target_link_libraries(dxfviewer PRIVATE  dxfrw)

target_include_directories(core INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})