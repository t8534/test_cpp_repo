/*
 * Vect.hpp
 */

#ifndef VECT_HPP_
#define VECT_HPP_

class Vect {

public:
	Vect();
	Vect(unsigned char sz):len(sz), buff(new unsigned char[len]) {};
	virtual ~Vect();

	int size();
	void set(unsigned char);
	unsigned char get();

private:
	int len;
	unsigned char* buff;
};

#endif /* VECT_HPP_ */
