#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <algorithm>
using std::remove_if;
bool isSubsequence(string s, string t) {
    // string final_str = "";
    for (size_t i = 0; i < s.length(); ++i) {
        // if (std::find(t.begin(), t.end(), s[i]) != t.end()) {
        //     final_str += s[i];
        // }
        remove_if (t.begin(), t.end(), !s[i]);
    }
    cout << t << endl;
    if (t == s) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    string s = "acb";
    string t = "ahbgdc";
}