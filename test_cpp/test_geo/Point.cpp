/*
 * Point.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: liberdaa
 */

#include "Point.hpp"

namespace Geo {


Point::Point(const Point& obj)
{
	if (this != &obj)
	{
		objID = ++objCnt;
		xy_ref = obj.xy_ref;
		obj_area = obj.obj_area;
	}
}


void Point::draw()
{
    std::cout << "Point draw() function." << std::endl;
    std::cout << "Point object ID: " << getObjID() << std::endl;
    std::cout << "Point: Objects Counter: " << GeoObj::getObjCnt() << std::endl;
    std::cout << "Point xy_ref X: " << xy_ref.x << std::endl;
    std::cout << "Point xy_ref Y: " << xy_ref.y << std::endl;
}


int Point::getObjArea() const
{
    return obj_area;
}


int Point::getRef_X() const { return xy_ref.x; }
//int Point::getRef_X() { return xy_ref.x; }

int Point::getRef_Y() const { return xy_ref.y; }


Point& Point::operator=(const Point& obj)
{
	if (this == &obj) return *this;

	xy_ref = obj.xy_ref;
	obj_area = obj.obj_area;

	return *this;
}


} /* namespace Geo */


// Note:
// Because parameter is const defined, the functions has to be const as well (?)
// as well.
std::ostream& operator<<(std::ostream& os, const Geo::Point& obj)
{
    os << "Description: Class Point object." << std::endl;
    os << "Description: object ID: " << obj.getObjID() << std::endl;
    os << "Description: Objects Counter: " << Geo::GeoObj::getObjCnt() << std::endl;
    os << "Description: Coordinates: " << std::endl;
    os << "Description: Ref X: " << obj.getRef_X() << std::endl;
    os << "Description: Ref Y: " << obj.getRef_Y() << std::endl;
    os << "Description: Area: " << obj.getObjArea() << std::endl;

	return os;
}

