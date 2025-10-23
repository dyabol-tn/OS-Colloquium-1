#include "Colloquium OS 1.h"
#include <vector>
#include <set>

using namespace std;

vector<int> fact(int n) {
	int temp = 1;
	vector<int>factorials;
	for (int i = 1; i <= n; i++) {
		temp *= i;
		factorials.push_back(temp);
	}
	return factorials;
}

vector<int> deleteDuplicates(vector<int> arr) {
	vector<int> result;

	for (int i = 0; i < arr.size(); i++) {
		bool isDuplicate = false;

		for (int j = 0; j < i; j++) {
			if (arr[i] == arr[j]) {
				isDuplicate = true;
				break;
			}
		}
		if (!isDuplicate) {
			result.push_back(arr[i]);
		}
	}
	return result;
}

int main()
{
	int n;
	cin >> n;
	vector <int> firstTask;
	vector<int> secondTask = { 4, 65, 44, 4, 1, 8, 5, 1 };
	firstTask = fact(n);

	for (int i = 0; i < n; i++) {
		cout << firstTask[i] << " ";
	}

	cout << endl;

	vector<int> secondTaskResult = deleteDuplicates(secondTask);

	for (int i = 0; i < secondTaskResult.size(); i++) {
		cout << secondTaskResult[i] << " ";
	}
	return 0;
}
