#include <iostream>
#include <string>

bool isHappy(int n) {
    if (n < 10 && n != 1) {
        return false;
    }
    while (n > 1) {
        // std::string n_str = std::to_string(n);
        // int sum = 0;
        // for (size_t i = 0; i < n_str.length(); ++i) {
        //     int the_temp = int(n_str[i]);
        //     int temp = pow(the_temp, 2);
        //     sum += temp;
        // }
        // n = sum;
        int div = n / 10;
        int remainder = n % 10;
        int sum = pow(div, 2) + pow(remainder, 2);
        n = sum;
        if (n < 10) {
            break;
        }
    }
    if (n == 1) {
        return true;
    }
    return false;
}

int main() {
    bool boolean = isHappy(19);
    std::cout << boolean << std::endl;
}