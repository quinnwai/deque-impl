// deque_assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once
#include <iostream>
#include <deque>
#include "my_deque.h"

using namespace std;

int main(int argc, char* argv[])
{
	my_deque* dqp1 = new my_deque(1);
	cout << dqp1 << endl;
	cout << dqp1 -> array << endl;
	dqp1->push_back(3);
	cout << dqp1 << endl;
	cout << dqp1->array << endl;

	return 0;
}
