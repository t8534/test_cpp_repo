/*
 * Observable.hpp
 */

#ifndef OBSRV_PATTERN_OBSERVABLE_HPP_
#define OBSRV_PATTERN_OBSERVABLE_HPP_

#include <set>
#include "Observer.hpp"


class Observable
{

public:
	Observable();
	virtual ~Observable();

	static Observable* getInstance();

	void addObserver(Observer& o);
	void removeObserver(Observer& o);

	void notifyObservers();

	// For tests only
	void testTrigger();

private:
	static Observable* instance;
	std::set<Observer*> observers;

};

#endif /* OBSRV_PATTERN_OBSERVABLE_HPP_ */
