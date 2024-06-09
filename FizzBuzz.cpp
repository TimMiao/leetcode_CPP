#include <vector>

#include <string>

std::vector<std::string> fizzBuzz(int n) {
    std::vector<std::string> vec;
    for (int i = 1; i <= n; ++i) {
        if (i % 3 == 0 && i % 5 == 0) {
            vec.push_back("FizzBuzz");
            continue;
        }
        if (i % 3 == 0) {
            vec.push_back("Fizz");
            continue;
        }
        if (i % 5 == 0) {
            vec.push_back("Buzz");
            continue;
        }
        vec.push_back(std::to_string(i));
    }
    return vec;
}