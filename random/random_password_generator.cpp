#include <iostream>
#include <string>
#include <boost/random.hpp>
#include <boost/random/random_device.hpp>
#include <boost/program_options.hpp>

#define DEFAULT_NUMBER_MIN 5
#define DEFAULT_NUMBER_MAX 10

const std::string lower_candidates("abcdefghijklmnopqrstuvwxyz");
const std::string upper_candidates("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
const std::string special_candidates("~!@#$%^&*,.");

void shuffle(std::string& s)
{
    boost::random::random_device rd;
    boost::random::mt19937 rng(rd());

    for (std::size_t i = s.length() - 1; i > 0; i--)
    {
        boost::random::uniform_int_distribution<> dist(0, i);

        std::size_t chosen_idx = dist(rng);
        std::swap(s[i], s[chosen_idx]);
    }
}

std::string generating_password(int lower, int upper, int special)
{
    std::string password;

    boost::random::random_device rd;
    boost::random::mt19937 rng(rd());

    boost::random::uniform_int_distribution<> lower_dist(0, lower_candidates.size() - 1);
    boost::random::uniform_int_distribution<> upper_dist(0, upper_candidates.size() - 1);
    boost::random::uniform_int_distribution<> special_dist(0, special_candidates.size() - 1);

    for (int i = 0; i < lower; i++)
    {
        password += lower_candidates[lower_dist(rng)];
    }

    for (int i = 0; i < upper; i++)
    {
        password += upper_candidates[upper_dist(rng)];
    }

    for (int i = 0; i < special; i++)
    {
        password += special_candidates[special_dist(rng)];
    }

    shuffle(password);

    return password;
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

        boost::random::random_device rd;
        boost::random::mt19937 rng(rd());
        boost::random::uniform_int_distribution<> default_dist(DEFAULT_NUMBER_MIN, DEFAULT_NUMBER_MAX);

        int count_lower = 0;
        int count_upper = 0;
        int count_special = 0;

        if (vm.count("lower"))
        {
            count_lower = vm["lower"].as<int>();
        }
        else
        {
            count_lower = default_dist(rng);
        }

        if (vm.count("upper"))
        {
            count_upper = vm["upper"].as<int>();
        }
        else
        {
            count_upper = default_dist(rng);
        }

        if (vm.count("special"))
        {
            count_special = vm["special"].as<int>();
        }
        else
        {
            count_special = default_dist(rng);
        }

        std::cout << "Generating a password containing:\n" 
                << count_lower << " lower-case letters\n"
                << count_upper << " upper-case letters\n" 
                << count_special << " special letters\n" 
                << std::endl;

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