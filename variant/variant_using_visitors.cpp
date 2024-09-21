#include <iostream>
#include <string>
#include <boost/variant.hpp>

class make_double_visitor : public boost::static_visitor<>
{
public:
    void operator()(int& i)
    {
        i *= 2;
    }

    void operator()(std::string& s)
    {
        s.insert(s.end(), s.begin(), s.end());
    }
};

int main()
{
    boost::variant<int, std::string> var;
    make_double_visitor visitor;

    var = "hello boost variant";
    boost::apply_visitor(visitor, var);
    std::cout << var << " length " << boost::get<std::string>(var).length() << std::endl;

    var = boost::get<std::string>(var).length();
    boost::apply_visitor(visitor, var);
    std::cout << var << std::endl;

    return 0;
}