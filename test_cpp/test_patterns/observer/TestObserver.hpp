/*
 * TestObserver.hpp
 *
 *  Created on: Jul 1, 2016
 *      Author: liberdaa
 */

#ifndef TESTOBSERVER_HPP_
#define TESTOBSERVER_HPP_

#include "Observer.hpp"

class TestObserver:public Observer {

	public:
		TestObserver();
		virtual ~TestObserver();

		void notify();
};

#endif /* TESTOBSERVER_HPP_ */
