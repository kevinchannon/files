#pragma once

#include <vector>

namespace files {

  class csv {
  public:

    class cell {};

    [[nodiscard]] size_t rows() const { return _rows; }

  private:
    std::vector<cell> _cells;
    size_t _rows{};
  };



}
