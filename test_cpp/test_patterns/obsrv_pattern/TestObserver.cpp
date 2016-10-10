/*
 * TestObserver.cpp
 */

#include <iostream>
#include "TestObserver.hpp"

TestObserver::TestObserver()
{
}

TestObserver::~TestObserver()
{
}

void TestObserver::notify()
{
	std::cout << "TestObserver notified." << std::endl;
}

