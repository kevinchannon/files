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

  SECTION("Adding values") {
    SECTION("Adds a new column") {
      SECTION("In a new row if there are no existing rows") {
        auto csv = files::csv{};
        csv << 1;

        REQUIRE(1 == csv.rows());
        REQUIRE(1 == csv.cols());

        SECTION("And in an existing row if there is at least one") {
          csv << 2;
          REQUIRE(1 == csv.rows());
          REQUIRE(2 == csv.cols());
        }
      }
    }
  }
}
