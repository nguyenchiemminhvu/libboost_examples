#include <iostream>
#include <string>
#include <cstdint>
#include <map>
#include <boost/property_map/property_map.hpp>

class EmployeeRecord
{
public:
    EmployeeRecord() : name("Unknown"), age(0), grade(0) {}

    EmployeeRecord(const std::string& name, int age, int grade)
        : name(name), age(age), grade(grade)
    {}

    std::string to_string() const
    {
        return name + " " + std::to_string(age) + " " + std::to_string(grade);
    }

    std::string name;
    int age;
    int grade;
};

typedef std::map<int, EmployeeRecord> EmployeeBoard;

template <typename Board>
void increase_grade(int id, Board& board)
{
    EmployeeRecord& emp = boost::get(board, id);
    emp.grade++;
}

int main()
{
    EmployeeBoard e_map;
    e_map.insert(std::make_pair(0, EmployeeRecord("Nguyen Chiem Minh Vu", 30, 3)));
    e_map.insert(std::make_pair(1, EmployeeRecord("Le Nhat Truong", 25, 2)));
    e_map.insert(std::make_pair(2, EmployeeRecord("Nguyen Minh Hieu", 25, 2)));

    boost::associative_property_map<EmployeeBoard> e_map_wrapper(e_map);
    increase_grade(1, e_map_wrapper);
    increase_grade(2, e_map_wrapper);

    for (const auto& p : e_map)
    {
        std::cout << p.first << " " << p.second.to_string() << std::endl;
    }

    return 0;
}