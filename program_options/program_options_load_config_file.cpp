#include <iostream>
#include <string>
#include <fstream>
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>

int main(int argc, char** argv)
{
    boost::program_options::options_description desc("Options");
    desc.add_options()
        ("help,h", "Print usage")
        ("file,f", boost::program_options::value<std::string>()->required(), "Specify configuration file");

    boost::program_options::variables_map vm;

    try
    {
        boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);

        if (vm.find("help") != vm.end())
        {
            std::cout << desc << std::endl;
            return 0;
        }

        if (vm.find("file") != vm.end())
        {
            std::string file_name = vm["file"].as<std::string>();
            if (boost::filesystem::exists(file_name))
            {
                std::ifstream file(file_name);
                if (file.is_open())
                {
                    boost::program_options::options_description file_options("Options from file");
                    file_options.add_options()
                        ("user,u", boost::program_options::value<std::string>(), "Username in whitelist");
                    boost::program_options::store(boost::program_options::parse_config_file(file_name.c_str(), file_options), vm);

                    if (vm.find("user") != vm.end())
                    {
                        std::cout << "Username: " << vm["user"].as<std::string>() << std::endl;
                    }
                }
                file.close();
            }
            else
            {
                std::cout << "Config file does not exist" << std::endl;
            }
        }
    }
    catch (const boost::program_options::error& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}