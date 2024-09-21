#include <iostream>
#include <boost/filesystem.hpp>

int main()
{
    boost::filesystem::path curPath(boost::filesystem::current_path());
    if (boost::filesystem::exists(curPath))
    {
        std::cout << curPath << " exists" << std::endl;
    }
    else
    {
        std::cerr << curPath << " does not exist" << std::endl;
    }

    boost::filesystem::path filePath = curPath / "hello_boost_filesystem";
    if (boost::filesystem::exists(filePath))
    {
        std::cout << filePath << " exists" << std::endl;
    }
    else
    {
        std::cerr << filePath << " does not exist" << std::endl;
    }

    curPath.append(boost::filesystem::path("temp"));
    if (boost::filesystem::exists(curPath))
    {
        std::cout << curPath << " exists" << std::endl;
    }
    else
    {
        std::cerr << curPath << " does not exist" << std::endl;
    }

    return 0;
}