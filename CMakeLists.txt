cmake_minimum_required(VERSION 3.21)

project(FleshkasTunes
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick QuickControls2)

qt_standard_project_setup()

qt_add_executable(FleshkasTunes
    src/main.cpp
)

qt_add_qml_module(FleshkasTunes
    URI io.fleshka.tunes
    VERSION 1.0
    QML_FILES
        qml/Main.qml
)

target_link_libraries(FleshkasTunes
    PRIVATE
        Qt6::Quick
        Qt6::QuickControls2
)
