#define  CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "calculator.hpp"

TEST_CASE("Empty string returns 0", "[calculator]") {
	REQUIRE(add("") == 0);
}