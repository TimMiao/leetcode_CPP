#include <iostream>
#include <string>
using namespace std;

int rtoi(char c) {
    if (c == 'I') {
        return 1;
    }
    if (c == 'V') {
        return 5;
    }
    if (c == 'X') {
        return 10;
    }
    if (c == 'L') {
        return 50;
    }
    if (c == 'C') {
        return 100;
    }
    if (c == 'D') {
        return 500;
    }
    if (c == 'M'){
        return 1000;
    }
    return 0;
}

int romanToInt(string s) {
    int number = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (i + 1 < s.length() && rtoi(s[i]) < rtoi(s[i+1])) {
            number -= rtoi(s[i]);
        }
        else {
            number += rtoi(s[i]);
        }
    }
    return number;
}

int main() {
    string s = "III";
    cout << romanToInt(s) << endl;

    s = "LVIII";
    cout << romanToInt(s) << endl;

    s = "MCMXCIV";
    cout << romanToInt(s) << endl;
}