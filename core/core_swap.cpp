#include <iostream>
#include <string>
#include <boost/core/invoke_swap.hpp>

int main()
{
    int a = 5;
    int b = 10;
    boost::core::invoke_swap(a, b);
    std::cout << a << " " << b << std::endl;
    return 0;
}