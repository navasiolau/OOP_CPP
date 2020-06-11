#include <iostream>
#include <ostream>
#include <istream>
#include <typeinfo>
#include "linkedList.cpp"
#include "Product.cpp"

int main() {
    system("chcp 1251");
    system("cls");

    Product prod;
    bool sort_flag = false;
    int field = 0;

    prod.addProductBat();
    cout << "Bat File contents:" << endl;
    prod.getProductBat(0);

    while (field == 0)
    {
        try {
            cout << "Choose field to edit: ";
            cin >> field;
            if (field <= 0) throw 1;
        }
        catch (int e) {
            invalidInput(e);
        }
    }

    cout << "------------------------------------- Field data ----------------------------------------" << endl;
    prod.getProductBat(sizeof(Product) * (field - 1), 1);
    prod.editProductBat(sizeof(Product) * (field - 1));

    cout << "After editing: " << endl;
    prod.getProductBat(0);

    while (sort_flag != true)
    {
        prod.sort_two();
        sort_flag = prod.sort_true();
    }
    cout << "------------------------ Sort results in file -----------------------------" << endl;
    prod.getProductBat(0);

    return 0;
}