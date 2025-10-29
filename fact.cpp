#include "fact.h"

vector<int> fact(int n) {
    int temp = 1;
    vector<int> factorials;
    for (int i = 1; i <= n; i++) {
        temp *= i;
        factorials.push_back(temp);
    }
    return factorials;
}
