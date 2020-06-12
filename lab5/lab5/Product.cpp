#include <string>
#include <iostream>

using namespace std;

inline void invalidInput(int e)
{
    cout << "Incorrect input value.\n";
    cin.clear();
    cin.ignore(256, '\n');
}

struct Product {

    string category;
    string fio;
    string name;
    int count;

    bool operator==(const Product& other) const {
        return category == other.category && fio == other.fio && name == other.name && count == other.count;
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

    static auto sortByName() {
        return [](const Product& x, const Product& z) -> bool {
            return x.name > z.name;
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