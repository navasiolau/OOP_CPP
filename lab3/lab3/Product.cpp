#include <string>
#include <iostream>
#include <sstream>

using namespace std;

struct Product {
    string category;
    string fio;
    string name;
    int count;

    Product(string category, string fio, string name, int count) : category(std::move(category)), fio(std::move(fio)), name(std::move(name)), count(count) {

    }

    Product() = default;

    static auto sortByCategory() {
        return [](const Product& o1, const Product& o2) -> bool {
            return o1.category > o2.category;
        };
    }

    static auto sortByFio() {
        return [](const Product& x, const Product& z) -> bool {
            return x.fio > z.fio;
        };
    }

    static auto sortByCount() {
        return [](const Product& x, const Product& z) -> bool {
            return x.count > z.count;
        };
    }

    static auto getByName(string name) {
        return [name](const Product& s) -> bool {
            return s.name == name;
        };
    }

    friend ostream& operator<<(ostream& out, const Product& s) {
        out << "Category: " << s.category << ". FIO: " << s.fio << ". Name: " << s.name << ". Count: " << s.count;
        return out;
    }
};

inline string to_string(const Product& s) {
    ostringstream ss;
    ss << s;
    return ss.str();
}