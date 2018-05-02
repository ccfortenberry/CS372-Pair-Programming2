#define  CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "calculator.hpp"

TEST_CASE("Empty string returns 0", "[calculator]") 
{
	REQUIRE(add("") == 0);
}


TEST_CASE("Single number string", "[calculator]") 
{
	REQUIRE(add("1") == 1);
	REQUIRE(add("3") == 3);
	REQUIRE(add("17") == 17);
	REQUIRE(add("998") == 998);
}

TEST_CASE("Two numbers comma delimimted", "[calculator]") 
{
	REQUIRE(add("1,1") == 2);
	REQUIRE(add("3,0") == 3);
	REQUIRE(add("17,105") == 122);
	REQUIRE(add("998,11") == 1009);
}

TEST_CASE("Two numbers newline delimimted", "[calculator]") 
{
	REQUIRE(add("1\n1") == 2);
	REQUIRE(add("3\n0") == 3);
	REQUIRE(add("17\n105") == 122);
	REQUIRE(add("998\n11") == 1009);
}

TEST_CASE("Three numbers newline and comma delimimted", "[calculator]")
{
	REQUIRE(add("1,1,1") == 3);
	REQUIRE(add("3\n0\n5") == 8);
	REQUIRE(add("17\n105,20") == 142);
	REQUIRE(add("998\n11,1") == 1010);
}

TEST_CASE("Checking for exceptions with negative numbers", "[calculator]") 
{
	CHECK_THROWS(add("1,1,-1"));
	CHECK_THROWS(add("3\n-1\n5"));
	CHECK_THROWS(add("-17\n105,20"));
	CHECK_THROWS(add("-2098,-1001\n1000"));
	CHECK_THROWS(add("-2098,1001\n-1000"));
	CHECK_THROWS(add("2098,-1001\n1000-"));
	CHECK_THROWS(add("-998\n-11,-1"));
	CHECK_THROWS(add("-1"));
	CHECK_THROWS(add("-1,1"));
	CHECK_THROWS(add("3,-2"));
}

TEST_CASE("Ignore values greater than 1000", "[calculator]") 
{
	REQUIRE(add("1001") == 0);
	REQUIRE(add("17\n105,29999") == 122);
	REQUIRE(add("17,99994") == 17);
	REQUIRE(add("99994,17") == 17);
	REQUIRE(add("1,1293,2") == 3);
	REQUIRE(add("1230,0\n8") == 8);
	REQUIRE(add("17,105,20002") == 122);
	REQUIRE(add("17,1002,20002") == 17);
}

TEST_CASE("Single Custom Delimiter", "[calculator]") 
{
	REQUIRE(add("//$\n0") == 0);
	REQUIRE(add("//?\n17?105") == 122);
	REQUIRE(add("//{\n17{17") == 34);
	REQUIRE(add("//f\n1,1f1") == 3);
	REQUIRE(add("//@\n5@3") == 8);
	REQUIRE(add("//;\n17;105,20") == 142);
}

TEST_CASE("Multiple Custom Delimiters", "[calculator]") 
{
	REQUIRE(add("//abcdefghijklmnopqrstuvwxyz\n1a1b1c1d1e1f1g1h1i1j1k1l1m1n1o1p1q1r1s1t1u1v1w1x1y1z1") == 27);
}

TEST_CASE("Bad Custom Delimiters", "[calculator]") 
{
	CHECK_THROWS(add("//#1,2,3,4,5"));
	CHECK_THROWS(add("//abcdefghijklmnopq"));
}