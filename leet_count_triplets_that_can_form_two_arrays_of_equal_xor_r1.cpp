/*
https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/?envType=daily-question&envId=2024-05-30
*/
#include <bits/stdc++.h>
using namespace std;

int countTriplets(vector<int>& arr) {

	int n = arr.size();
	int ans = 0;

	for (int i = 0; i < n; ++i) {
		int curr_xor = arr[i];
		for (int j = i + 1; j < n; ++j) {
			curr_xor ^= arr[j];
			if (curr_xor == 0) {
				ans += j - i;
			}
		}
	}

	return ans;
}

int main() {

	// vector<int> arr = {2, 3, 1, 6, 7};
	vector<int> arr = {1, 1, 1, 1, 1};
	cout << countTriplets(arr) << endl;
}