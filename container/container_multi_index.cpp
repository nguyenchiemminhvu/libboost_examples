#include <iostream>
#include <string>
#include <cstdint>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/sequenced_index.hpp>
#include <boost/multi_index/member.hpp>

class Employee
{
public:
    int id;
    std::string name;
    int age;
    int grade;

    Employee(int id, const std::string& name, int age, int grade)
        : id(id), name(name), age(age), grade(grade)
    {
    }

    bool operator<(const Employee& other) const
    {
        return this->id < other.id;
    }
};

struct tag_id {};
struct tag_name {};
struct tag_age {};
struct tag_grade {};

int main()
{
    boost::multi_index_container<
        Employee,
        boost::multi_index::indexed_by<
            boost::multi_index::ordered_unique<
                boost::multi_index::tag<tag_id>,
                boost::multi_index::member<Employee, int, &Employee::id>
            >,
            boost::multi_index::sequenced<
                boost::multi_index::tag<tag_name>
            >,
            boost::multi_index::ordered_non_unique<
                boost::multi_index::tag<tag_age>,
                boost::multi_index::member<Employee, int, &Employee::age>
            >,
            boost::multi_index::ordered_non_unique<
                boost::multi_index::tag<tag_grade>,
                boost::multi_index::member<Employee, int, &Employee::grade>
            >
        >
    > employees;

    employees.insert(Employee(1, "Nguyen Chiem Minh Vu", 30, 3));
    employees.insert(Employee(2, "Le Nhat Truong", 25, 3));
    employees.insert(Employee(3, "Nguyen Minh Hieu", 25, 2));

    const auto& ordered_by_id = employees.get<tag_id>();
    for (const auto& employee : ordered_by_id)
    {
        std::cout << employee.id << " " << employee.name << " " << employee.age << " " << employee.grade << std::endl;
    }
    std::cout << std::endl;

    auto& sequenced_by_name = employees.get<tag_name>();
    sequenced_by_name.push_front(Employee(4, "Tran Quang Vinh", 40, 4));
    for (const auto& employee : sequenced_by_name)
    {
        std::cout << employee.id << " " << employee.name << " " << employee.age << " " << employee.grade << std::endl;
    }
    std::cout << std::endl;

    const auto& ordered_by_age = employees.get<tag_age>();
    for (const auto& employee : ordered_by_age)
    {
        std::cout << employee.id << " " << employee.name << " " << employee.age << " " << employee.grade << std::endl;
    }
    std::cout << std::endl;

    const auto& ordered_by_grade = employees.get<tag_grade>();
    for (const auto& employee : ordered_by_grade)
    {
        std::cout << employee.id << " " << employee.name << " " << employee.age << " " << employee.grade << std::endl;
    }
    std::cout << std::endl;

    const auto& found_id = ordered_by_id.find(1);
    if (found_id != ordered_by_id.end())
    {
        std::cout << "Found: " << found_id->name << " " << found_id->age << " " << found_id->grade << std::endl;
    }

    return 0;
}