#include <iostream>
#include <cmath>

using namespace std;

int climbingStairs(int n) {
    double phi = (1+sqrt(5))/2;
    double psi = (1-sqrt(5))/2;

    auto steps = (pow(phi, n+1) - pow(psi, n+1))/sqrt(5);

    return steps;
}

int main() {
    cout << climbingStairs(3) << endl;
    cout << climbingStairs(2) << endl;
}