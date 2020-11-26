// declare my_deque_iterator here
#pragma once
//#include "my_deque.h";

class my_deque;

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
	bool operator== (const my_deque_iterator compare_against) const;
	int* get_mem();
};