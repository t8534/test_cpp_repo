/*
 * Line.cpp
 */

#include <iostream>
//#include "GeoObj.hpp"
#include "Line.hpp"

namespace Geo {


//Line::Line() {}

//Line::~Line() {}

Line::Line(const Line& obj)
{
	if( this != &obj )
	{
		xy_ref = obj.xy_ref;
		end = obj.end;
		obj_area = obj.obj_area;
	}

}

void Line::draw()
{
    std::cout << "Line draw() function." << std::endl;
    std::cout << "Line object ID: " << getObjID() << std::endl;
    std::cout << "Line Objects Counter: " << GeoObj::getObjCnt() << std::endl;
    std::cout << "Line begin X: " << xy_ref.x << std::endl;
    std::cout << "Line begin Y: " << xy_ref.y << std::endl;
    std::cout << "Line end X: " << end.x << std::endl;
    std::cout << "Line end Y: " << end.y << std::endl;
}



int Line::area()
{
    std::cout << "Line area() function. Area = " << obj_area << std::endl;
    return obj_area;
}


int Line::getBeginX() const { return xy_ref.x; }

int Line::getBeginY() const { return xy_ref.y; }

int Line::getEndX() const { return end.x; }

int Line::getEndY() const { return end.y; }


Line& Line::operator=(const Line& obj)
{
	if ( this == &obj) return *this;

	xy_ref = obj.xy_ref;
	end = obj.end;
	obj_area = obj.obj_area;

	return *this;

};


} /* namespace Geo */


// Note:
// Because parameter is const defined, the funtctions getBegin* has to be const as well.
std::ostream& operator<<(std::ostream& os, const Geo::Line& obj)
{
    os << "Description: Class Line object." << std::endl;
    os << "Description: object ID: " << obj.getObjID() << std::endl;
    os << "Description: Objects Counter: " << Geo::GeoObj::getObjCnt() << std::endl;
    os << "Description: Coordinates: " << std::endl;
    os << "Description: begin X: " << obj.getBeginX() << std::endl;
    os << "Description: begin Y: " << obj.getBeginY() << std::endl;
    os << "Description: end X: " << obj.getEndX() << std::endl;
    os << "Description: end Y: " << obj.getEndY() << std::endl;
    os << "Description: Area: " << obj.obj_area << std::endl;  //todo: area is public here, and should be private

	return os;
}
