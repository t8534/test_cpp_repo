/*
 * Rectangle.cpp
 */

#include "Rectangle.hpp"

namespace Geo {

Rectangle::Rectangle(const Rectangle& obj)
{
	if (this != &obj)
	{
		objID = ++objCnt;
		xy_ref = obj.xy_ref;
		obj_area = obj.obj_area;
		width = obj.width;
		height = obj.height;
	}
}

void Rectangle::draw()
{
    std::cout << "Rectangle draw() function." << std::endl;
    std::cout << "Rectangle object ID: " << getObjID() << std::endl;
    std::cout << "Rectangle Objects Counter: " << GeoObj::getObjCnt() << std::endl;
    std::cout << "Rectangle Ref_X: " << xy_ref.x << std::endl;
    std::cout << "Rectangle Ref_Y: " << xy_ref.y << std::endl;
    std::cout << "Rectangle Width: " << width << std::endl;
    std::cout << "Rectangle Height: " << height << std::endl;
    std::cout << "Rectangle Area: " << obj_area << std::endl;
}


int Rectangle::getObjArea() const
{
    return obj_area;
}


int Rectangle::getRef_X() const { return xy_ref.x; }

int Rectangle::getRef_Y() const { return xy_ref.y; }

int Rectangle::getWidth() const { return width; }

int Rectangle::getHeight() const { return height; }

Rectangle& Rectangle::operator=(const Rectangle& obj)
{
	if (this == &obj) return *this;

	xy_ref = obj.xy_ref;
	obj_area = obj.obj_area;
	width = obj.width;
	height = obj.height;

	return *this;
}


} /* namespace Geo */


// Note:
// Because parameter is const defined, the functions has to be const as well (?)
std::ostream& operator<<(std::ostream& os, const Geo::Rectangle& obj)
{
    os << "Description: Class Rectangle object." << std::endl;
    os << "Description: object ID: " << obj.getObjID() << std::endl;
    os << "Description: Objects Counter: " << Geo::GeoObj::getObjCnt() << std::endl;
    os << "Description: Coordinates: " << std::endl;
    os << "Description: Ref X: " << obj.getRef_X() << std::endl;
    os << "Description: Ref Y: " << obj.getRef_Y() << std::endl;
    os << "Description: Width: " << obj.getWidth() << std::endl;
    os << "Description: Height: " << obj.getHeight() << std::endl;
    os << "Description: Area: " << obj.getObjArea() << std::endl;

	return os;
}
