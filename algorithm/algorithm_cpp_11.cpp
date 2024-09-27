#include <iostream>
#include <vector>
#include <string>
#include <boost/algorithm/cxx11/all_of.hpp>
#include <boost/algorithm/cxx11/any_of.hpp>
#include <boost/algorithm/cxx11/none_of.hpp>
#include <boost/algorithm/cxx11/one_of.hpp>
#include <boost/algorithm/cxx11/is_sorted.hpp>
#include <boost/algorithm/cxx11/is_partitioned.hpp>
#include <boost/algorithm/cxx11/copy_if.hpp>

int main()
{
    std::vector<int> arr = {5, 3, 9, 15, 20};

    bool allPositive = boost::algorithm::all_of(arr.begin(), arr.end(), [](int val) { return val > 0; });
    if (allPositive)
    {
        std::cout << "All values of arr are positive" << std::endl;
    }
    else
    {
        std::cout << "Not all values of arr are positive" << std::endl;
    }

    bool anyNine = boost::algorithm::any_of_equal(arr.begin(), arr.end(), 9);
    if (anyNine)
    {
        std::cout << "Number 9 is in the arr" << std::endl;
    }
    else
    {
        std::cout << "Number 9 is not in the arr" << std::endl;
    }

    bool noneZero = boost::algorithm::none_of_equal(arr.begin(), arr.end(), 0);
    if (noneZero)
    {
        std::cout << "None of arr's value is zero" << std::endl;
    }
    else
    {
        std::cout << "There is value zero in arr" << std::endl;
    }

    bool onlyOneEven = boost::algorithm::one_of(arr.begin(), arr.end(), [](int val) { return (val % 2) == 0; });
    if (onlyOneEven)
    {
        std::cout << "Only one element of arr is even" << std::endl;
    }
    else
    {
        std::cout << "Either none or more than one elements of arr are even" << std::endl;
    }
    
    bool onlyOneOdd = boost::algorithm::one_of(arr.begin(), arr.end(), [](int val) { return val & 1; });
    if (onlyOneOdd)
    {
        std::cout << "Only one element of arr is odd" << std::endl;
    }
    else
    {
        std::cout << "Either none or more than one elements of arr are odd" << std::endl;
    }

    if (boost::algorithm::is_sorted(arr.begin(), arr.end()))
    {
        std::cout << "Arr is sorted" << std::endl;
    }
    else
    {
        std::cout << "Arr is not sorted" << std::endl;
    }

    if (boost::algorithm::is_partitioned(arr.begin(), arr.end(), [](int val) { return val & 1; }))
    {
        std::cout << "Arr starts with odd values, then ends with even values" << std::endl;
    }
    else
    {
        std::cout << "Not the expected odd-even partition" << std::endl;
    }

    std::vector<int> odd_values;
    boost::algorithm::copy_if(arr.begin(), arr.end(), std::back_inserter(odd_values), [](int val) { return val & 1; });
    std::cout << "Odd values: ";
    for (int val : odd_values)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}