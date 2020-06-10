#include <iostream>

using namespace std;

struct animal {
    string name;
    string kind;
    string color;
    string country;
    int height;
    int weight;
    float price;
};

ostream& operator<<(ostream& os, const animal& animal) {
    os.unsetf(ios_base::basefield);
    os.setf(ios_base::hex);
    os << "name: " << animal.name 
       << "; kind: " << animal.kind 
       << "; color: " << animal.color 
       << "; country: " << animal.country
       << "; height: " << animal.height  
       << "; weight: " << animal.weight 
       << "; price: " << animal.price;
    return os;
}

istream& operator>>(istream& in, animal& a) {
    cout << "name ";
    in >> a.name;
    cout << "kind ";
    in >> a.kind;
    cout << "color ";
    in >> a.color;
    cout << "country ";
    in >> a.country;
    cout << "height ";
    in >> a.height;
    cout << "weight ";
    in >> a.weight;
    cout << "price ";
    in >> a.price;
    return in;
}

int main() {
    animal cow;
    cin >> cow;

    cout << "------------------------------------- Base output ------------------------------------\n";
    cout << cow;
    cout.setf(ios_base::hex, ios_base::basefield);
    cout << "\n\n---------------------------- ios_base::hex, ios_base::basefield -----------------------------\n";
    cout << cow;
    cout.setf(ios_base::uppercase);
    cout << "\n\n------------------------------ ios_base::uppercase -----------------------------------\n";
    cout << cow;
    cout.setf(ios_base::oct);
    cout << "\n\n------------------------------ ios_base::oct -----------------------------------\n";
    cout << cow;

    return 0;
}
