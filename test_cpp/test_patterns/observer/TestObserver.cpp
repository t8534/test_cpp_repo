/*
 * TestObserver.cpp
 *
 *  Created on: Jul 1, 2016
 *      Author: liberdaa
 */

#include <iostream>
#include "TestObserver.hpp"


TestObserver::TestObserver() {
}

TestObserver::~TestObserver() {
}

void TestObserver::notify() {
	std::cout << "TestObserver was notified" << std::endl;
}
