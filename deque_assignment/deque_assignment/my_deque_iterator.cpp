// define my_deque_iterator here
#include "my_deque_iterator.h"

my_deque_iterator::my_deque_iterator(int* ptr, my_deque* d) : curr(ptr), deque(d) {
	//if invalid ptr, set to nullptr
	if (ptr < deque->get_mem()) { //TODO: make sure not off by one for end
		curr = nullptr;
	}
}

my_deque_iterator my_deque_iterator::operator+ (int n) {
	if (n < 0) {
		return *this;
	}
	
	return *(new my_deque_iterator(curr + n, deque));
}

my_deque_iterator& my_deque_iterator::operator+= (int n) {
	return *this;
}

int& my_deque_iterator::operator* () {
	//TODO: placeholder code
	int a = 0;
	return a;
}

bool my_deque_iterator::operator< (const my_deque_iterator compare_against) const {
	return true;
}

bool my_deque_iterator::operator== (const my_deque_iterator) const {
	return true;
}

int* my_deque_iterator::get_mem() {
	return curr;
}