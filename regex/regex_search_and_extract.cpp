#include <iostream>
#include <string>
#include <boost/regex.hpp>

int main()
{
    std::string email = "nguyenchiemminhvu@gmail.com";

    boost::regex pattern("(\\w+)@(\\w+).(\\w+)");
    boost::smatch matches;

    if (boost::regex_search(email, matches, pattern))
    {
        std::cout << "Full match: " << matches[0] << std::endl;
        std::cout << "Username : " << matches[1] << std::endl;
        std::cout << "Domain: " << matches[2] << std::endl;
        std::cout << "Top-level domain (TLD): " << matches[3] << std::endl; 
    }

    return 0;
}