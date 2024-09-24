#include <iostream>
#include <string>
#include <cstdint>
#include <boost/json.hpp>

int main()
{
    std::string json_str = R"({
        "name": "Nguyen Chiem Minh Vu",
        "age": 30,
        "skills": ["C++", "DSA", "Linux"],
        "is_unemployed": true
    })";

    boost::json::value parsed_json = boost::json::parse(json_str);
    boost::json::object root = parsed_json.as_object();

    if (root.find("name") != root.end())
    {
        std::string name = root["name"].as_string().c_str();
        std::cout << name << std::endl;
    }

    if (root.find("age") != root.end())
    {
        int64_t age = root["age"].as_int64();
        std::cout << age << std::endl;
    }

    if (root.find("skills") != root.end())
    {
        std::vector<std::string> all_skill;
        boost::json::array skills = root["skills"].as_array();
        for (int i = 0; i < skills.size(); i++)
        {
            std::string skill = skills[i].as_string().c_str();
            all_skill.push_back(skill);
        }

        for (const std::string& skill : all_skill)
        {
            std::cout << skill << " ";
        }
        std::cout << std::endl;
    }

    if (root["is_unemployed"].as_bool())
    {
        std::cout << "Will code for food. Please hire me!" << std::endl;
    }

    return 0;
}