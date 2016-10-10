/*
 * Line.hpp
 */

#ifndef LINE_HPP_
#define LINE_HPP_

#include "GeoObj.hpp"

namespace Geo {

class Line: public GeoObj {

public:
	Line() : GeoObj(), end(0,0), objID(++objCnt) {};
	Line(Coords begin_v, Coords end_v) : GeoObj(begin_v), end(end_v), objID(++objCnt) {};
	Line(int begin_x, int begin_y, int end_x, int end_y) : GeoObj(begin_x, begin_y), end(end_x, end_y), objID(++objCnt) {};
	Line(const Line& obj);
	virtual ~Line() { if (objCnt > 0) objCnt-- ; };

	void draw();
	int getObjArea() const;

    int getBeginX() const;
    int getBeginY() const;
    int getEndX() const;
    int getEndY() const;

    int getObjID() const { return objID; };

    Line& operator=(const Line& obj);

private:
    Coords end;
    int objID;
};


} /* namespace Geo */

std::ostream& operator<<(std::ostream& os, const Geo::Line& obj);

#endif /* LINE_HPP_ */
