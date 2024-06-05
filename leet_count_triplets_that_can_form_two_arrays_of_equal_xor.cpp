/*
https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/?envType=daily-question&envId=2024-05-30
*/
#include <bits/stdc++.h>
using namespace std;

int countTriplets(vector<int>& arr) {

	int n = arr.size();
	vector<int> pf(n + 1, 0);

	for (int i = 0; i < n; ++i) {
		pf[i + 1] = pf[i] ^ arr[i];
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			for (int k = j; k <= n; ++k) {
				int a = pf[j - 1] ^ pf[i - 1];
				int b = pf[k] ^ pf[j - 1];

				if (a == b) {
					ans++;
				}
			}
		}
	}

	return ans;
}

int main() {

	vector<int> arr = {2, 3, 1, 6, 7};
	// vector<int> arr = {1, 1, 1, 1, 1};
	cout << countTriplets(arr) << endl;
}