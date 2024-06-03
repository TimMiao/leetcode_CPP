#include <string>
using std::string;

int scoreOfString(string s) {
    int str_score = 0;
    for (size_t i = 0; i < s.length(); ++i) {
        int abs_val = 0;
        if (i < s.length() - 1) {
            abs_val = abs(s[i] - s[i + 1]);

        }
        str_score += abs_val;
    }
    return str_score;
}