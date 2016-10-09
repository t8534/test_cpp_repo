/*
 * Coords.hpp
 */

#ifndef COORDS_HPP_
#define COORDS_HPP_

namespace Geo {

class Coords {

public:
	Coords(int xv = 0, int yv = 0) : x(xv), y(yv) {};
	Coords(Coords& obj) : x(obj.x), y(obj.y) {};
	virtual ~Coords() {};

	Coords& operator=(const Coords& obj)
	{
		if(this == &obj) return *this;
		x = obj.x;
		y = obj.y;

		return *this;
	}

	int x;
	int y;
};

} /* namespace Geo */

#endif /* COORDS_HPP_ */
