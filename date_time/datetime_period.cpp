#include <iostream>
#include <boost/date_time.hpp>

int main()
{
    boost::gregorian::date_period per(boost::gregorian::date(2024, 9, 25), boost::gregorian::date(2024, 10, 25));
    std::cout << per << std::endl;
    std::cout << per.contains(boost::gregorian::from_string("2024/09/30")) << std::endl;
    std::cout << per.length().days() << std::endl;

    return 0;
}