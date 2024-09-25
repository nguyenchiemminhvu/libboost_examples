#include <iostream>
#include <fstream>
#include <cstdint>
#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

class LocationData
{
public:
    LocationData()
    {
    }

    LocationData(uint64_t t, double lat, double lon, double alt, double speed)
        : timestamp(t), lat(lat), lon(lon), alt(alt), speed(speed)
    {
    }

    void print()
    {
        std::cout << timestamp << " " << lat << " " << lon << " " << alt << " " << speed << std::endl;
    }

private:
    friend class boost::serialization::access;

    template <class Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar & timestamp;
        ar & lat;
        ar & lon;
        ar & alt;
        ar & speed;
    }

private:
    uint64_t timestamp;
    double lat;
    double lon;
    double alt;
    double speed;
};

int main()
{
    LocationData loc1(1000, 18.0, 106.0, 100.0, 0.0);

    std::ofstream out_file("loc_backup.txt");
    boost::archive::text_oarchive out_arc(out_file);
    out_arc << loc1;
    out_file.close();


    LocationData loc2;

    std::ifstream in_file("loc_backup.txt");
    boost::archive::text_iarchive in_arc(in_file);
    in_arc >> loc2;
    in_file.close();

    loc2.print();

    return 0;
}