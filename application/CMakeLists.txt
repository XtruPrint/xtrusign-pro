add_library(xtrusign-application STATIC)

target_sources(xtrusign-application
    PRIVATE
        src/DocumentManager.cpp
)

target_include_directories(xtrusign-application
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(xtrusign-application
    PUBLIC
        xtrusign-engine
)
