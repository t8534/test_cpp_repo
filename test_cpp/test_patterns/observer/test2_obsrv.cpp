//============================================================================
// Name        : test2_obsrv.cpp
//============================================================================

#include <iostream>
#include "Observable.hpp"
#include "Observer.hpp"
#include "TestObserver.hpp"

using namespace std;

int main() {
	cout << "Start" << endl;
	Observable* observable = Observable::getInstance();
	TestObserver* observer = new TestObserver();  //todo what about if you create not by new ?
	observable->addObserver(*observer);
	observable->trigger();
	cout << "Stop" << endl;
	return 0;
}
