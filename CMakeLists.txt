cmake_minimum_required(VERSION 3.1)

project(roboConsole LANGUAGES CXX)

set(Qt5Core_DIR "/home/oleksii/programs/Qt/5.12.0/gcc_64/lib/cmake/Qt5Core")
set(Qt5_DIR "/home/oleksii/programs/Qt/5.12.0/gcc_64/lib/cmake/Qt5")
set(Qt5Quick_DIR "/home/oleksii/programs/Qt/5.12.0/gcc_64/lib/cmake/Qt5ml")
set(QT_QMAKE_EXECUTABLE "/home/oleksii/programs/Qt/5.12.0/gcc_64/bin/qmake.exe")



set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(build/conanbuildinfo.cmake)
conan_basic_setup()

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

aux_source_directory(. SRC_LIST)
aux_source_directory(./proto SRC_LIST)

add_executable(${PROJECT_NAME} ${SRC_LIST} "qml.qrc")

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Quick  ${CONAN_LIBS})

add_custom_target(useful_files DEPENDS ALL
    SOURCES
    command.proto
    conanfile.txt
)
