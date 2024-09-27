#include <iostream>
#include <boost/math/constants/constants.hpp>

int main()
{
    std::cout << boost::math::constants::pi<double>() << std::endl;
    std::cout << boost::math::double_constants::pi << std::endl;

    std::cout << boost::math::constants::two_pi<double>() << std::endl;
    std::cout << boost::math::double_constants::two_pi << std::endl;

    std::cout << boost::math::constants::e<double>() << std::endl;
    std::cout << boost::math::double_constants::e << std::endl;

    std::cout << boost::math::constants::sin_one<double>() << std::endl;
    std::cout << boost::math::double_constants::sin_one << std::endl;

    std::cout << boost::math::constants::cos_one<double>() << std::endl;
    std::cout << boost::math::double_constants::cos_one << std::endl;

    return 0;
}