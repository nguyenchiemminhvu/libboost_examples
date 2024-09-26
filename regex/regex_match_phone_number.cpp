#include <iostream>
#include <string>
#include <boost/regex.hpp>

int main()
{
    std::string phone = "(+84) 93-435-9954";

    // boost::regex pattern("\\(\\+\\d{2}\\)\\s\\d{2}-\\d{3}-\\d{4}");
    boost::regex pattern(R"(\(\+\d{1,3}\)\s\d{2}-\d{3}-\d{4})");
    if (boost::regex_match(phone, pattern))
    {
        std::cout << "Valid phone number" << std::endl;
    }
    else
    {
        std::cout << "Invalid phone number" << std::endl;
    }

    return 0;
}