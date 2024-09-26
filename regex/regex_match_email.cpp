#include <iostream>
#include <string>
#include <boost/regex.hpp>

int main()
{
    std::string email = "nguyenchiemminhvu@gmail.com";

    // boost::regex pattern("([a-zA-Z0-9]+)@([a-zA-Z0-9]+).([a-zA-Z]+)");
    boost::regex pattern(R"((\w+)@(\w+).(\w+))");
    if (boost::regex_match(email, pattern))
    {
        std::cout << "Valid email address" << std::endl;
    }
    else
    {
        std::cout << "Invalid email address" << std::endl;
    }

    return 0;
}