/*
 * Rectangle.hpp
 */

#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

#include <iostream>
#include "geoobj.hpp"

namespace Geo {

class Rectangle : public GeoObj {
public:
	Rectangle(int xref = 0, int yref = 0, int w = 0, int h = 0) : GeoObj(xref, yref), width(w), height(h), objID(++objCnt) { obj_area = (w*h); };
	Rectangle(Coords& obj, int w = 0, int h = 0) : GeoObj(obj), width(w), height(h), objID(++objCnt) { obj_area = (w*h); };
	Rectangle(const Rectangle& obj);
	virtual ~Rectangle() { if (objCnt > 0) objCnt-- ; };

	void draw();
	int getObjArea() const;

    int getRef_X() const ;
    int getRef_Y() const ;
    int getWidth() const ;
    int getHeight() const ;

    int getObjID() const { return objID; };

    Rectangle& operator=(const Rectangle& obj);

private:
	int width;
	int height;
	int objID;

};



} /* namespace Geo */


std::ostream& operator<<(std::ostream& os, const Geo::Rectangle& obj);

#endif /* RECTANGLE_HPP_ */
