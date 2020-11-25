/*my_deque.h
Author: Quinn Wai Wong
Email: qwong@wustl.edu
Purpose: declaring my_deque class
*/

#pragma once
#include <memory>

class my_deque {
private:
	
	int size;
	int initSize;
	int count;
	int rIndex;
	int lIndex;
public:
	int* array; //TODO: make sure this is right
	my_deque(int initial_size);
	my_deque(const my_deque& d);
	~my_deque();
	int get_used();
	int get_size();
	int get_lIndex();
	int get_rIndex();
	void push_back(int v);
	void push_front(int v);
	int pop_back();
	int pop_front();
	int* get_mem();
	int& operator[](const int i);
};
