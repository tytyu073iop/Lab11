#include "fio.h"
#include <tuple>

Fio::Fio(std::string n, std::string s, std::string d) : name(n), surname(s), dadname(d) {}

Fio::Fio() = default;

std::ostream& operator<<(std::ostream& stream, const Fio& f) {
    stream << f.surname << ' ' << f.name << ' ' << f.dadname;
    return stream;
}

std::istream& operator>>(std::istream& stream, Fio& f) {
    stream >> f.surname >> f.name >> f.dadname;
    return stream;
}

int Fio::operator<=>(const Fio& right) const {
    auto first = std::tie(surname, name, dadname);
    auto second = std::tie(right.surname, right.name, right.dadname);
    if (first > second) {
        return 1;
    } 
    if (first < second) {
        return -1;
    }          
    return 0;
   
}
