// deque_assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once
#include <iostream>
#include <deque>
#include <memory>
#include "my_deque.h"

using namespace std;

int main(int argc, char* argv[])
{
	auto dqp1 = make_shared<my_deque>(4);
	cout << "dqp1: " << dqp1 << endl;
	dqp1->push_back(1);
	dqp1->push_back(2);
	dqp1->push_back(3);
	return 0;
}
