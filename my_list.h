#pragma once
#include <iostream>

using namespace std;

struct MyList {
	int value;
	MyList* next;
	MyList(int n) : value(n), next(nullptr) {};
};
