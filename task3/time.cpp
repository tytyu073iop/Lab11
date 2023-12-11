#include "time.h" //NOLINT
#include <iomanip>

Time::Time(unsigned h, unsigned m) : hours(h % 24), minutes(m % 60) {};

unsigned Time::GetHours() const {
    return hours;
}

unsigned Time::GetMinutes() const {
    return minutes;
}

std::ostream& operator<<(std::ostream& out, const Time& t) {
    out << std::setw(2) << std::setfill('0') << t.hours << ':' << std::setw(2) << std::setfill('0') << t.minutes;
    return out;
}

int Time::operator<=>(const Time& right) const {
    return static_cast<int>(hours * 60 + minutes) - (right.hours * 60 + right.minutes);
}
