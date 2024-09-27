#include <iostream>
#include <boost/container/list.hpp>

int main()
{
    boost::container::list<std::string> myList;

    // Adding elements to the list
    myList.push_back("Hello");
    myList.push_back("World");
    myList.push_front("Boost");

    std::cout << "Elements in myList: ";
    for (const std::string& elem : myList)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Removing an element
    myList.remove("World");
    std::cout << "After removing 'World': ";
    for (const std::string& elem : myList)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Iterating through the list
    std::cout << "Iterating through myList: ";
    for (auto it = myList.begin(); it != myList.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
