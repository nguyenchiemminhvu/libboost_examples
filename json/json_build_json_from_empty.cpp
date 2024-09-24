#include <iostream>
#include <string>
#include <cstdint>
#include <boost/json.hpp>

void pretty_print(std::ostream& os, boost::json::value& j_val, std::string* indent = nullptr)
{
    std::string local_indent;
    if (indent == nullptr)
    {
        indent = &local_indent;
    }

    switch (j_val.kind())
    {
        case boost::json::kind::object:
        {
            os << "{\n";
            indent->append(4, ' ');

            boost::json::object obj = j_val.get_object();
            if (!obj.empty())
            {
                boost::json::object::iterator iter = obj.begin();
                do
                {
                    os << *indent << iter->key() << " : ";
                    pretty_print(os, iter->value(), indent);
                    iter++;
                    if (iter == obj.end())
                        break;
                    os << ",\n";
                } while (iter != obj.end());
            }

            os << "\n";
            indent->resize(indent->size() - 4);
            os << *indent << "}";
            break;
        }
        case boost::json::kind::array:
        {
            os << "[\n";
            indent->append(4, ' ');

            boost::json::array arr = j_val.get_array();
            if (!arr.empty())
            {
                boost::json::array::iterator iter = arr.begin();
                do
                {
                    os << *indent;
                    pretty_print(os, *iter, indent);
                    iter++;
                    if (iter == arr.end())
                        break;
                    os << ",\n";
                } while (iter != arr.end());
            }

            os << "\n";
            indent->resize(indent->size() - 4);
            os << *indent << "]";
            break;
        }
        case boost::json::kind::string:
        {
            os << boost::json::serialize(j_val.get_string());
            break;
        }
        case boost::json::kind::double_:
        case boost::json::kind::uint64:
        case boost::json::kind::int64:
        {
            os << j_val;
            break;
        }
        case boost::json::kind::bool_:
        {
            if (j_val.get_bool())
            {
                os << "true";
            }
            else
            {
                os << "false";
            }
            break;
        }
        case boost::json::kind::null:
        {
            os << "null";
            break;
        }
    }

    if (indent->empty())
    {
        os << "\n";
    }
}

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
    boost::json::value j_val;
    {
        boost::json::object root;

        root["Company"] = "LG Electronics R&D Vietnam";

        boost::json::object owner = json_create_employee("jongwook02.lee", "Lee Jong Wook", 50, 5);
        root["Owner"] = owner;

        boost::json::array employees;
        employees.push_back(json_create_employee("vu3.nguyen", "Nguyen Chiem Minh Vu", 30, 3));
        employees.push_back(json_create_employee("truong.le", "Le Nhat Truong", 25, 3));
        employees.push_back(json_create_employee("hieu6.nguyen", "Nguyen Minh Hieu", 25, 2));
        root["employees"] = employees;

        j_val = root;
    }

    std::cout << boost::json::serialize(j_val) << std::endl;

    pretty_print(std::cout, j_val);

    return 0;
}