#include <iostream>
#include <vector>
#include <string>
#include <boost/algorithm/cxx14/equal.hpp>
#include <boost/algorithm/cxx14/mismatch.hpp>

int main()
{
    std::vector<int> arr1 = {1, 2, 3, 0, 5};
    std::vector<int> arr2 = {1, 2, 3, 4, 5};
    if (boost::algorithm::equal(arr1.begin(), arr1.end(), arr2.begin(), arr2.end()))
    {
        std::cout << "arr1 and arr2 are equal" << std::endl;
    }
    else
    {
        std::cout << "arr1 and arr2 are not equal" << std::endl;
    }

    auto mismatch_iter = boost::algorithm::mismatch(arr1.begin(), arr1.end(), arr2.begin(), arr2.end());
    if (mismatch_iter.first == arr1.end())
    {
        std::cout << "arr1 and arr2 are identical" << std::endl;
    }
    else
    {
        int idx = std::distance(arr1.begin(), mismatch_iter.first);
        std::cout << "arr1 and arr2 are mismatched at " << idx << std::endl;
        std::cout << "arr1[idx] = " << *mismatch_iter.first << std::endl;
        std::cout << "arr2[idx] = " << *mismatch_iter.second << std::endl;
    }

    return 0;
}