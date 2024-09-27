#include <iostream>
#include <boost/smart_ptr/local_shared_ptr.hpp>

class Sample
{
public:
    Sample()
    {
        std::cout << "Sample constructor" << std::endl;
    }

    ~Sample()
    {
        std::cout << "Sample destructor" << std::endl;
    }

    void do_something()
    {
        std::cout << "Sample do something" << std::endl;
    }
};

int main()
{
    boost::local_shared_ptr<Sample> local_ptr(new Sample());
    boost::local_shared_ptr<Sample> another_local_ptr = local_ptr;
    std::cout << local_ptr.local_use_count() << std::endl;

    return 0;
}