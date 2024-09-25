#include <iostream>
#include <string>
#include <boost/date_time.hpp>

int main()
{
    boost::gregorian::date d{2024, 9, 25};
    std::cout << d << std::endl;
    std::cout << d.year() << std::endl;
    std::cout << d.month() << std::endl;
    std::cout << d.day() << std::endl;
    std::cout << d.week_number() << std::endl;
    std::cout << d.day_of_week().as_number() << std::endl;

    std::cout << "Release version: " << std::to_string(d.year()) + "." + std::to_string(d.week_number()) + "-" + std::to_string(d.day_of_week()) << std::endl;

    return 0;
}