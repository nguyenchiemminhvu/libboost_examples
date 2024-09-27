#include <iostream>
#include <boost/shared_array.hpp>

void printArray(const boost::shared_array<int>& arr, const size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    const size_t arraySize = 10;
    boost::shared_array<int> sharedArr(new int[arraySize]);

    for (size_t i = 0; i < arraySize; ++i)
    {
        sharedArr[i] = static_cast<int>(i * 10);
    }

    std::cout << "Array contents: ";
    printArray(sharedArr, arraySize);

    boost::shared_array<int> sharedArrCopy = sharedArr;

    std::cout << "Array contents after copying ownership: ";
    printArray(sharedArrCopy, arraySize);

    sharedArrCopy[5] = 500;

    std::cout << "Array contents after modification: ";
    printArray(sharedArr, arraySize);
    
    return 0;
}
