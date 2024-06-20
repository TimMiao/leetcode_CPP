#include <string>

bool judgeCircle(std::string moves) {
    int U = 0;
    int D = 0;
    int L = 0;
    int R = 0;
    for (size_t i = 0; i < moves.length(); ++i) {
        if (moves[i] == 'U') {
            U++;
        }
        if (moves[i] == 'D') {
            D++;
        }
        if (moves[i] == 'L') {
            L++;
        }
        if (moves[i] == 'R') {
            R++;
        }
    }
    if (U == D && L == R) {
        return true;
    }
    return false;
}