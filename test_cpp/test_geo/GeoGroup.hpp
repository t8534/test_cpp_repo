/*
 * GeoGroup.hpp
 */

#ifndef GEOGROUP_HPP_
#define GEOGROUP_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include "geoobj.hpp"

namespace Geo {

class GeoGroup : public GeoObj {

public:
	GeoGroup() {};
	//todo: cannot initialize  ": configFileName(fname)" if Constructor is defined
	// at .cpp
	GeoGroup(const std::string fname);
	GeoGroup(const GeoGroup& obj);
	virtual ~GeoGroup();  //todo: what about if writing the file throw exception.

	void draw();
    int area();

    void addGeoObj(GeoObj& obj);
    void removeGeoObj(GeoObj& obj);

    void addGeoObj(GeoObj* obj);
    void removeGeoObj(GeoObj* obj);

    GeoGroup& operator=(const GeoGroup& obj);

    class CfgRWExcp {
    public:

    	CfgRWExcp(std::string m = "") : msg(m) {};
    	~CfgRWExcp() {};

    	std::string msg;
    };

    /*
    class myexception: public exception
    {
      virtual const char* what() const throw()
      {
        return "My exception happened";
      }
    } myex;
    */

    void readCfgData(const std::string fname);
    void writeCfgData(const std::string fname);

private:
    std::vector<GeoObj*> vect_geobj;
    std::string configFileName;
};


} /* namespace Geo */

//todo
std::ostream& operator<<(std::ostream& os, const Geo::GeoGroup& obj);

#endif /* GEOGROUP_HPP_ */
