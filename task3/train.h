#pragma once

#include "time.h" //NOLINT
#include <iostream>
#include <string>

using Ull = unsigned long long;

class Train {
public:
  Ull number;
  std::string where_to;
  enum class Type {
    passager, fast
  };
  Type type;
  Time departue;
  Time way;
  Train(Ull, std::string, Type, Time, Time);
  friend std::ostream& operator<<(std::ostream&, const Train&) ; //NOLINT
};
