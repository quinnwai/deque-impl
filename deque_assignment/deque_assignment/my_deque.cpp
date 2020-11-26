// define my_deque here

#pragma once
#include "my_deque.h"
#include "my_deque_iterator.h"

my_deque::my_deque(int initial_size) : size(0), initSize(0), lIndex(0), rIndex(0) {
	array = new int[initial_size];

	count = 0;

	if (initial_size > 0) {
		size = initial_size;
		initSize = initial_size;
		lIndex = (initial_size / 2) - 1;
		rIndex = initial_size / 2;
	}
}

my_deque::my_deque(const my_deque& d) : size(0), initSize(0), count(0), lIndex(0), rIndex(0) {
	array = new int[d.size];

	if (d.size > 0) {
		size = d.size;
		initSize = d.initSize;
		count = d.count;
		lIndex = d.lIndex;
		rIndex = d.rIndex;

		for (int i = 0; i < d.size; ++i) {
			array[i] = d.array[i];
		}
	}
}

my_deque::~my_deque() {
	delete[] array;

	//TODO: make sure delete is for both pointers and contents
}

int my_deque::get_used() {
	return count;
}

int my_deque::get_size() {
	return size;
}

int my_deque::get_lIndex() {
	return lIndex;
}

int my_deque::get_rIndex() {
	return rIndex;
}

void my_deque::push_back(int v) {
	//check that there's space 
	bool outOfBounds = rIndex >= size;
	bool tooManyElems = count + 1 > size / 2;

	//check 2 options: resize and recenter, just recenter, or just resize
	if (outOfBounds && tooManyElems) { //resize and recenter
		//resize
		my_deque* d2 = new my_deque(size * 2);

		int mid = ((lIndex + rIndex) / 2);
		//TODO: why mid + 1 and + 2, but at least still storing correctly...
		for (int i = mid + 1; i > lIndex; --i) { //fill left side of array
			d2->array[d2->lIndex] = array[i];
			--(d2->lIndex);
			++(d2->count);
		}
		for (int i = mid + 2; i < rIndex; ++i) { //fill right side of array including middle value
			d2->array[d2->rIndex] = array[i];
			++(d2->rIndex);
			++(d2->count);
		}

		//temp for swap
		int* oldArr = array;

		//copy all fields from array to array
		array = d2->array;
		size = d2->size;
		lIndex = d2->lIndex; //TODO: why does this work (might cause a problem later on w/ 1 empty spot at lIndex+1)
		rIndex = d2->rIndex; //TODO: why does this work (same possible problem)
		count = d2->count;

		//move d2 into array's old position for destruction
		d2->array = oldArr;
	}
	else if (outOfBounds) { //recenter only

		int mid = ((lIndex + rIndex) / 2);
		int midArr = size / 2;
		for (int i = mid; i > lIndex; --i) { //fill left side of array
			array[midArr] = array[i];
			array[i] = -1; //TODO: choose random -1 as placeholder for array?
			--midArr;
		}
		/*if (count != 0) {
			lIndex = midArr; 
		}
		else {*/
			lIndex = midArr - 1; //TODO: dunno why - 1 used here
		//}
		
		midArr = size / 2;
		for (int i = mid + 1; i < rIndex; ++i) { //fill right side of array including middle value
			array[midArr] = array[i];
			array[i] = -1;  //TODO: choose random -1 as placeholder for array?
			++midArr;
		}
		rIndex = midArr; //TODO: dunno why no - 1 here

		//TODO: need to delete elements?
	}

	//add value v at rIndex and increment count
	array[rIndex] = v;
	++rIndex;
	++count;
}

