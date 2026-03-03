#include <catch2/catch_test_macros.hpp>
#include "GeometryEngine.h"

TEST_CASE("Engine initializes correctly")
{
    GeometryEngine engine;

    REQUIRE(engine.isInitialized() == true);
}
