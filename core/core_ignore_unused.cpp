#include <iostream>
#include <boost/core/ignore_unused.hpp>

void accept_unused(int this_use_less_thing)
{
    boost::ignore_unused(this_use_less_thing);
}

int main()
{
    accept_unused(5);
    return 0;
}