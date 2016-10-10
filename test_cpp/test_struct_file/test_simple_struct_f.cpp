/*
 * test_simple_struct_f.hpp

 */

#include <iostream>
#include <fstream>
#include <vector>
#include "test_simple_struct_f.hpp"


//Read::Read() {}

//Read::Read(int v_h, int v_t): h(v_h), t(v_t) {}

// ok, work.
void test_simple_struct_f()
{
	std::ifstream is("simple_f.txt");
	if (!is)
	{
		std::cout << "Cannot open simple_f.txt." << std::endl;
		return;
	}

	int tmp_h = 0;
	int tmp_t = 0;
	std::vector<Read> vread;
	while (is >> tmp_h >> tmp_t)
	{
		//std::cout << tmp_h << " " << tmp_t << std::endl;
		vread.push_back(Read(tmp_h, tmp_t));
	}

	std::vector<Read>::iterator itr;
	for(itr = vread.begin(); itr != vread.end(); itr++)
	{
		std::cout << "h: " << (*itr).h << " i: " << (*itr).t << std::endl;
	}

	std::ofstream os("out_simple_f.txt");
	if (!os)
	{
		std::cout << "Cannot open out_simple_f.txt." << std::endl;
		return;
	}

	for(itr = vread.begin(); itr != vread.end(); itr++)
	{
		os << (*itr).h << " " << (*itr).t << " ";
	}
	os << std::endl;

}

