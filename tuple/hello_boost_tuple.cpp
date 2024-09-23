#include <iostream>
#include <string>
#include <boost/tuple/tuple.hpp>

boost::tuple<std::string, std::string, int> createEmployee(const std::string& id, const std::string& name, int grade)
{
    return boost::make_tuple(id, name, grade);
}

void printEmployee(const boost::tuple<std::string, std::string, int>& person)
{
    std::cout << "=========================================" << std::endl;
    std::cout << "ID: " << boost::get<0>(person) << std::endl;
    std::cout << "Name: " << boost::get<1>(person) << std::endl;
    std::cout << "Grade: " << boost::get<2>(person) << std::endl;
    std::cout << "=========================================" << std::endl;
}

int main()
{
    boost::tuple<std::string, std::string, int> newEmp = createEmployee("vu3.nguyen", "NCMV", 3);
    printEmployee(newEmp);

    boost::get<2>(newEmp) = 4;
    printEmployee(newEmp);

    return 0;
}