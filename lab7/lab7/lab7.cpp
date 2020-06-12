#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include "Product.cpp"

using namespace std;

template<class T>
void print(const vector<T>& vector) {
    for (auto const& i : vector) {
        cout << i << endl;
    }
}

template<class T, class T1>
void findDiff(T vector1, T1 vector2) {
    auto i2 = vector2.begin();
    for (auto i1 = vector1.begin(); i1 < vector1.end(); i1++) {
        if (*i1 != *i2) {
            cout << "First diff element:\t" << *i2 << ' ' << endl;
            break;
        }
        i2++;
    }
}

template<class T, class T1, class T2>
T setValues(T vector1, T1 searchValue, T2 replaceValue) {
    cout << "Desired value:\t\t" << searchValue << endl;
    cout << "Value for replace:\t" << replaceValue << endl;
    for (auto i = vector1.begin(); i < vector1.end(); i++) {
        if (*i == searchValue) {
            cout << "*i: " << *i << endl;
            *i = replaceValue;
        }
    }

    return vector1;
}

template<class T>
void insertionSort(vector<T>& vector) {
    T tmp;
    auto j = vector.begin();

    for (auto i = vector.begin(); i < vector.end(); i++)
    {
        j = i;
        tmp = *i;
        while (j != vector.begin() && tmp < *(j - 1))
        {
            *j = *(j - 1);
            j--;
        }
        *j = tmp;
    }
}

int main()
{
    vector<Product> vector1, vector2;
    int arr1[6] = { 34, 3, 31, 98, 92, 23 };
    int count = 6;
    for (int i = 0; i < count; i++) {
        if (i < 2)
        {
            Product s("B", to_string(1), to_string(1), arr1[2]);
            vector1.push_back(s);
        }
        else
        {
            Product s("A", to_string(i), to_string(-i), arr1[i]);
            vector1.push_back(s);
        }
    }

    int arr2[6] = { 34, 3, 111, 98, 12, 23 };
    for (int i = 0; i < count; i++) {
        Product s("A", to_string(i), to_string(-i), arr2[i]);
        vector2.push_back(s);
    }


    cout << "Vector1:" << endl;
    print(vector1);

    cout << "Vector2:" << endl;
    print(vector2);

    findDiff(vector1, vector2);

    Product forSearch("B", to_string(1), to_string(1), 31);
    Product forReplace("C", to_string(1), to_string(4), 88);
    vector1 = setValues(vector1, forSearch, forReplace);
    cout << "Vector1 after replace:" << endl;
    print(vector1);
    cout << "Vector1 after insertion sort: " << endl;
    insertionSort(vector1);
    print(vector1);
    cout << "Vector2 after insertion sort: " << endl;
    insertionSort(vector2);
    print(vector2);
}