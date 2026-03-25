#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool delimiter(char c, const string& delimiters) {
    return delimiters.find(c) != string::npos;
}

vector<string> split(const string& str, const string& delimiters) {
    vector<string> result;
    string temp;

    for (char c : str) {
        if (!delimiter(c, delimiters)) {
            temp += c;
        } else {
            if (!temp.empty()) {
                result.push_back(temp);
                temp.clear();
            }
            if (c != ' ') {
                result.push_back(string(1, c));
            }
        }
    }

    if (!temp.empty()) {
        result.push_back(temp);
    }

    return result;
}

int main() {
    string data;
    string delimiters = ",/.'[]*-+ ";

    cout << "Введите строку:\n";
    getline(cin, data);

    vector<string> result = split(data, delimiters);

    for (size_t i = 0; i < result.size(); i++) {
        cout << "[" << i << "] " << result[i] << endl;
    }

    return 0;
}