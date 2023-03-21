#include <files/csv.hpp>

#include <catch2/catch_all.hpp>

#include <sstream>
#include <string>

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

    SECTION("Inserting csv::endl adds a new row") {
      auto csv = files::csv{};
      csv << 1 << files::csv::endl;
      REQUIRE(1 == csv.rows());

      csv << 2;

      REQUIRE(2 == csv.rows());
      REQUIRE(1 == csv.cols());
    }

    SECTION("Values can have different types") {
      auto csv = files::csv{};

      SECTION("integer values") {
        SECTION("int8_t")   csv << std::int8_t{-5};
        SECTION("int16_t")  csv << std::int16_t{-5};
        SECTION("int32_t")  csv << std::int32_t{-5};
        SECTION("int64_t")  csv << std::int64_t{-5};
        SECTION("uint8_t")  csv << std::uint8_t{5};
        SECTION("uint16_t") csv << std::uint16_t{5};
        SECTION("uint32_t") csv << std::uint32_t{5};
        SECTION("uint64_t") csv << std::uint64_t{5};
      }

      SECTION("floating-point values") {
        SECTION("float") csv << 3.142f;
        SECTION("double") csv << 2.718;
        SECTION("long double") csv << static_cast<long double>(1.618);
      }

      SECTION("boolean values") {
        SECTION("true") csv << true;
        SECTION("false") csv << false;
      }

      SECTION("string values") {
        SECTION("std::string") csv << std::string{"foo"};
        SECTION("const char*") csv << "foo";
        SECTION("std::string_view") csv << std::string_view{"foo"};
      }
    }
  }
}
