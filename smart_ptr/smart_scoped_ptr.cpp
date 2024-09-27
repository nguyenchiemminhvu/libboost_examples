#include <iostream>
#include <boost/scoped_ptr.hpp>

class Sample
{
public:
    Sample()
        : ptr(new int(0))
    {
        
    }

    Sample(int* p)
        : ptr(p)
    {

    }

    int add_one()
    {
        return ++*ptr;
    }

    int* get()
    {
        return ptr.get();
    }

    void reset()
    {
        ptr.reset();
    }

private:
    boost::scoped_ptr<int> ptr;
};

int main()
{
    Sample s;
    std::cout << s.add_one() << std::endl;
    std::cout << s.add_one() << std::endl;

    std::cout << s.get() << std::endl;
    s.reset();
    std::cout << s.get() << std::endl;

    return 0;
}