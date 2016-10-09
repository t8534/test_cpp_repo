//============================================================================
// Name        : test_cpp.cpp
// Author      : asa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdlib.h>
#include <iostream>
#include "test_geo/line.hpp"
#include "test_geo/point.hpp"
#include "test_geo/rectangle.hpp"
#include "test_geo/geogroup.hpp"

int main(void) {

	std::cout << "start" << std::endl;

	Geo::Line l;
	std::cout << "Line class: " << l << std::endl;

	Geo::Point p;
	std::cout << "Point class: " << p << std::endl;

	Geo::Rectangle r;
	std::cout << "Rectangle class: " << r << std::endl;

	Geo::GeoGroup gg("alfa");


	/*
	try
	{
		throw myex;
	}
	catch (exception& e)
	{
		std::cout << e.what() << '\n';
	}
	*/

	std::cout << "stop" << std::endl;

	return EXIT_SUCCESS;
}
