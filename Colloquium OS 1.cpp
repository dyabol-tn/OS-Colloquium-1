#include "Colloquium OS 1.h"
#include <vector>
#include <windows.h>
#include <iostream>
#include "my_list.h"
#include "reverse_list.h"

using namespace std;

DWORD WINAPI FactorialThread(LPVOID lpParam) {
    FactorialData* data = (FactorialData*)lpParam;
    int temp = 1;
    for (int i = 1; i <= data->n; i++) {
        temp *= i;
        data->result.push_back(temp);
    }
    return 0;
}

DWORD WINAPI DuplicatesThread(LPVOID lpParam) {
    DuplicatesData* data = (DuplicatesData*)lpParam;
    vector<int> result;

    for (int i = 0; i < data->input.size(); i++) {
        bool isDuplicate = false;
        for (int j = 0; j < i; j++) {
            if (data->input[i] == data->input[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            result.push_back(data->input[i]);
        }
    }
    data->output = result;
    return 0;
}

DWORD WINAPI ReverseListThread(LPVOID lpParam) {
    ListData* data = (ListData*)lpParam;
    MyList* list = createList(data->input);
    data->reversedList = reverseList(list);
    return 0;
}

vector<int> inputArrayWithSize(const string& prompt) {
    vector<int> result;
    int size;

    cout << prompt;
    cin >> size;

    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        int element;
        cin >> element;
        result.push_back(element);
    }

    return result;
}

int main() {
    int n;
    cout << "Enter n for factorials: ";
    cin >> n;

    FactorialData factorialData;
    factorialData.n = n;

    HANDLE hFactorialThread;
    DWORD factorialThreadID;
    hFactorialThread = CreateThread(NULL, 0, FactorialThread, &factorialData, 0, &factorialThreadID);

    if (hFactorialThread == NULL) {
        cerr << "Error creating factorial thread" << endl;
        return 1;
    }

    WaitForSingleObject(hFactorialThread, INFINITE);
    CloseHandle(hFactorialThread);

    cout << "Factorials: ";
    for (int i = 0; i < factorialData.result.size(); i++) {
        cout << factorialData.result[i] << " ";
    }
    cout << endl;

    DuplicatesData duplicatesData;

    duplicatesData.input = inputArrayWithSize("Enter the number of elements for duplicates removal: ");

    HANDLE hDuplicatesThread;
    DWORD duplicatesThreadID;
    hDuplicatesThread = CreateThread(NULL, 0, DuplicatesThread, &duplicatesData, 0, &duplicatesThreadID);

    if (hDuplicatesThread == NULL) {
        cerr << "Error creating duplicates thread" << endl;
        return 1;
    }

    WaitForSingleObject(hDuplicatesThread, INFINITE);
    CloseHandle(hDuplicatesThread);

    cout << "Without duplicates: ";
    for (int i = 0; i < duplicatesData.output.size(); i++) {
        cout << duplicatesData.output[i] << " ";
    }
    cout << endl;

    ListData listData;
    listData.input = inputArrayWithSize("Enter the number of elements for list reversal: ");

    HANDLE hReverseListThread;
    DWORD reverseListThreadID;
    hReverseListThread = CreateThread(NULL, 0, ReverseListThread, &listData, 0, &reverseListThreadID);

    if (hReverseListThread == NULL) {
        cerr << "Error creating reverse list thread" << endl;
        return 1;
    }

    WaitForSingleObject(hReverseListThread, INFINITE);
    CloseHandle(hReverseListThread);

    cout << "Reversed list: ";
    printList(listData.reversedList);

    deleteList(listData.reversedList);

    cout << "\nAll threads completed successfully!" << endl;

    return 0;
}