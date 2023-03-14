#include <files/csv.hpp>

#include <catch2/catch_all.hpp>

#include <sstream>

TEST_CASE("CSV tests")
{
  SECTION("Construction") {
    SECTION("Default constructs with...") {
      SECTION("zero rows")  REQUIRE(0 == files::csv{}.rows());
      SECTION("zero columns")  REQUIRE(0 == files::csv{}.cols());
    }
  }
}
