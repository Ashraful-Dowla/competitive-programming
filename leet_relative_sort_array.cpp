/*
https://leetcode.com/problems/relative-sort-array/description/?envType=daily-question&envId=2024-06-11
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

	int n = arr1.size();
	int m = arr2.size();

	int cnt[1005] = {0};

	for (int x : arr1) {
		cnt[x]++;
	}

	vector<int> ans;
	for (int x : arr2) {
		while (cnt[x] > 0) {
			ans.push_back(x);
			cnt[x]--;
		}
	}

	for (int i = 0; i <= 1000; ++i) {
		while (cnt[i] > 0) {
			ans.push_back(i);
			cnt[i]--;
		}
	}

	return ans;
}

int main() {

	vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
	vector<int> arr2 = {2, 1, 4, 3, 9, 6};


	auto res = relativeSortArray(arr1, arr2);

	for (int x : res) {
		cout << x << " ";
	}
	cout << endl;
}