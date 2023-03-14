#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

namespace files {

class csv {
  struct cell {
    uint64_t value;
  };

 public:

  [[nodiscard]] size_t rows() const { return _rows; }
  [[nodiscard]] size_t cols() const { return _cols; }

  csv& operator<<(uint64_t val) {
    _cells.emplace_back(val);
    ++_cols;
    if (0 == _rows) {
      ++_rows;
    }

    return *this;
  }

 private:
  std::vector<cell> _cells;
  size_t _rows{};
  size_t _cols{};
};

}  // namespace files
