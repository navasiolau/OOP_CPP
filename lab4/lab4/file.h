#include <string>
#include <utility>
#include <fstream>
#include <iostream>

using namespace std;

struct file {

    ifstream in;
    ofstream out;

    file(const string& path) {
        in = ifstream(path);
        out = ofstream(path);
    }

    virtual ~file() {
        try {
            in.close();
            out.close();
        }
        catch (exception& e) {
            cout << "Error closing file " << e.what() << endl;
        }
    }

    string readLines() {
        string result;
        try {
            string line;
            while (std::getline(in, line)) {
                result += line;
                result.push_back('\n');
            }
        }
        catch (exception& e) {
            cout << "Error reading file " << e.what() << endl;
        }
        return result;
    }

    void writeLine(const string& text) {
        try {
            out << text << endl;
        }
        catch (exception& e) {
            cout << "Error writing to file " << e.what() << endl;
        }
        out.flush();
    }
};