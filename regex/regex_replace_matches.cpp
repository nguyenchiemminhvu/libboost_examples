#include <iostream>
#include <string>
#include <boost/regex.hpp>

int main()
{
    std::string s = "Without Jesus, I can't go this far.";

    boost::regex pattern("\\.");
    std::string res = boost::regex_replace(s, pattern, "!!!");

    std::cout << s << std::endl;
    std::cout << res << std::endl;
    return 0;
}