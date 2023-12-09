#include <iostream>

class Time {
private:
  unsigned hours, minutes;
public:
  Time(unsigned, unsigned);
  unsigned GetHours();
  unsigned GetMinutes();
  friend std::ostream& operator << (std::ostream&, const Time&);
}
