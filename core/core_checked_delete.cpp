#include <iostream>
#include <boost/core/checked_delete.hpp>

class SampleClass
{
public: 
    ~SampleClass()
    {
        std::cout << "Destroyed SampleClass instance" << std::endl;
    }
};

int main()
{
    SampleClass* ptr = new SampleClass();
    std::cout << "1111111111" << std::endl;
    boost::checked_delete(ptr);
    ptr = nullptr;
    std::cout << "2222222222" << std::endl;

    ptr = new SampleClass[10];
    std::cout << "3333333333" << std::endl;
    boost::checked_array_delete(ptr);
    ptr = nullptr;
    std::cout << "4444444444" << std::endl;
    return 0;
}