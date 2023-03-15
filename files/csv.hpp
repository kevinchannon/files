#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>
#include <variant>

namespace files {

class csv {
  using cell = std::int64_t;
  using cell_row = std::vector<cell>;

 public:
  struct endl_t {};
  static constexpr auto endl = endl_t{};

  [[nodiscard]] size_t rows() const { return _rows.size() - (_rows.back().empty() ? 1 : 0); }
  [[nodiscard]] size_t cols() const { return _cols; }

  csv& operator<<(uint64_t val) {
    _rows.back().emplace_back(val);
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
