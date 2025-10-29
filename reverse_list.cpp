#include "reverse_list.h"

MyList* reverseList(MyList* head) {
    if (!head || !head->next) return head;

    MyList* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

MyList* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;

    MyList* head = new MyList(values[0]);
    MyList* current = head;

    for (size_t i = 1; i < values.size(); i++) {
        current->next = new MyList(values[i]);
        current = current->next;
    }

    return head;
}

void printList(MyList* head) {
    MyList* current = head;
    while (current != nullptr) {
        cout << current->value;
        if (current->next != nullptr) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << " -> NULL" << endl;
}

void deleteList(MyList* head) {
    while (head != nullptr) {
        MyList* temp = head;
        head = head->next;
        delete temp;
    }
}