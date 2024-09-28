#include <iostream>
#include <string>
#include <boost/unordered_set.hpp>

int main()
{
    boost::unordered_set<std::string> usernames;

    std::string username;
    char choice;

    do {
        std::cout << "Enter a username to register: ";
        std::cin >> username;

        auto result = usernames.insert(username);

        if (result.second)
        {
            std::cout << "Username '" << username << "' registered successfully!" << std::endl;
        }
        else
        {
            std::cout << "Error: Username '" << username << "' is already taken!" << std::endl;
        }

        std::cout << "Do you want to add another username? (y/n): ";
        std::cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    std::cout << "\nRegistered Usernames:" << std::endl;
    for (const auto& name : usernames)
    {
        std::cout << name << std::endl;
    }

    if (usernames.find("ncmv") != usernames.end())
    {
        std::cout << "User ncmv exists, delete it" << std::endl;
        usernames.erase("ncmv");
    }

    return 0;
}
