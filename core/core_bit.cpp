#include <iostream>
#include <boost/core/bit.hpp>

int main()
{
    if (boost::core::has_single_bit(0b0001000U))
    {
        std::cout << 0b0001000U << " is power of 2" << std::endl;
    }

    std::cout << "Count trailing zeros of " << 0b00010000U << ": " << boost::core::countr_zero(0b00010000U) << std::endl;
    std::cout << "Count trailing zeros of " << 0b00010000U << ": " << __builtin_ctzll(0b00010000U) << std::endl;

    std::cout << "Pop count " << 0b100101011U << ": " << boost::core::popcount(0b100101011U) << std::endl;
    std::cout << "Pop count " << 0b100101011U << ": " << __builtin_popcount(0b100101011U) << std::endl;

    std::cout << "Rotate left " << 0b00001U << ": " << boost::core::rotl(0b00001U, 1) << std::endl;
    std::cout << "Rotate left " << 0b00001U << ": " << (0b00001U << 1U) << std::endl;

    return 0;
}