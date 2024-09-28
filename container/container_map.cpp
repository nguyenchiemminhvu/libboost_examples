#include <iostream>
#include <boost/container/map.hpp>
#include <boost/container/detail/pair.hpp>

int main()
{
    boost::container::map<int, std::string> employeeMap;

    employeeMap.insert(std::make_pair(101, "John Doe"));
    employeeMap.insert(std::make_pair(102, "Jane Smith"));
    employeeMap.insert(std::make_pair(103, "Alice Johnson"));

    // Accessing elements by key
    std::cout << "Employee with ID 101: " << employeeMap[101] << std::endl;
    std::cout << "Employee with ID 102: " << employeeMap[102] << std::endl;

    std::cout << "All employees:\n";
    for (const std::pair<int, std::string>& pair : employeeMap)
    {
        std::cout << "ID: " << pair.first << ", Name: " << pair.second << std::endl;
    }

    employeeMap[102] = "Jane Doe";
    std::cout << "Updated Employee with ID 102: " << employeeMap[102] << std::endl;

    employeeMap.erase(103);
    std::cout << "Employee with ID 103 removed.\n";

    if (employeeMap.empty())
    {
        std::cout << "The employee map is empty.\n";
    }
    else
    {
        std::cout << "The employee map contains " << employeeMap.size() << " elements.\n";
    }

    return 0;
}
