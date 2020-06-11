#include <iostream>
#include <ostream>
#include <istream>
#include <typeinfo>
#include "linkedList.cpp"
#include "Product.cpp"

int main() {
    system("chcp 1251");
    system("cls");

    //create file here
    linkedList<Product> list;

    //int size = 0, tmpCount;
    //string  tmpCategory, tmpFio, tmpName, workshop = "";

    //while (size == 0)
    //{
    //    try {
    //        cout << "Enter the size of the list, please: ";
    //        cin >> size;
    //        if (size <= 0) throw 1;
    //    }
    //    catch (int e) {
    //        invalidInput(e);
    //    }
    //}

    //for (int i = 1; i <= size; i++) {
    //    cout << "Input element " << i << ": ";
    //    try {
    //        cout << "Category (A, B or C): ";
    //        cin >> tmpCategory;
    //        cout << "FIO: ";
    //        cin >> tmpFio;
    //        cout << "Name: ";
    //        cin >> tmpName;
    //        cout << "Count: ";
    //        cin >> tmpCount;
    //        if (cin.fail()) throw 2;

    //        Product s(tmpCategory, tmpFio, tmpName, tmpCount);
    //        //list.add(s);
    //        //Write file here
    //    }
    //    catch (int e) {
    //        invalidInput(e);
    //        i--;
    //    }
    //}

    Product prod;
    int s;

    prod.addProductBat();
    cout << "Bat File contents:" << endl;
    prod.getProductBat(0);

    cout << "Введите номер сотрудника, чьи данные надо поменять: " << endl;
    cin >> s;
    cout << "Вы хотите изменить: " << endl;
    prod.getProductBat(sizeof(Product) * (s - 1), 1);
    prod.editProductBat(sizeof(Product) * (s - 1));

    cout << "After editing: " << endl;
    prod.getProductBat(0);

   /* cout << "List:" << endl;
    list.print();
    list.sort(Product::sortByFio());
    cout << "Sorted by FIO" << endl;
    list.print();
    list.sort(Product::sortByCategory());
    cout << "Sorted by category" << endl;
    list.print();
    list.sort(Product::sortByCount());
    cout << "Sorted by count" << endl;
    list.print();

    while (workshop == "")
    {
        try {
            cout << "Enter workshop name, please: ";
            cin >> workshop;
            if (workshop == "") throw 1;
        }
        catch (int e) {
            invalidInput(e);
        }
    }

    auto filtered = list.filter(Product::getByName(workshop));
    cout << "Filtered by workshop name" << endl;
    filtered.print();*/
    return 0;
}