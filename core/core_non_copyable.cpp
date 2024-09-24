#include <iostream>
#include <boost/core/noncopyable.hpp>

class Singleton : private boost::noncopyable
{
public:
    static Singleton& instance()
    {
        static Singleton instance;
        return instance;
    }

    void debug()
    {
        std::cout << "Call Singleton::debug method" << std::endl;
    }
};

int main()
{
    Singleton s;
    // Singleton temp = s; // compile error

    Singleton::instance().debug();
    return 0;
}