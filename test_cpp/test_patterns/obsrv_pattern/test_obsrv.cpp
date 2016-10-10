/*
 * test_obsrv.cpp
 */

#include "test_obsrv.hpp"
#include "Observable.hpp"
#include "TestObserver.hpp"


void test_obsrv()
{
	Observable* observable = Observable::getInstance();
	TestObserver* tobserver = new TestObserver();
	observable->addObserver(*tobserver);
	for(int i = 0; i < 10; i++)
	{
		observable->testTrigger();
	}
}



