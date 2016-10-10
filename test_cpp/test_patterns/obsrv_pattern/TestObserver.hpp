/*
 * TestObserver.h
 */

#ifndef OBSRV_PATTERN_TESTOBSERVER_HPP_
#define OBSRV_PATTERN_TESTOBSERVER_HPP_

#include "Observer.hpp"

class TestObserver: public Observer
{

public:
	TestObserver();
	virtual ~TestObserver();

	void notify();

};

#endif /* OBSRV_PATTERN_TESTOBSERVER_HPP_ */
