#include <iostream>
#include <boost/container/string.hpp>

int main()
{
    boost::container::string boostStr = "Hello, Boost Container String!";
    
    std::cout << "String: " << boostStr << std::endl;
    
    boostStr += " It's similar to std::string.";
    std::cout << "After append: " << boostStr << std::endl;

    boostStr.insert(6, "World ");
    std::cout << "After insert: " << boostStr << std::endl;

    boostStr.erase(6, 6); // Remove "World "
    std::cout << "After erase: " << boostStr << std::endl;

    size_t pos = boostStr.find("Boost");
    if (pos != boost::container::string::npos)
    {
        boostStr.replace(pos, 5, "Modern C++");
    }
    std::cout << "After replace: " << boostStr << std::endl;

    return 0;
}
