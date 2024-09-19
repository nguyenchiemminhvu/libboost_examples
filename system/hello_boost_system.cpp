#include <iostream>
#include <boost/system/error_code.hpp>
#include <boost/system/system_error.hpp>

void do_something(boost::system::error_code& ec)
{
    ec = boost::system::errc::make_error_code(boost::system::errc::permission_denied);
}

int main()
{
    boost::system::error_code ec;

    do_something(ec);

    if (ec != 0)
    {
        std::cerr << "Error: " << ec.message() << std::endl;
        std::cerr << "Error value: " << ec.value() << std::endl;
        std::cerr << "Error category: " << ec.category().name() << std::endl;
    }
    else
    {
        std::cout << "Done something" << std::endl;
    }

    return 0;
}