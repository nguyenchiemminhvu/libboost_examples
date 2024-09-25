#include <iostream>
#include <cstdint>
#include <memory>
#include <fstream>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/access.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/export.hpp>
#include <boost/serialization/version.hpp>

class LocationData
{
public:
    LocationData() {}
    LocationData(uint64_t timestamp, double lat, double lon, double alt, double speed)
        : timestamp(timestamp), lat(lat), lon(lon), alt(alt), speed(speed)
    {
    }
    virtual ~LocationData() {}

    virtual void print()
    {
        std::cout << timestamp << " " << lat << " " << lon << " " << alt << " " << speed << std::endl;
    }

protected:
    uint64_t timestamp;
    double lat;
    double lon;
    double alt;
    double speed;

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
};

class ExtendedLocationData : public LocationData
{
public:
    ExtendedLocationData()
        : LocationData()
    {
    }

    ExtendedLocationData(uint64_t timestamp, double lat, double lon, double alt, double speed, double hor_acc, double ver_acc, double s_acc)
        : LocationData(timestamp, lat, lon, alt, speed), hor_acc(hor_acc), ver_acc(ver_acc), speed_acc(s_acc)
    {
    }

    virtual ~ExtendedLocationData() {}

    virtual void print()
    {
        std::cout << timestamp << " " << lat << " " << lon << " " << alt << " " << speed << " " << hor_acc << " " << ver_acc << " " << speed_acc << std::endl;
    }

private:
    double hor_acc;
    double ver_acc;
    double speed_acc;

private:
    friend class boost::serialization::access;

    template <class Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar & boost::serialization::base_object<LocationData>(*this);
        ar & hor_acc;
        ar & ver_acc;

        if (version >= 2)
        {
            ar & speed_acc;
        }
    }
};

BOOST_CLASS_EXPORT(ExtendedLocationData);
BOOST_CLASS_VERSION(ExtendedLocationData, 2);

int main()
{
    std::shared_ptr<LocationData> base_instance = std::make_shared<ExtendedLocationData>(1000, 18.0, 107.0, 100.0, 0.0, 1.0, 2.0, 1.0);

    std::ofstream out_file("poly.txt");
    boost::archive::text_oarchive out_arc(out_file);
    out_arc << base_instance;
    out_file.close();

    std::shared_ptr<LocationData> loaded_data;

    std::ifstream in_file("poly.txt");
    boost::archive::text_iarchive in_arc(in_file);
    in_arc >> loaded_data;
    in_file.close();

    loaded_data->print();

    return 0;
}