#include <iostream>
#include <boost/container/deque.hpp>

int main()
{
    boost::container::deque<int> myDeque;

    // Adding elements to the back and front
    myDeque.push_back(10);
    myDeque.push_back(20);
    myDeque.push_front(5);

    std::cout << "Elements in myDeque: ";
    for (const int& elem : myDeque)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Removing elements from the front
    myDeque.pop_front();
    std::cout << "After pop_front: ";
    for (const int& elem : myDeque)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Accessing elements
    std::cout << "First element: " << myDeque.front() << std::endl;
    std::cout << "Last element: " << myDeque.back() << std::endl;

    return 0;
}
