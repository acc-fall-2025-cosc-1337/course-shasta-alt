// 01_data_types_tests.cpp
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "data_types.h"

TEST_CASE("Verify multiply_numbers function")
{
    REQUIRE(multiply_numbers(7, 7) == 49);
    REQUIRE(multiply_numbers(5, 5) == 25);
    REQUIRE(multiply_numbers(10, 2) == 20);
}


