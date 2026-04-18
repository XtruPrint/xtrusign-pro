add_library(xtrusign-engine STATIC)

target_sources(xtrusign-engine
    PRIVATE
        src/Engine.cpp
)

target_include_directories(xtrusign-engine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

find_package(OpenCASCADE REQUIRED)

target_link_libraries(xtrusign-engine
    PUBLIC
        ${OpenCASCADE_LIBRARIES}
)

target_include_directories(xtrusign-engine
    PUBLIC
        ${OpenCASCADE_INCLUDE_DIR}
)
target_sources(xtrusign-engine
    PRIVATE
        src/Engine.cpp
        src/GeometryEngine.cpp
)

# Future: link OpenCASCADE here
# target_link_libraries(xtrusign-engine PRIVATE OpenCASCADE::TKBRep)
