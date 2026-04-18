cmake_minimum_required(VERSION 3.20)
project(XtruSignPro VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Core modules
add_subdirectory(engine)
add_subdirectory(application)

# Desktop app
option(BUILD_DESKTOP "Build desktop app" ON)
if(BUILD_DESKTOP)
    add_subdirectory(apps/desktop)
endif()

# Tests
option(BUILD_TESTS "Build unit tests" ON)
if(BUILD_TESTS)
    enable_testing()
    # add_subdirectory(tests)
endif()

# Qt
find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)