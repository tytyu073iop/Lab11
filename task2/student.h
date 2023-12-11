#pragma once

#include "fio.h"
#include <iostream>

class Student {
    public:
        Fio fio;
        size_t course;
        size_t group;
        Student(const Fio&, size_t, size_t);
        friend std::ostream& operator<<(std::ostream&, const Student&);
};
