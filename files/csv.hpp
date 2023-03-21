#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <variant>
#include <vector>
#include <string_view>

namespace files {

template <typename T>
concept cell_value =
    requires(T) {
      std::is_same_v<bool, T> || std::is_same_v<std::int8_t, T> || std::is_same_v<std::int8_t, T> ||
          std::is_same_v<std::int16_t, T> || std::is_same_v<std::int32_t, T> || std::is_same_v<std::int64_t, T> ||
          std::is_same_v<std::uint8_t, T> || std::is_same_v<std::uint16_t, T> || std::is_same_v<std::uint32_t, T> ||
          std::is_same_v<std::uint64_t, T> || std::is_same_v<float, T> || std::is_same_v<double, T> ||
          std::is_same_v<long double, T> || std::is_same_v<std::string, T> || std::is_same_v<std::string_view, T> ||
          std::is_same_v<std::wstring, T> || std::is_same_v<std::wstring_view, T>;
    };

class csv {
  using cell     = std::variant<bool,
                            std::int8_t,
                            std::int16_t,
                            std::int32_t,
                            std::int64_t,
                            std::uint8_t,
                            std::uint16_t,
                            std::uint32_t,
                            std::uint64_t,
                            float,
                            double,
                            long double,
                            std::string,
                            std::wstring>;
  using cell_row = std::vector<cell>;

 public:
  struct endl_t {};
  static constexpr auto endl = endl_t{};

  [[nodiscard]] size_t rows() const { return _rows.size() - (_rows.back().empty() ? 1 : 0); }
  [[nodiscard]] size_t cols() const { return _cols; }

  template <cell_value Value_T>
  csv& operator<<(Value_T val) {
    _rows.back().emplace_back(val);
    _cols = std::max(_cols, _rows.back().size());

    return *this;
  }

  template <cell_value Value_T>
    requires std::is_same_v<std::string_view, Value_T>
  csv& operator<<(Value_T val) {
    _rows.back().emplace_back(std::string{val});
    _cols = std::max(_cols, _rows.back().size());

    return *this;
  }

  template <cell_value Value_T>
    requires std::is_same_v<std::wstring_view, Value_T>
  csv& operator<<(Value_T val) {
    _rows.back().emplace_back(std::wstring{val});
    _cols = std::max(_cols, _rows.back().size());

    return *this;
  }

  csv& operator<<(endl_t) {
    _rows.emplace_back();

    return *this;
  }

 private:
  std::vector<cell_row> _rows{{cell_row{}}};
  size_t _cols{};
};

}  // namespace files
