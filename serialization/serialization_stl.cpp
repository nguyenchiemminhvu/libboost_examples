#include <iostream>
#include <fstream>
#include <vector>
#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/vector.hpp>

int main()
{
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7};

    std::ofstream out_file("data.txt");
    boost::archive::text_oarchive out_arc(out_file);
    out_arc << data;
    out_file.close();

    std::vector<int> loaded_data;

    std::ifstream in_file("data.txt");
    boost::archive::text_iarchive in_arc(in_file);
    in_arc >> loaded_data;    
    in_file.close();

    for (int n : data)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}