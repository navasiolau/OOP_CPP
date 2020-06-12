#include <string>
#include <iostream>

using namespace std;

struct Product {

    string category;
    string fio;
    string name;
    int count;

    bool operator==(const Product& other) const {
        return category == other.category && fio == other.fio && name == other.name && count == other.count;
    }

    bool operator!=(const Product& other) const {
        return category != other.category && fio != other.fio && name != other.name && count != other.count;
    }

    bool operator>=(const Product& other) const {
        return count >= other.count;
    }

    bool operator<(const Product& other) const {
        return count < other.count;
    }

    Product(string category, string fio, string name, int count) {
        this->category = category;
        this->fio = fio;
        this->name = name;
        this->count = count;
    }

    Product() = default;

    friend ostream& operator<<(ostream& out, const Product& s) {
        out << "Category: " << s.category << ". FIO: " << s.fio << ". Name: " << s.name << ". Count: " << s.count;
        return out;
    }
};