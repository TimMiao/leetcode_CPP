#include <iostream>
#include <vector>
#include <string>

using namespace std;

string IntegerToRoman(int num) {
    vector<int> num_vec = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> roman_vec = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string roman;
    for (int i = 0; i < num_vec.size(); ++i) {
        while (num >= num_vec[i]) {
            roman += roman_vec[i];
            num -= num_vec[i];
        }
    }

    return roman;
}

int main() {
    cout << IntegerToRoman(3479) << endl;
    cout << IntegerToRoman(1997) << endl;
}