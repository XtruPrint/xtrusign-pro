find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(xtrusign-desktop
    src/main.cpp
    src/MainWindow.cpp
)

target_link_libraries(xtrusign-desktop
    PRIVATE
        Qt6::Widgets
        xtrusign-application
)  