void my_deque::push_front(int v) {
	bool outOfBounds = lIndex <= -1;
	bool tooManyElems = count + 1 > size / 2;

	//check 2 options: resize and recenter, just recenter, or just resize
	if (outOfBounds && tooManyElems) { //resize and recenter
		//resize
		my_deque* d2 = new my_deque(size * 2);

		int mid = ((lIndex + rIndex) / 2);
		for (int i = mid; i > lIndex; --i) { //fill left side of array
			d2->array[d2->lIndex] = array[i];
			--(d2->lIndex);
			++(d2->count);
		}
		for (int i = mid + 1; i < rIndex; ++i) { //fill right side of array including middle value
			d2->array[d2->rIndex] = array[i];
			++(d2->rIndex);
			++(d2->count);
		}

		//temp for swap
		int* oldArr = array;

		//copy all fields from array to array
		array = d2->array;
		size = d2->size;
		lIndex = d2->lIndex; //TODO: why does this work (might cause a problem later on w/ 1 empty spot at lIndex+1)
		rIndex = d2->rIndex; //TODO: why does this work (same possible problem)
		count = d2->count;

		//move d2 into array's old position for destruction
		d2->array = oldArr;
	}
	else if (outOfBounds) { //recenter only


		//fill left side of array including middle value
		int mid = ((lIndex + rIndex) / 2);
		int midArr = size / 2;
		for (int i = mid; i > lIndex; --i) {
			array[midArr] = array[i];
			array[i] = -1; //TODO: choose random -1 as deleting from array?
			--midArr;
		}
		lIndex = midArr; //TODO: dunno why no + 1 used here

		//fill right side of array
		midArr = size / 2;
		for (int i = mid + 1; i < rIndex; ++i) {
			array[midArr] = array[i];
			array[i] = -1; //TODO: choose random -1 as "deleting" from array?
			++midArr;
		}
		if (count != 0) {
			rIndex = midArr + 1; //TODO: dunno why + 1 here
		}
		else {
			rIndex = midArr; //weird to have this here only
		}
		
	}

	//add value v at lIndex and increment count
	array[lIndex] = v;
	--lIndex;
	++count;
}

int my_deque::pop_back() {
	if (count == 0) { //TODO: seems wrong
		throw std::exception("");
	}

	//resize if array is smaller than an 1/8 of the total array size
	if (count - 1 < size / 8 && size != initSize) {
		my_deque* d2 = new my_deque(size / 2);

		int mid = ((lIndex + rIndex) / 2);
		for (int i = mid; i > lIndex; --i) { //fill left side of array
			d2->array[d2->lIndex] = array[i];
			--(d2->lIndex);
			++(d2->count);
		}
		for (int i = mid + 1; i < rIndex; ++i) { //fill right side of array including middle value
			d2->array[d2->rIndex] = array[i];
			++(d2->rIndex);
			++(d2->count);
		}

		//temp for swap
		int* oldArr = array;

		//copy all fields from array to array
		array = d2->array;
		size = d2->size;
		lIndex = d2->lIndex; 
		rIndex = d2->rIndex;
		count = d2->count;

		//move d2 into array's old position for destruction
		d2->array = oldArr;
	}

	//update the proper fields and return popped value
	--rIndex;
	--count;
	return array[rIndex];
}

int my_deque::pop_front() {
	if (count == 0) { //TODO: seems wrong
		throw std::exception("");
	}

	//resize if array is smaller than an 1/8 of the total array size
	if (count - 1 < size / 8 && size != initSize) {
		my_deque* d2 = new my_deque(size / 2);

		int mid = ((lIndex + rIndex) / 2);
		//TODO: why + 1?
		for (int i = mid + 1; i > lIndex; --i) { //fill left side of array
			d2->array[d2->lIndex] = array[i];
			--(d2->lIndex);
			++(d2->count);
		}
		for (int i = mid + 2; i < rIndex; ++i) { //fill right side of array including middle value
			d2->array[d2->rIndex] = array[i];
			++(d2->rIndex);
			++(d2->count);
		}

		//temp for swap
		int* oldArr = array;

		//copy all fields from array to array
		array = d2->array;
		size = d2->size;
		lIndex = d2->lIndex; 
		rIndex = d2->rIndex; 
		count = d2->count;

		//move d2 into array's old position for destruction
		d2->array = oldArr;
	}

	//update the proper fields and return popped value
	++lIndex;
	--count;
	return array[lIndex];
}

int* my_deque::get_mem() {
	return array;
}

int& my_deque::operator[](const int i) {
	int index = lIndex + i + 1;
	if (index >= rIndex){
		throw std::exception("");
	}
	return array[index];
}

my_deque_iterator my_deque::begin() { //TODO: uncomment this
	if (count == 0) {
		return *(new my_deque_iterator(array + rIndex, this));
	}
	return *(new my_deque_iterator(array + lIndex + 1, this));

}

my_deque_iterator my_deque::end() {
	return *(new my_deque_iterator(array + rIndex, this));
}