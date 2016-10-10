/*
 * Observable.hpp
 *
 *  Created on: Jul 1, 2016
 *      Author: liberdaa
 */

#ifndef OBSERVABLE_HPP_
#define OBSERVABLE_HPP_

#include <set>
#include "Observer.hpp"

class Observable {

	public:
		Observable();
		virtual ~Observable();

		static Observable* getInstance();

		void addObserver(Observer&);
		void removeObserver(Observer&);

		// For tests
		void trigger();

	private:
		static Observable* instance;
		std::set<Observer*> observers;

};

#endif /* OBSERVABLE_HPP_ */
