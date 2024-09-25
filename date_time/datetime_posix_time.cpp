#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>

int main()
{
    boost::posix_time::ptime current_time = boost::posix_time::second_clock::local_time();
    std::cout << "Current time: " << current_time << std::endl;

    boost::posix_time::ptime specific_time(boost::gregorian::date(2024, 9, 25), 
                                           boost::posix_time::hours(13) + 
                                           boost::posix_time::minutes(45) + 
                                           boost::posix_time::seconds(30));
    std::cout << "Specific time: " << specific_time << std::endl;

    boost::posix_time::time_duration duration = boost::posix_time::hours(2) + boost::posix_time::minutes(30);
    boost::posix_time::ptime new_time = specific_time + duration;
    std::cout << "Specific time + 2 hours 30 minutes: " << new_time << std::endl;

    boost::posix_time::ptime earlier_time = new_time - boost::posix_time::hours(1);
    std::cout << "New time - 1 hour: " << earlier_time << std::endl;

    boost::posix_time::time_duration time_diff = new_time - specific_time;
    std::cout << "Difference between new time and specific time: " << time_diff << std::endl;

    std::string formatted_time = boost::posix_time::to_simple_string(current_time);
    std::cout << "Formatted current time: " << formatted_time << std::endl;

    boost::posix_time::ptime parsed_time = boost::posix_time::time_from_string("2024-09-25 13:45:30");
    std::cout << "Parsed time from string: " << parsed_time << std::endl;

    return 0;
}
