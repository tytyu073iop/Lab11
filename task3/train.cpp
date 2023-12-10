#include "train.h"
#include <ostream>

Train::Train(Ull n, std::string s, Type t, Time d, Time w) :
    number(n), where_to(s), type(t), departue(d), way(w) {}

std::ostream& operator<<(std::ostream& out, const Train& t) {
    out << t.number << ';' << t.where_to << ';';
    switch (t.type) {
        case Train::Type::fast:
            out << "fast";
            break;
        case Train::Type::passager:
            out << "passager";
            break;
    }
    out << ';';
    out << t.departue << ';' << t.way;
    return out;
}
