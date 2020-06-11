#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

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

    fstream file;
    int count_sotr = 0;

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

    void addProductBat() {
        char outputSignal = 'n';

        file.open("FILE.DAT", ios::binary | ios::out | ios::in | ios::trunc);
        do
        {
            try {
                cout << "Category: " << endl;
                cin >> this->category;
                if (this->category == "") throw 1;

                cout << "FIO: " << endl;
                cin >> this->fio;
                if (this->fio == "") throw 1;

                cout << "Name: " << endl;
                cin >> this->name;
                if (this->name == "") throw 1;

                cout << "Count: " << endl;
                cin >> this->count;
                if (this->count < 0) throw 1;
            }
            catch (int e) {
                invalidInput(e);
            }

            file.write(reinterpret_cast<char*>(this), sizeof(Product));
            cout << "Menu:" << endl;
            cout << "Input \n Y - continue \n N - stop\n Your choise:";
            cin >> outputSignal;
            count_sotr++;
        } while (outputSignal == 'y');
        file.close();
    }

    void getProductBat(unsigned int s = 0, int count = 0, int time_work = 0)
    {
        file.open("FILE.DAT", ios::binary | ios::in | ios::out);
        cout << setw(5) << "#" << setw(20) << "Category" << setw(20) << "FIO" << setw(20) << "Name" << setw(20) << "Count" << setw(20) << endl;
        int index = 1;
        if (s > 0)
        {
            file.seekg(s | ios::beg);
        }
        if (time_work == 0)
        {
            while (1)
            {
                file.read(reinterpret_cast<char*>(this), sizeof(Product));
                if (file.eof()) break;
                cout << setw(5) << index << setw(20) << this->category << setw(20) << this->fio << setw(20) << this->name << setw(20) << this->count << endl;
                if (count > 0 && index == count) break;
                index += 1;
            }
        }
        if (time_work > 0)
        {
            while (1)
            {
                file.read(reinterpret_cast<char*>(this), sizeof(Product));
                if (file.eof()) break;
                if (this->count <= time_work)
                {
                    cout << setw(5) << index << setw(20) << this->category << setw(20) << this->fio << setw(20) << this->name << setw(20) << this->count << endl;
                }
                if (count > 0 && index == count) break;
                index += 1;
            }
        }
        index = 1;
        file.close();
    }

    void editProductBat(unsigned int i)
    {
        string tmpCategory, tmpName, tmpFIO;
        int tmpCount;
        file.open("FILE.DAT", ios::binary | ios::in | ios::out);

        try {
            cout << "Category: " << endl;
            cin >> this->category;
            if (this->category == "") throw 1;

            cout << "FIO: " << endl;
            cin >> this->fio;
            if (this->fio == "") throw 1;

            cout << "Name: " << endl;
            cin >> this->name;
            if (this->name == "") throw 1;

            cout << "Count: " << endl;
            cin >> this->count;
            if (this->count < 0) throw 1;
        }
        catch (int e) {
            invalidInput(e);
        }
        
        file.seekp(i | ios::beg);
        file.write(reinterpret_cast<char*>(this), sizeof(Product));
        file.close();
    }

    bool sort_true()
    {
        fstream file_2;
        file_2.open("FILE.DAT", ios::binary | ios::in | ios::out);
        Product* s;
        int one = 0;
        bool flag = true;
        file_2.seekg(0 | ios::beg);
        while (1)
        {
            s = new Product[2];
            if (file_2.eof()) break;
            file_2.seekg(one * sizeof(Product));
            file_2.read(reinterpret_cast<char*>(&s[0]), sizeof(Product));
            if (file_2.eof()) break;
            file_2.read(reinterpret_cast<char*>(&s[1]), sizeof(Product));
            if (s[0].count > s[1].count && s[1].category != "" && s[1].fio != "" && s[1].name != "")
            {
                flag = false;
                break;
            }
            one++;
        }
        file_2.close();
        return flag;
    }

    void sort_two()
    {
        Product* s;
        int one = 0;
        bool proverka = false;
        file.open("FILE.DAT", ios::binary | ios::in | ios::out);
        while (1)
        {
            s = new Product[2];
            if (file.eof()) break;
            file.seekg(one * sizeof(Product));
            file.read(reinterpret_cast<char*>(&s[0]), sizeof(Product));
            if (file.eof()) break;
            file.read(reinterpret_cast<char*>(&s[1]), sizeof(Product));
            if (s[0].count > s[1].count)
            {
                file.seekp(one * sizeof(Product));
                file.write(reinterpret_cast<char*>(&s[1]), sizeof(Product));
                file.write(reinterpret_cast<char*>(&s[0]), sizeof(Product));
            }
            one++;
        }
        file.close();
        proverka = sort_true();
        if (proverka == false)
        {
            cout << "----------------------- Resual after iteration ----------------------" << endl;
            getProductBat(0);
            cout << "------------------------------------------------------------------------------------------" << endl;
        }
    }
};