// 02_expressions_tests.cpp
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "hwexpressions.h"

TEST_CASE("Verify get_sales_tax_amount function")
{
    REQUIRE(get_sales_tax_amount(10) == Approx(0.675));
    REQUIRE(get_sales_tax_amount(20) == Approx(1.35));
}

TEST_CASE("Verify get_tip_amount function")
{
    REQUIRE(get_tip_amount(20, 0.15) == Approx(3.0));
    REQUIRE(get_tip_amount(30, 0.20) == Approx(6.0));
}
