#include <map>
#include <string>

bool canConstruct(std::string ransomNote, std::string magazine) {
    if (ransomNote.length() > magazine.length()) {
        return false;
    }

    std::unordered_map<char, int> map;

    for (char c : magazine) {
        map[c - 'a']++;
    }

    for (char c : ransomNote) {
        if (map[c - 'a'] == 0) {
            return false;
        }
        map[c - 'a']--;
    }
    return true;
}