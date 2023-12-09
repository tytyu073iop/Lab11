#include <string>

using ull = unsigned long long;

class Train {
public:
  ull number;
  std::string where_to;
  enum class Type {
    passager, fast
  }
  Type type;
  
