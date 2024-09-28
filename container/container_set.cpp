#include <iostream>
#include <boost/container/set.hpp>

int main()
{
    boost::container::set<int> numbers;

    numbers.insert(10);
    numbers.insert(5);
    numbers.insert(20);
    numbers.insert(15);
    
    auto result = numbers.insert(10);
    if (!result.second)
    {
        std::cout << "Element 10 already exists in the set.\n";
    }

    std::cout << "Set elements: ";
    for (const int& number : numbers)
    {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    if (numbers.find(15) != numbers.end())
    {
        std::cout << "Element 15 is in the set.\n";
    }

    numbers.erase(5);
    std::cout << "Element 5 removed from the set.\n";

    std::cout << "Set after removal: ";
    for (const int& number : numbers)
    {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    if (numbers.empty())
    {
        std::cout << "The set is empty.\n";
    }
    else
    {
        std::cout << "The set contains " << numbers.size() << " elements.\n";
    }

    return 0;
}
