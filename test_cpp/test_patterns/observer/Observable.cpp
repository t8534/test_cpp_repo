/*
 * Observable.cpp
 *
 *  Created on: Jul 1, 2016
 *      Author: liberdaa
 */

#include "Observable.hpp"


Observable* Observable::instance = NULL;

Observable::Observable() {
}

Observable::~Observable() {
}

Observable* Observable::getInstance() {
	if (instance == NULL)
	{
		instance = new Observable();
	}
	return instance;
}

void Observable::addObserver(Observer& o) {
	observers.insert(&o);
}

void Observable::removeObserver(Observer& o) {
	observers.erase(&o);
}

// For tests
void Observable::trigger() {
	std::set<Observer*>::iterator itr;
	for(itr = observers.begin(); itr != observers.end(); itr++ ) {
		(*itr)->notify();
	}
}
