#include <iostream>
#include <fstream>
#include <boost/system/error_code.hpp>
#include <boost/system/system_error.hpp>

void read_file(const std::string& file_name)
{
    std::ifstream file(file_name);
    
    boost::system::error_code ec;
    if (!file.is_open())
    {
        ec = boost::system::errc::make_error_code(boost::system::errc::no_such_file_or_directory);
        throw boost::system::system_error(ec, "Failed to open file");
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
    }

    file.close();
}

int main()
{
    try
    {
        read_file("temp");
    }
    catch (boost::system::system_error& ex)
    {
        std::cerr << ex.what() << std::endl;
        return ex.code().value();
    }

    return 0;
}