#include <string>
#include "time.h"
#include <iostream>

using ull = unsigned long long;

class Train {
public:
  ull number;
  std::string where_to;
  enum class Type {
    passager, fast
  }
  Type type;
  Time departue;
  Time way;
  Train(ull, std::string, Type, Time, Time);
  friend std::ostream& operator<<(std::ostream&, const Train&) const;
}
