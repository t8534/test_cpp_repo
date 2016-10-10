//============================================================================
// Name        : CmdPattern.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "obsrv_pattern\test_obsrv.hpp"

using namespace std;

// Command Pattern.
// http://www.sourcetricks.com/2011/06/command-pattern.html#.V3T34Y38Jiw


int main() {

	cout << "Start" << endl;
	test_obsrv();  // Observer pattern.
	cout << "Stop" << endl;

	return 0;
}
