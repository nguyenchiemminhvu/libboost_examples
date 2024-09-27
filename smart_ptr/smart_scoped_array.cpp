#include <iostream>
#include <boost/scoped_array.hpp>

int main()
{
    boost::scoped_array<int> data(new int[5]);
    for (int i = 0; i < 5; i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}