#include <iostream>
#include <boost/core/addressof.hpp>

int main()
{
    int a = 0;
    int *p = boost::addressof(a);
    *p = 10;
    std::cout << &a << std::endl;
    std::cout << boost::addressof(a) << std::endl;
    std::cout << p << std::endl;
    
    return 0;
}