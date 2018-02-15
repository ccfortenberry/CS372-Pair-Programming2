#define  CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "calculator.hpp"

TEST_CASE("Empty string returns 0", "[calculator]") {
	REQUIRE(add("") == 0);
}


TEST_CASE("Single number string", "[calculator]") {
	REQUIRE(add("1") == 1);
	REQUIRE(add("3") == 3);
	REQUIRE(add("17") == 17);
	REQUIRE(add("2098") == 2098);
	REQUIRE(add("998") == 998);
}

TEST_CASE("Two numbers comma delimimted", "[calculator]") {
	REQUIRE(add("1,1") == 2);
	REQUIRE(add("3,0") == 3);
	REQUIRE(add("17,105") == 122);
	REQUIRE(add("2098,1001") == 3099);
	REQUIRE(add("998,11") == 1009);
}