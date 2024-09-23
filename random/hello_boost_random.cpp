#include <iostream>
#include <boost/random.hpp>

int main()
{
    boost::random::mt19937 rng;
    rng.seed(static_cast<unsigned int>(std::time(0)));
    boost::random::uniform_int_distribution<> int_dist(0, 100);

    for (int i = 0; i < 10; i++)
    {
        std::cout << int_dist(rng) << std::endl;
    }
    return 0;
}