#include "student.h"
#include <ostream>

Student::Student(const Fio& f, size_t c, size_t g) : fio(f), course(c), group(g) {}

std::ostream& operator<<(std::ostream& stream, const Student& s) {
    stream << s.fio << ';' << s.course << ';' << s.group;
    return stream;
}
