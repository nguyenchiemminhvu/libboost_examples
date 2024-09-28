#include <iostream>
#include <vector>
#include <boost/geometry.hpp>

int main()
{
    boost::geometry::model::segment<boost::geometry::model::point<double, 2, boost::geometry::cs::cartesian>> segment1(
        boost::geometry::model::point<double, 2, boost::geometry::cs::cartesian>(0.0, 0.0),
        boost::geometry::model::point<double, 2, boost::geometry::cs::cartesian>(5.0, 5.0)
    );
    std::cout << "Length of segment1: " << boost::geometry::length(segment1) << std::endl;

    boost::geometry::model::segment<boost::geometry::model::point<double, 2, boost::geometry::cs::cartesian>> segment2(
        boost::geometry::model::point<double, 2, boost::geometry::cs::cartesian>(5.0, 0.0),
        boost::geometry::model::point<double, 2, boost::geometry::cs::cartesian>(0.0, 5.0)
    );
    std::cout << "Length of segment2: " << boost::geometry::length(segment2) << std::endl;

    if (boost::geometry::intersects(segment1, segment2))
    {
        std::cout << "segment1 intersects with segment2" << std::endl;
        
        std::vector<boost::geometry::model::point<double, 2, boost::geometry::cs::cartesian>> intersect_points;
        boost::geometry::intersection(segment1, segment2, intersect_points);
        std::cout << "Intersection points: " << std::endl;
        for (const boost::geometry::model::point<double, 2, boost::geometry::cs::cartesian>& point : intersect_points)
        {
            std::cout << "(" << point.get<0>() << " " << point.get<1>() << ")" << std::endl;
        }
    }
    else
    {
        std::cout << "segment1 does not intersect with segment2" << std::endl;
    }

    return 0;
}