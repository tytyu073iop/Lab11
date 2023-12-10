#pragma once

#include <iostream>

class Time {
private:
  unsigned hours, minutes; //NOLINT
public:
  Time(unsigned, unsigned);
  unsigned GetHours() const; //NOLINT
  unsigned GetMinutes() const; //NOLINT
  friend std::ostream& operator<<(std::ostream&, const Time&) ; //NOLINT
    int operator<=>(const Time& right) const; 
};
