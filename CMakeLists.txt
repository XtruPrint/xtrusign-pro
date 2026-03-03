cmake_minimum_required(VERSION 3.20)
project(XtruSignPro VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add subprojects
add_subdirectory(engine)
add_subdirectory(application)
add_subdirectory(apps/desktop)
