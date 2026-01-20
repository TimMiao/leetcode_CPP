/**
 * @file pascal_triangle.cpp
 * @author Tim Miao
 */

#include "pascal_triangle.h"
#include <vector>


using namespace std;


std::vector<std::vector<int> > pascal_triangle::get_pascal_triangle(int numRow)
{
    if (numRow == 0)
    {
        return {{}};
    }
    if (numRow == 1)
    {
        return {{1}};
    }
    vector<vector<int>> result;
    vector<int> prev;


    for (int i = 0; i < numRow; i++)
    {
        vector<int> curr(i + 1, 1);
        for (int j = 1; j < i; j++)
        {
            curr[j] = prev[j-1] + prev[j];
        }
        result.push_back(curr);
        prev = curr;
    }
    return result;
}
