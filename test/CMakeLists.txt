include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.5.2
)

FetchContent_MakeAvailable(Catch2)

add_executable(xtrusign-tests
    test_geometry.cpp
)

target_link_libraries(xtrusign-tests
    PRIVATE
        Catch2::Catch2WithMain
        xtrusign-engine
)

include(Catch)
catch_discover_tests(xtrusign-tests)
