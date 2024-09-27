#include <iostream>
#include <boost/algorithm/cxx11/is_sorted.hpp>
#include <boost/container/vector.hpp>

int main()
{
    boost::container::vector<int> arr;
    for (int i = 0; i < 10; i++)
    {
        arr.push_back(i);
    }

    for (const int& val : arr)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    if (boost::algorithm::is_sorted(arr.begin(), arr.end()))
    {
        std::cout << "arr is sorted" << std::endl;
    }

    boost::container::vector<int> another_arr = { 1,3,4,6,8,2,0,7 };

    std::sort(another_arr.begin(), another_arr.end());
    arr.merge(another_arr.begin(), another_arr.end());

    for (const int& val : arr)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    if (boost::algorithm::is_sorted(arr.begin(), arr.end()))
    {
        std::cout << "arr is sorted" << std::endl;
    }

    return 0;
}