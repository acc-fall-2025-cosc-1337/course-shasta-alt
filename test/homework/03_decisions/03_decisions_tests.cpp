// 03_decisions_tests.cpp
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "decisions.h"

TEST_CASE("Test get_letter_grade_using_if")
{
    REQUIRE(get_letter_grade_using_if(95) == "A");
    REQUIRE(get_letter_grade_using_if(85) == "B");
    REQUIRE(get_letter_grade_using_if(75) == "C");
    REQUIRE(get_letter_grade_using_if(65) == "D");
    REQUIRE(get_letter_grade_using_if(50) == "F");
}

TEST_CASE("Test get_letter_grade_using_switch")
{
    REQUIRE(get_letter_grade_using_switch(95) == "A");
    REQUIRE(get_letter_grade_using_switch(85) == "B");
    REQUIRE(get_letter_grade_using_switch(75) == "C");
    REQUIRE(get_letter_grade_using_switch(65) == "D");
    REQUIRE(get_letter_grade_using_switch(50) == "F");
}
