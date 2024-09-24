#include <iostream>
#include <cstdint>
#include <string>
#include <type_traits>
#include <boost/core/enable_if.hpp>

template <typename T>
typename boost::enable_if<std::is_integral<T>, T>::type add(T a, T b)
{
    return a + b;
}

template <typename T>
typename boost::enable_if<std::is_same<T, std::string>, T>::type add(T a, T b)
{
    return a + b;
}

int main()
{
    std::cout << add<int>(1, 2) << std::endl;
    std::cout << add<uint32_t>(1U, 2U) << std::endl;
    // std::cout << add<double>(1.0, 2.0) << std::endl; // compile error

    std::cout << add<std::string>("hello", "boost") << std::endl;

    return 0;
}