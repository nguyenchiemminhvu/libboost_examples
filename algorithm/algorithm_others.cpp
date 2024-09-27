#include <iostream>
#include <vector>
#include <string>
#include <boost/algorithm/clamp.hpp>
#include <boost/algorithm/find_not.hpp>
#include <boost/algorithm/find_backward.hpp>

int main()
{
    // Sample vector of integers
    std::vector<int> values = {10, 25, 30, 45, 60, 25, 80, 90, 25, 100};

    // Clamp range
    int lower_bound = 20;
    int upper_bound = 60;

    // Clamping values within the range [lower_bound, upper_bound]
    for (int& value : values)
    {
        value = boost::algorithm::clamp(value, lower_bound, upper_bound);
    }

    std::cout << "Clamped Values: ";
    for (const int& value : values)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    auto it = boost::algorithm::find_not(values.begin(), values.end(), 25);
    if (it != values.end())
    {
        std::cout << "First value not equal to 25: " << *it << std::endl;
    }
    else
    {
        std::cout << "All values are equal to 25." << std::endl;
    }

    auto reverse_it = boost::algorithm::find_backward(values.begin(), values.end(), 25);
    if (reverse_it != values.end())
    {
        std::cout << "Last occurrence of 25 found at position: " 
                  << std::distance(values.begin(), reverse_it) << std::endl;
    }
    else
    {
        std::cout << "Value 25 not found." << std::endl;
    }

    return 0;
}