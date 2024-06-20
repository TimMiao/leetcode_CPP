#include <string>
using std::string;
#include <stack>
using std::stack;

bool isValid(string s) {
    std::stack<char> stack;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        }
        else {
            if (stack.empty() || 
                (c == ')' && stack.top() != '(') || 
                (c == ']' && stack.top() != '[') || 
                (c == '}' && stack.top() != '{')) {
                    return false;
            }
            stack.pop();
        }
    }
    return stack.empty();
}