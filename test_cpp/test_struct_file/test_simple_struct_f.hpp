/*
 * test_simple_struct_f.hpp
 */

#ifndef TEST_SIMPLE_STRUCT_F_HPP_
#define TEST_SIMPLE_STRUCT_F_HPP_

void test_simple_struct_f();

class Read {

public:
	Read();
	Read(int v_h, int v_t): h(v_h), t(v_t) {};

	int h;
	int t;

};



#endif /* TEST_SIMPLE_STRUCT_F_HPP_ */
