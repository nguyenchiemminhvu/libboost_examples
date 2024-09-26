#include <iostream>
#include <string>
#include <boost/regex.hpp>

int main()
{
    std::string ip = "192.168.1.123";

    boost::regex pattern("(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?).(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?).(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?).(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)");
    if (boost::regex_match(ip, pattern))
    {
        std::cout << "Valid ip v4 address" << std::endl;
    }
    else
    {
        std::cout << "Invalid ip v4 address" << std::endl;
    }

    return 0;
}