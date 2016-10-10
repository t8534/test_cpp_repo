/*
 * Observable.cpp
 */

#include "Observable.hpp"


Observable* Observable::instance = NULL;

Observable::Observable()
{
}

Observable::~Observable()
{
}

Observable* Observable::getInstance()
{
	if (instance == NULL)
	{
		instance = new Observable();
	}
	return instance;
}

void Observable::addObserver(Observer& o)
{
	observers.insert(&o);
}

void Observable::removeObserver(Observer& o)
{
	observers.erase(&o);
}

void Observable::notifyObservers()
{
	std::set<Observer*>::iterator itr;
	for(itr = observers.begin(); itr != observers.end(); itr++)
	{
		(*itr)->notify();
	}
}

// For tests only
void Observable::testTrigger()
{
	notifyObservers();
}

