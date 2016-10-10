/*
 * GeoGroup.cpp
 */

#include "GeoGroup.hpp"

namespace Geo {


GeoGroup::GeoGroup(const std::string fname)
{
	//todo: throwing exception from Constructor when reading file.
	try {
		readCfgData(fname);
	} catch (CfgRWExcp& e) {  //todo is reference necessary ?
		std::cout << "An exception occurred. CfgReadExcp: " << e.msg << '\n';
		// clear vector
		vect_geobj.clear();
		// In case you want to shrink the capacity of the vector along with clear():
		vect_geobj.swap(vect_geobj);
	}
}


GeoGroup::GeoGroup(const GeoGroup& obj)
{

	if (this != &obj)
	{
		xy_ref = obj.xy_ref;
		obj_area = obj.obj_area;
		vect_geobj = obj.vect_geobj;
	}

}

GeoGroup::~GeoGroup()
{
	//todo writing config file. How to propagate fault if writing to the file
	// throw exception ?
	// There should be never throw exception from destructor.
	// Perhaps the best way is to write config file separately before object
	// is destroyed.

}


void GeoGroup::draw()
{
	for( std::vector<GeoObj*>::iterator iter = vect_geobj.begin(); iter != vect_geobj.end(); ++iter )
	{
		(*iter)->draw();
	}
}

// Sum of all objects area
int GeoGroup::getObjArea() const
{
	int area_sum = 0;


	for( std::vector<GeoObj*>::const_iterator iter = vect_geobj.begin(); iter != vect_geobj.end(); ++iter )
	{
		area_sum += (*iter)->getObjArea();
	}

	return area_sum;
}


void GeoGroup::addGeoObj(GeoObj& obj)
{
	vect_geobj.push_back(&obj);
}

void GeoGroup::removeGeoObj(GeoObj& obj)
{
	for( std::vector<GeoObj*>::iterator iter = vect_geobj.begin(); iter != vect_geobj.end(); ++iter )
	{
	    if( *iter == &obj )  // todo: is it obj or &obj. Because this is the vector of pointers.
	    {
	    	vect_geobj.erase(iter);
	        break;
	    }
	}
}


void GeoGroup::addGeoObj(GeoObj* obj)
{
	vect_geobj.push_back(obj);
}


void GeoGroup::removeGeoObj(GeoObj* obj)
{
	for( std::vector<GeoObj*>::iterator iter = vect_geobj.begin(); iter != vect_geobj.end(); ++iter )
	{
	    if( *iter == obj )  // todo: is it obj or &obj. Because this is the vector of pointers.
	    {
	    	vect_geobj.erase(iter);
	        break;
	    }
	}
}

void GeoGroup::readCfgData(const std::string fname)
{
	//todo read file

	throw CfgRWExcp("This is a test exception from readCfgData()");
}


void GeoGroup::writeCfgData(const std::string fname)
{
	//todo read file

	throw CfgRWExcp("This is a test exception from writeCfgData()");
}


GeoGroup& GeoGroup::operator=(const GeoGroup& obj)
{
	if (this == &obj) return *this;

	xy_ref = obj.xy_ref;
	obj_area = obj.obj_area;
	vect_geobj = obj.vect_geobj;

	return *this;
}

} /* namespace Geo */


