#include <iostream>
#include <boost/math/special_functions.hpp>
#include <boost/math/interpolators/bilinear_uniform.hpp>

int main()
{
    std::cout << "Round double 3.7 = " << boost::math::round<double>(3.7) << std::endl;
    std::cout << "Round double -3.7 = " << boost::math::round<double>(-3.7) << std::endl;
    std::cout << "Round double 3.4 = " << boost::math::round<double>(3.7) << std::endl;
    std::cout << "Round double -3.4 = " << boost::math::round<double>(-3.7) << std::endl;
    std::cout << "Round int 3.7 = " << boost::math::round<int>(3.7) << std::endl;
    std::cout << "Round int -3.7 = " << boost::math::round<int>(-3.7) << std::endl;
    std::cout << "Round int 3.4 = " << boost::math::round<int>(3.7) << std::endl;
    std::cout << "Round int -3.4 = " << boost::math::round<int>(-3.7) << std::endl;

    std::cout << std::endl;

    std::cout << "Trunc 1.5 = " << boost::math::trunc<double>(1.5) << std::endl;
    std::cout << "Trunc 1.9 = " << boost::math::trunc<double>(1.9) << std::endl;
    std::cout << "Trunc -1.1 = " << boost::math::trunc<double>(-1.5) << std::endl;
    std::cout << "Trunc -1.9 = " << boost::math::trunc<double>(-1.9) << std::endl;

    std::cout << std::endl;

    double integral;
    double fractional;
    fractional = boost::math::modf(5.745, &integral);
    std::cout << "Modf of 5.745 = " << integral << " and " << fractional << std::endl;

    std::cout << std::endl;

    std::cout << "Is 1 negative = " << boost::math::signbit(1) << std::endl;
    std::cout << "Is -5.10 negative = " << boost::math::signbit(-5.10) << std::endl;
    std::cout << "Is 0 negative = " << boost::math::signbit(0) << std::endl;

    return 0;
}