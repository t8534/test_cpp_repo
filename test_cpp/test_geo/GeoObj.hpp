/*
 * GeoObj.hpp\
 *
 */


#ifndef GEOOBJ_HPP_
#define GEOOBJ_HPP_

#include <iostream>
#include "Coords.hpp"

namespace Geo {

class GeoObj {

public:
	GeoObj(Coords& v) : xy_ref(v), obj_area(0) {};
	GeoObj(int x = 0, int y = 0) : xy_ref(x,y), obj_area(0) {};
	GeoObj(const GeoObj& obj) : obj_area(0) {};
	virtual ~GeoObj() {};

	virtual void draw() = 0;
    virtual int area() = 0;

    static int getObjCnt() { return objCnt; };

    // The starting point to draw the shape.
    // With the Circle this is center of circle.
    Coords xy_ref;

    int obj_area;
    static int objCnt;

};


} /* namespace Geo */




#endif /* GEOOBJ_HPP_ */
