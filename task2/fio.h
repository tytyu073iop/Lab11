#pragma once

#include <iostream>
#include <ostream>
#include <string>

class Fio {
    public:
        std::string name;
        std::string surname;
        std::string dadname;
        Fio();
        Fio(std::string, std::string, std::string);
        friend std::ostream& operator<<(std::ostream&, const Fio&);
        friend std::istream& operator>>(std::istream&, Fio&);
        int operator<=>(const Fio&) const;
};
