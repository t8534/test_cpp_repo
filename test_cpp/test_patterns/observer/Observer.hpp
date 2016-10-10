/*
 * Observer.hpp
 *
 *  Created on: Jul 1, 2016
 *      Author: liberdaa
 */

#ifndef OBSERVER_HPP_
#define OBSERVER_HPP_

class Observer {
	public:
		Observer();
		virtual ~Observer();

		virtual void notify() = 0;
};

#endif /* OBSERVER_HPP_ */
