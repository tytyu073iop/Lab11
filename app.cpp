#include "train.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

Time ConvertToTime(std::string s) {
    size_t i = s.find(":");
    return Time(stou(s), stou(s.substr(i)));
}

int main() {
  std::ifstream in("in.txt");
  if (!in.is_open()) { std::cout << "Error opening input file!"; return 1; }
  std::vector<Train> v;
  std::string s;
  while(std::getline(in, s)) {
    std::stringstream ss(s);
    std::string number; std::getline(ss, number, ";");
    std::string where_to; std::getline(ss, where_to, ";");
    std::string type; std::getline(ss, type, ';');
    std::string departue; std::geline(ss, deartue, ';');
    std::string way; std::getline(ss, way, ';');
    Train::Type t;
    if (type == "passager") {
      t = Train::Type::passager;
    } else if (type == "time") {
      t = Train::Type::time;
    } else {
      std::cout << "Wrong type!";
      return 2;
    }
    Time dt(ConvertToTime(departue)), wt(ConvertToTime(way));
    v.push_back(Train(stoull(number), where_to, t, dt, wt));
  }
  std::sort(v.begin(), v.end(), [](const Train& first, const Train& second){
    return first.departue < second.departue;
  });
