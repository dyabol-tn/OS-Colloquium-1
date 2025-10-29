#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
#include "my_list.h"

using namespace std;

struct FactorialData {
    int n;
    vector<int> result;
};

struct DuplicatesData {
    vector<int> input;
    vector<int> output;
};

struct ListData {
    vector<int> input;
    MyList* reversedList;
};

DWORD WINAPI FactorialThread(LPVOID lpParam);
DWORD WINAPI DuplicatesThread(LPVOID lpParam);
DWORD WINAPI ReverseListThread(LPVOID lpParam);