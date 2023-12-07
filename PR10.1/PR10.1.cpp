#include <iostream>
#include <fstream>
#include <map>

using namespace std;

void Count(const string& filename, map<char, int>& counts) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error during opening file" << endl;
        return;
    }

    char s;
    while (file.get(s)) {
        if (s == '+' || s == '-' || s == '=') {
            counts[s]++;
        }
    }

    file.close();
}

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    map<char, int> occurrences;
    Count(filename, occurrences);

    // Виведення результатів
    cout << "Occurrences in file '" << filename << "':" << endl;
    cout << "Symbol '+' " << occurrences['+'] << " times." << endl;
    cout << "Symbol '-' " << occurrences['-'] << " times." << endl;
    cout << "Symbol '=' " << occurrences['='] << " times." << endl;

    return 0;
}
