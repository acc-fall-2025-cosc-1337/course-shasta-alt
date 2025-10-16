#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "repetition.h"

TEST_CASE("get_factorial computes small n correctly")
{
    REQUIRE(get_factorial(1) == 1);
    REQUIRE(get_factorial(3) == 6);
    REQUIRE(get_factorial(5) == 120);
    REQUIRE(get_factorial(9) == 362880);
}

TEST_CASE("sum_odd_numbers adds odds up to n")
{
    REQUIRE(sum_odd_numbers(1) == 1);          // 1
    REQUIRE(sum_odd_numbers(2) == 1);          // 1
    REQUIRE(sum_odd_numbers(7) == 16);         // 1+3+5+7
    REQUIRE(sum_odd_numbers(10) == 25);        // 1+3+5+7+9
    REQUIRE(sum_odd_numbers(99) == 2500);      // known sum
}
