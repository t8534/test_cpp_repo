/*
 * test_structf.cpp
 *
 */

// Format:
// The SPACE is delimiter.
//
//   Day  Hour Value
// ( 14   23   5.4 )
//
// { year 2015
//     { month jan ( 14 23 5.4 ) ( 15 20 8.2 ) ( 16 10 2 ) }
//     { month feb ( 9 12 3.8 ) ( 10 8 4.5 ) ( 14 5 2.4 ) }
// }
//
// { year 2016
//     { month apr ( 11 12 10.1 ) ( 19 9 20.2 ) ( 29 8 4 ) }
//     { month may ( 7 10 14.8 ) ( 17 18 28.5 ) ( 27 21 3.4 ) }
// }

#include <iostream>
#include <fstream>
#include "test_structf.hpp"

using namespace std;

istream& operator>>(istream& is, Reading& r)
{
	char ch1;
	if ( is>>ch1 && ch1 != '(' )
	{
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	char ch2;
	int d;
	int h;
	double t;
	is >> d >> h >> t >> ch2;
	if ( !is || ch2 != ')' )
	{
		cout << "Wrong reading." << endl;
		return is; // is it right, no unget ?
	}

	r.day = d;
	r.hour = h;
	r.temperature = t;

	return is;
}


istream& operator>>(istream& is, Month& m)
{
	char ch1;
	if ( is>>ch1 && ch1 != '{' )
	{
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	string month_marker;
	string mm;
	is >> month_marker >> mm;
	if (!is || month_marker != "month")
	{
		cout << "Wrong month marker." << endl;
		return is; // is it right, no unget ?
	}
	m.month = month_to_int(mm);

	Reading r;
	int duplicates = 0;
	int invalids = 0;
	while (is >> r)
	{
		if (is_valid(r))
		{
			if (m.day[r.day].hour[r.hour] != not_a_reading) ++duplicates;
			m.day[r.day].hour[r.hour] = r.temperature;
		}
		else
		{
			++invalids;
		}
	}
	if (invalids) cout << "Wrong reading in the month: " << invalids << endl;
	if (duplicates) cout << "Duplicates in the month: " << duplicates << endl;
	end_of_loop(is, '}', "Wrong end of month marker");

	return is;
}


void test_structf()
{
	ifstream is("struct_f.txt");
	if (!is)
	{
		cout << "Cannot open struct_f.txt." << endl;
		return;
	}




}


