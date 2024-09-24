#include <iostream>
#include <string>
#include <cstdint>
#include <boost/json.hpp>

boost::json::object json_create_employee(const std::string& id, const std::string& name, int age, int grade)
{
    boost::json::object emp;
    emp["ID"] = id;
    emp["name"] = name;
    emp["age"] = age;
    emp["grade"] = grade;
    return emp;
}

int main()
{
    boost::json::object root;

    boost::json::array employees;
    employees.push_back(json_create_employee("vu3.nguyen", "Nguyen Chiem Minh Vu", 30, 3));
    employees.push_back(json_create_employee("truong.le", "Le Nhat Truong", 25, 3));
    employees.push_back(json_create_employee("hieu6.nguyen", "Nguyen Minh Hieu", 25, 2));
    
    root["employees"] = employees;
    
    std::cout << boost::json::serialize(root) << std::endl;

    return 0;
}