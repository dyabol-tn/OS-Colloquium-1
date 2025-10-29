#include "delete_duplicates.h"

vector<int> deleteDuplicates(const vector<int>& arr) {
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
