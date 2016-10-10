/*
 * test_structf.hpp
 */

#ifndef TEST_STRUCTF_HPP_
#define TEST_STRUCTF_HPP_

#include <vector>
#include <string>

using namespace std;



class Reading
{

public:
	Reading();
	Reading(int d, int h, double t) : day(d), hour(h), temperature(t) {};

	int day;
	int hour;
	double temperature;

};

istream& operator>>(istream& is, Reading& r);


class Month
{
public:
	string month;
	vector<Reading> day;
};

istream& operator>>(istream& is, Month& m);


class Year
{
public:
	int year ;
	vector<Month> mread;
};

void test_structf();


#endif /* TEST_STRUCTF_HPP_ */
