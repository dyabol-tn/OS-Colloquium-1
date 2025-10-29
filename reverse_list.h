#pragma once

#include <iostream>
#include <vector>
#include "my_list.h"

using namespace std;

MyList* reverseList(MyList* head);
MyList* createList(const vector<int>& values);
void printList(MyList* head);
void deleteList(MyList* head);