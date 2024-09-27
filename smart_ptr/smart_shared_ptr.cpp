#include <iostream>
#include <thread>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

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

void thread_func(boost::shared_ptr<Sample> ptr)
{
    std::cout << ptr.use_count() << std::endl;
    ptr->do_something();
}

int main()
{
    boost::shared_ptr<Sample> s1 = boost::make_shared<Sample>();

    {
        boost::shared_ptr<Sample> s2 = s1;
        s2->do_something();
        std::cout << s1.use_count() << std::endl;
    }

    std::cout << "Back to main" << std::endl;
    s1->do_something();
    std::cout << s1.use_count() << std::endl;

    boost::shared_ptr<Sample> sample_ptr = boost::make_shared<Sample>();
    std::vector<std::thread> threads(100);
    for (int i = 0; i < 100; i++)
    {
        threads[i] = std::thread(thread_func, sample_ptr);
    }

    for (int i = 0; i < 100; i++)
    {
        threads[i].join();
    }

    return 0;
}