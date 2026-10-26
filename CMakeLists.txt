cmake_minimum_required(VERSION 3.21)

project(dxfviewer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

add_library(core INTERFACE
    core/entities.h
)

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

target_include_directories(core INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})