#include "train.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

Time ConvertToTime(const std::string& s) {
    size_t const i = s.find(':');
    // std::cout << "DEBUG\t" << "first convertion" << '\n';
    auto const h = static_cast<unsigned int>(stoi(s));
    // std::cout << "DEBUG\t" << "second convertion" << '\n';
    std::string const ms = s.substr(i + 1);
    // std::cout << "DEBUG\t" << ms << '\t';
    auto const m = static_cast<unsigned int>(stoi(ms));
    return {h, m};
}

int main() {
  std::ifstream in("in.txt");
  if (!in.is_open()) { std::cout << "Error opening input file!"; return 1; }
  std::vector<Train> v;
  std::string s;
  while(std::getline(in, s)) {
    std::stringstream ss(s);
    std::string number; std::getline(ss, number, ';');
    std::string where_to; std::getline(ss, where_to, ';');
    std::string type; std::getline(ss, type, ';');
    std::string departue; std::getline(ss, departue, ';');
    std::string way; std::getline(ss, way, ';');
    // std::cout << "DEBUG:\t" << number << ' ' << where_to << ' ' << type << ' ' << departue << ' ' << way << '\n';
    Train::Type t = Train::Type::passager;
    if (type == "пассажирский") {
      t = Train::Type::passager;
    } else if (type == "скорый") {
      t = Train::Type::fast;
    } else {
      std::cout << "Wrong type!";
      return 2;
    }
    Time const dt(ConvertToTime(departue));
    Time const wt(ConvertToTime(way));
    v.push_back(Train(stoull(number), where_to, t, dt, wt)); //NOLINT
  }
  std::sort(v.begin(), v.end(), [](const Train& first, const Train& second){
    return first.departue < second.departue;
  });
  std::cout << "sorted by time\n";
  std::for_each(v.begin(), v.end(), [](const Train& i){ std::cout << i << '\n'; });
    {
        unsigned hour, minutes; //NOLINT
        std::cout << "enter hours and minutes to begin:\n";
        std::cin >> hour >> minutes;
        Time const begin(hour, minutes);
        std::cout << "enter hours and minutes to end:\n";
        std::cin >> hour >> minutes;
        Time const end(hour, minutes);
        if (end < begin) { std::cout << "Wrong end time!\n"; return -1; }
        auto begin_i = std::lower_bound(v.begin(), v.end(), begin, [](const Train& i, const Time& val) {
            return i.departue < val;
        });
        auto end_i = std::upper_bound(v.begin(), v.end(), end,
        [](const Time& end, const Train& i){
            return i.departue > end;
        });
        if (begin_i == end_i) {
            std::cout << "No trains for this timeline\n";
        } else {
        std::cout << "trains from " << begin << " to " << end << '\n';
        std::for_each(begin_i, end_i, [](const Train& i){ std::cout << i << '\n'; });
        }
    }
    {
        std::string where;
        std::cout << "what place: ";
        std::cin >> where;
        std::vector<Train> c(v);
        // std::cout << "DEBUG\t" << "begin removing\n";
        auto end = std::copy_if(v.begin(), v.end(), c.begin(), [&where](const Train& i){
            return i.where_to == where;
        });
        if (c.begin() == end) {
            std::cout << "No trains to that place\n";
        } else {
        std::cout << "trains to:\n";
        std::for_each(c.begin(), end, [](const Train& i){ std::cout << i << '\n'; });
        }
    }
    {
        std::string where;
        std::cout << "what place: ";
        std::cin >> where;
        std::vector<Train> c(v);
        auto end = std::copy_if(v.begin(), v.end(), c.begin(), [&where](const Train& i){
            return i.where_to == where && i.type == Train::Type::fast;
        });
        if (c.begin() == end) {
            std::cout << "No fast trains to that place\n";
        } else {
        std::cout << "fast trains to:\n";
        std::for_each(c.begin(), end, [](const Train& i){ std::cout << i << '\n'; });
        }
    }
    {
        std::string where;
        std::cout << "what place: ";
        std::cin >> where;
        std::vector<Train> c(v);
        auto end = std::copy_if(v.begin(), v.end(), c.begin(), [&where](const Train& i){
            return i.where_to == where && i.type == Train::Type::fast;
        });
        if (end == c.begin()) {
            std::cout << "No fast trains to that place\n";
        } else {
        std::cout << "fastest train to:\n";
        std::cout << *std::min_element(c.begin(), end, [](const Train& left, const Train& right) { return left.way < right.way; }) << '\n';
        }
    }
}
