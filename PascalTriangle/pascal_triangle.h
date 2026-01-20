/**
 * @file pascal_triangle.h
 * @author Tim Miao
 *
 *
 */

#ifndef PASCALTRIANGLE_PASCAL_TRIANGLE_H
#define PASCALTRIANGLE_PASCAL_TRIANGLE_H

#include <vector>


class pascal_triangle
{
private:

public:
    std::vector<std::vector<int>> get_pascal_triangle(int numRow);
};


#endif //PASCALTRIANGLE_PASCAL_TRIANGLE_H