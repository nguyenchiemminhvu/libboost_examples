#include <iostream>
#include <string>
#include <boost/program_options.hpp>

int main(int argc, char** argv)
{
    boost::program_options::options_description desc("Options");
    desc.add_options()
        ("help,h", "Print help messages")
        ("debug,d", "Enable debug messages")
        ("file,f", boost::program_options::value<std::string>(), "input file");
    
    boost::program_options::variables_map vm;
    try
    {
        boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
        boost::program_options::notify(vm);

        if (vm.count("help"))
        {
            std::cout << desc << std::endl;
            return 0;
        }

        if (vm.count("debug"))
        {
            std::cout << "Enable debug messages" << std::endl;
        }

        if (vm.count("file"))
        {
            std::cout << "Input file: " << vm["file"].as<std::string>() << std::endl;
        }
        else
        {
            std::cout << "Missing input file" << std::endl;
        }
    }
    catch(const boost::program_options::error& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    
    return 0;
}