/*
 * Observer.hpp
 */

#ifndef OBSRV_PATTERN_OBSERVER_HPP_
#define OBSRV_PATTERN_OBSERVER_HPP_

class Observer
{

public:
	Observer();
	virtual ~Observer();

	virtual void notify() = 0;

};

#endif /* OBSRV_PATTERN_OBSERVER_HPP_ */
