cmake_minimum_required(VERSION 3.29)
project(MongoLauncher)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS
        Core
        Qml
        Quick
        QuickControls2
        REQUIRED)

qt6_add_resources(QML_RESOURCES
        ui/qml.qrc
)

add_executable(MongoLauncher src/main.cpp ${QML_RESOURCES}
        src/piston/version_manifest.h)
target_link_libraries(MongoLauncher
        Qt6::Core
        Qt6::Qml
        Qt6::Quick
        Qt6::QuickControls2
)

