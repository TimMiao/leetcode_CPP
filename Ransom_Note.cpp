#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <algorithm>
using std::remove;
using std::find;

bool canConstruct(string ransomNote, string magazine) {
    std::sort(ransomNote.begin(), ransomNote.end());
    std::sort(magazine.begin(), magazine.end());
    string temp_str = ransomNote;
    string mag = magazine;
    std::string temp = "";
    while (ransomNote.length() > 0) {
        if (std::find(magazine.begin(), magazine.end(), ransomNote[0]) 
            != magazine.end()) {
            temp += ransomNote[0];
            remove(ransomNote.begin(), ransomNote.end(), magazine[0]);
            remove(magazine.begin(), magazine.end(), magazine[0]);
        }
    }
    if (temp_str.length() == mag.length()) {
        if (temp == mag) {
            return true;
        }
        else {
            return false;
        }
    }
    if (temp == temp_str) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    string ransomNote = "bg";
    string magazine = "efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj";
    bool boolean = canConstruct(ransomNote, magazine);
    cout << boolean << endl;
}