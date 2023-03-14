#pragma once

#include <vector>

namespace files {

  class csv {
  public:

    class cell {};

    [[nodiscard]] size_t rows() const { return _rows; }
    [[nodiscard]] size_t cols() const { return _cols; }

  private:
    std::vector<cell> _cells;
    size_t _rows{};
    size_t _cols{};
  };
} // namespace: files
