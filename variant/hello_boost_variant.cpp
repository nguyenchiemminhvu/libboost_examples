#include <iostream>
#include <string>
#include <boost/variant.hpp>

int main()
{
    boost::variant<std::size_t, std::string> var = "Hello boost variant";
    std::cout << var << std::endl;

    var = boost::get<std::string>(var).length();
    std::cout << var << std::endl;

    var = std::string(boost::get<std::size_t>(var), 'a');
    std::cout << var << std::endl;

    try
    {
        int i = boost::get<std::size_t>(var);
    }
    catch(const boost::bad_get& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    if (var.type() == typeid(std::string))
    {
        std::cout << "var has typeid string" << std::endl;
    }

    return 0;
}