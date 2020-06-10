#include <iostream>
#include "linkedList.cpp"
#include "Product.cpp"
#include "file.cpp"


void invalidInput(int e)
{
    cout << "Incorrect input value. Please input integer number\n";
    cin.clear();
    cin.ignore(256, '\n');
}

int main() {
    system("chcp 1251");
    system("cls");
    linkedList<Product> list;
    file f("text.txt");
    int size = 0, tmpCount;
    string  tmpCategory, tmpFio, tmpName, workshop = "";

    while (size == 0)
    {
        try {
            cout << "Enter the size of the list, please: ";
            cin >> size;
            if (size <= 0) throw 1;
        }
        catch (int e) {
            invalidInput(e);
        }
    }

    for (int i = 1; i <= size; i++) {
        cout << "Input element " << i << ": ";
        try {
            cout << "Category (A, B or C): ";
            cin >> tmpCategory;
            cout << "FIO: ";
            cin >> tmpFio;
            cout << "Name: ";
            cin >> tmpName;
            cout << "Count: ";
            cin >> tmpCount;
            if (cin.fail()) throw 2;

            Product s(tmpCategory, tmpFio, tmpName, tmpCount);
            list.add(s);
            f.writeLine(to_string(s));
        }
        catch (int e) {
            invalidInput(e);
            i--;
        }
    }

    cout << "File contents:" << endl;
    cout << f.readLines() << endl;
    cout << "List:" << endl;
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
    filtered.print();
    return 0;
}