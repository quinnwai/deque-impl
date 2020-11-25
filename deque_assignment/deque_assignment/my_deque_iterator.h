#pragma once
#include "my_deque.h"
// declare my_deque_iterator here

class my_deque_iterator {
private:
	int* curr;
	my_deque* deque;
public:
	my_deque_iterator(int* ptr, my_deque* d);
	my_deque_iterator operator+ (int n);
	my_deque_iterator& operator+= (int n);
	int& operator* ();
	bool operator< (const my_deque_iterator compare_against) const;
	bool operator== (const my_deque_iterator) const;
	int* get_mem();
	//my_deque_iterator begin();
	//my_deque_iterator end();
};