#include <iostream>
#include <boost/geometry.hpp>

int main()
{
    boost::geometry::model::point<double, 2, boost::geometry::cs::cartesian> point1(0.0, 0.0);
    boost::geometry::model::point<double, 2, boost::geometry::cs::cartesian> point2(3.0, 4.0);
    std::cout << "Distance (Cartesian) from point1 to point2: " 
              << boost::geometry::distance(point1, point2) << std::endl;
    
    boost::geometry::model::point<double, 2, boost::geometry::cs::geographic<boost::geometry::degree>> point3(0.0, 0.0); // (lat, lon)
    boost::geometry::model::point<double, 2, boost::geometry::cs::geographic<boost::geometry::degree>> point4(0.0, 1.0); // (lat, lon)
    std::cout << "Distance (Geographic) from point3 to point4: " 
              << boost::geometry::distance(point3, point4) << std::endl;

    boost::geometry::model::point<double, 3, boost::geometry::cs::cartesian> point5(0.0, 0.0, 0.0);
    boost::geometry::model::point<double, 3, boost::geometry::cs::cartesian> point6(1.0, 2.0, 3.0);
    std::cout << "Distance (Cartesian 3D) from point5 to point6: " 
              << boost::geometry::distance(point5, point6) << std::endl;

    boost::geometry::set<0>(point1, 1.0);
    boost::geometry::set<1>(point1, 1.0);
    boost::geometry::set<0>(point2, 4.0);
    boost::geometry::set<1>(point2, 5.0);
    std::cout << "Updated Distance (Cartesian) from point1 to point2: " 
              << boost::geometry::distance(point1, point2) << std::endl;

    return 0;
}
