/*
 * Point.hpp
 */

// todo: The access to xy_ref at GeoObj should be not possible for Point user.

#ifndef POINT_HPP_
#define POINT_HPP_

#include "geoobj.hpp"

namespace Geo {

class Point : public GeoObj {

public:
	Point(int xv = 0, int yv = 0) : GeoObj(xv, yv), objID(++objCnt) {};
	Point(Coords& obj) : GeoObj(obj), objID(++objCnt) {};
	Point(const Point& obj);

	virtual ~Point() { if (objCnt > 0) objCnt-- ; };

	void draw();
	int getObjArea() const;

    int getRef_X() const;  //todo why const. [A] because << operator in the other place is const
    int getRef_Y() const;

    int getObjID() const { return objID; };

    Point& operator=(const Point& obj);

private:
    int objID;

};

} /* namespace Geo */

std::ostream& operator<<(std::ostream& os, const Geo::Point& obj);

#endif /* POINT_HPP_ */
