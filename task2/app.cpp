#include "student.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::ifstream in("Students.txt");
    if (!in) { std::cout << "Error opening Students.txt!\n"; return 1; }
    std::string line;
    std::vector<Student> v;
    while (std::getline(in, line)) {
        std::stringstream s(line);
        std::string f; std::getline(s, f, ';');
        std::string c; std::getline(s, c, ';');
        std::string g; std::getline(s, g, ';');
        std::stringstream fs (f);
        Fio fio;
        fs >> fio;
        v.push_back(Student(fio, stoul(c), stoul(g)));
    }
    {
        std::ofstream out("Fio.txt");
        if (!out) { std::cout << "Error opening Fio.txt\n"; return 2; }
        std::vector c(v);
        std::sort(c.begin(), c.end(), [](const Student& first, const Student& second) {
            return first.fio < second.fio;
        });
        std::for_each(c.begin(), c.end(), [&out](const Student& i){ out << i << '\n'; });
    }
    {
        std::ofstream out("Groups.txt");
        if (!out) { std::cout << "Error opening Groups.txt\n"; return 3; }
        std::vector c(v);
        std::sort(c.begin(), c.end(), [](const Student& first, const Student& second) {
            return std::tie(first.course, first.group, first.fio) < std::tie(second.course, second.group, second.fio);
        });
        std::for_each(c.begin(), c.end(), [&out](const Student& i){ out << i << '\n'; });
    }
    return 0;
}
