#include <iostream>
#include <boost/geometry.hpp>

int main()
{
    boost::geometry::model::polygon<boost::geometry::model::point<double, 2, boost::geometry::cs::cartesian>> poly;

    boost::geometry::append(poly, boost::geometry::model::point<double, 2, boost::geometry::cs::cartesian>(0.0, 0.0));
    boost::geometry::append(poly, boost::geometry::model::point<double, 2, boost::geometry::cs::cartesian>(0.0, 5.0));
    boost::geometry::append(poly, boost::geometry::model::point<double, 2, boost::geometry::cs::cartesian>(5.0, 5.0));
    boost::geometry::append(poly, boost::geometry::model::point<double, 2, boost::geometry::cs::cartesian>(7.0, 0.0));
    boost::geometry::append(poly, boost::geometry::model::point<double, 2, boost::geometry::cs::cartesian>(0.0, 0.0));

    std::cout << "Area of polygon: " << boost::geometry::area(poly) << std::endl;

    boost::geometry::model::point<double, 2, boost::geometry::cs::cartesian> point(6.0, 1.0);
    if (boost::geometry::within(point, poly))
    {
        std::cout << "Point is within polygon" << std::endl;
    }
    else
    {
        std::cout << "Point is outside polygon" << std::endl;
    }

    return 0;
}