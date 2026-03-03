add_library(xtrusign-engine STATIC)

target_sources(xtrusign-engine
    PRIVATE
        src/GeometryEngine.cpp
)

target_include_directories(xtrusign-engine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Future: link OpenCASCADE here
# target_link_libraries(xtrusign-engine PRIVATE OpenCASCADE::TKBRep)
