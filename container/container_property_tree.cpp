#include <iostream>
#include <string>
#include <cstdint>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

int main()
{
    boost::property_tree::ptree PT;

    try
    {
        boost::property_tree::read_json("sample.json", PT);

        std::string server_address = PT.get<std::string>("config.server.address");
        int port = PT.get<uint32_t>("config.server.port");

        std::cout << server_address << ":" << port << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    if (PT.empty())
    {
        PT.put<std::string>("config.server.address", "nguyenchiemminhvu.com");
        PT.put<uint32_t>("config.server.port", 8000);
        PT.put<uint32_t>("config.backup_port", 12345);

        for (int i = 0; i < 10; i++)
        {
            PT.add("features", std::string("feature_") + std::to_string(i + 1));
        }

        boost::property_tree::write_json("sample.json", PT);
    }

    return 0;
}