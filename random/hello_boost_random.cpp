#include <iostream>
#include <boost/random.hpp>
#include <boost/random/random_device.hpp>

int main()
{
    boost::random::random_device rd;
    boost::random::mt19937 rng(rd());

    boost::random::uniform_int_distribution<> int_dist(0, 100);
    for (int i = 0; i < 10; i++)
    {
        std::cout << int_dist(rng) << " ";
    }
    std::cout << std::endl;

    boost::random::normal_distribution<> normal_dist(0.0, 1.0);
    for (int i = 0; i < 10; i++)
    {
        std::cout << normal_dist(rng) << " ";
    }
    std::cout << std::endl;

    boost::random::binomial_distribution<> binomial_dist(10, 0.5);
    for (int i = 0; i < 10; i++)
    {
        std::cout << binomial_dist(rng) << " ";
    }
    std::cout << std::endl;

    boost::random::bernoulli_distribution<> bool_dist(0.5);
    for (int i = 0; i < 10; i++)
    {
        std::cout << bool_dist(rng) << " ";
    }
    std::cout << std::endl;

    return 0;
}