#include <iostream>
#include <string>
#include <boost/random.hpp>
#include <boost/program_options.hpp>

#define DEFAULT_NUMBER_OF_LOWERCASE 10
#define DEFAULT_NUMBER_OF_UPPERCASE 5
#define DEFAULT_NUMBER_OF_SPECIAL 5

std::string generating_password(int lower, int upper, int special)
{
    return "";
}

int main(int argc, char** argv)
{
    boost::program_options::options_description desc("Options");
    desc.add_options()
        ("help,h", "Print help messages")
        ("lower,l", boost::program_options::value<int>(), "Number of lower-case letters")
        ("upper,u", boost::program_options::value<int>(), "Number of upper-case letters")
        ("special,s", boost::program_options::value<int>(), "Number of special letters");

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

        int count_lower = 0;
        int count_upper = 0;
        int count_special = 0;

        if (vm.count("lower"))
        {
            count_lower = vm["lower"].as<int>();
        }

        if (vm.count("upper"))
        {
            count_upper = vm["upper"].as<int>();
        }

        if (vm.count("special"))
        {
            count_special = vm["special"].as<int>();
        }

        if (count_lower == 0 && count_upper == 0 && count_special == 0)
        {
            std::cout << "No lower/upper/special letters specified, generating a password with default option" << std::endl;
            count_lower = DEFAULT_NUMBER_OF_LOWERCASE;
            count_upper = DEFAULT_NUMBER_OF_UPPERCASE;
            count_special = DEFAULT_NUMBER_OF_SPECIAL;
        }
        else
        {
            std::cout << "Generating a password containing:\n" 
                << count_lower << " lower-case letters\n"
                << count_upper << " upper-case letters\n" 
                << count_special << " special letters" << std::endl;
        }

        std::string password = generating_password(count_lower, count_upper, count_special);
        std::cout << password << std::endl;
    }
    catch (const boost::program_options::error& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}