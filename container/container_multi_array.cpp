#include <iostream>
#include <string>
#include <cstdint>
#include <boost/multi_array.hpp>

int main()
{
    boost::multi_array<int, 2> matrix(boost::extents[3][4]);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matrix[i][j] = i * j;
        }
    }

    int* p_mat = matrix.data();
    for (int i = 0; i < 12; i++)
    {
        std::cout << p_mat[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}