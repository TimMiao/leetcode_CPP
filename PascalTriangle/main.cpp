/**
* @file main.cpp
* @author Tim Miao
*/



#include <iostream>
#include <vector>
#include "pascal_triangle.h"
using namespace std;


int main()
{
    constexpr int numRow = 5;
    pascal_triangle pascalTri;
    const vector<vector<int> > result = pascalTri.get_pascal_triangle(numRow);


    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
