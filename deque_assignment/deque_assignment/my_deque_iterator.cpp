// define my_deque_iterator here
#pragma once
#include "my_deque.h"
#include "my_deque_iterator.h"

my_deque_iterator::my_deque_iterator(int* ptr, my_deque* d) : curr(ptr), deque(d) {
	//if invalid ptr, set to nullptr
	if (ptr < d->get_mem() + d->get_lIndex() || ptr > d->get_mem() + d->get_rIndex()) { //TODO: make sure not off by one for end
		curr = (int*)nullptr;
	}
}

my_deque_iterator my_deque_iterator::operator+ (int n) {
	if (n < 0) {
		return *(new my_deque_iterator((int*)nullptr, deque));
	}
	return *(new my_deque_iterator(curr + n, deque));
}

my_deque_iterator& my_deque_iterator::operator+= (int n) {
	if (n < 0) {
		curr = (int*)nullptr;
		return *this;
	}
	curr = curr + n;
	return *this;
}

int& my_deque_iterator::operator* () {
	if (curr == (int*)nullptr || curr >= deque->get_mem() + deque->get_rIndex()) {
		throw std::exception("");
	}
	return *curr;
}

bool my_deque_iterator::operator< (const my_deque_iterator compare_against) const {
	if (this->curr == (int*)nullptr || compare_against.curr == (int*)nullptr || !(this->deque == compare_against.deque)) {
		throw std::exception("");
	}
	return this->curr < compare_against.curr;
}

bool my_deque_iterator::operator== (const my_deque_iterator compare_against) const {
	return (this->deque == compare_against.deque) && this->curr == compare_against.curr;
}

int* my_deque_iterator::get_mem() {
	return curr;
}
