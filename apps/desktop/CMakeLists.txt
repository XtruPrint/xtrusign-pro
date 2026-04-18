find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(xtrusign-desktop
    src/main.cpp
    src/MainWindow.cpp
    src/OcctViewer.cpp 
)

target_link_libraries(xtrusign-desktop
    PRIVATE
        Qt6::Widgets
        xtrusign-engine
)

target_include_directories(xtrusign-desktop
    PRIVATE
        ${CMAKE_SOURCE_DIR}/engine/src
)