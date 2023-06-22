/*
https://leetcode.com/problems/candy/description/
*/
#include <bits/stdc++.h>
using namespace std;


int candy(vector<int>& ratings) {

	int n = ratings.size();
	vector<int> left(n, 1), right(n, 1);

	for (int i = 1; i < n; ++i) {
		if (ratings[i] > ratings[i - 1]) {
			left[i] = left[i - 1] + 1;
		}
	}

	for (int i = n - 2; i >= 0; --i) {
		if (ratings[i] > ratings[i + 1]) {
			right[i] = right[i + 1] + 1;
		}
	}

	int res = 0;
	for (int i = 0; i < n; ++i) {
		res += max(left[i], right[i]);
	}

	return res;
}

int main() {

	// vector<int> ratings = {1, 0, 2};
	// vector<int> ratings = {1, 2, 2};
	// vector<int> ratings = {1, 3, 3, 4};
	// vector<int> ratings = {1, 2, 87, 87, 87, 2, 1};
	// vector<int> ratings = {1, 3, 2, 2, 1};
	cout << candy(ratings);
}