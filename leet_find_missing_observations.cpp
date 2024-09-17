/*
https://leetcode.com/problems/find-missing-observations/description/?envType=daily-question&envId=2024-09-05
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> missingRolls(vector<int>& rolls, int mean, int n) {

	int m = rolls.size();
	int rolls_sum = accumulate(rolls.begin(), rolls.end(), 0);
	int total = mean * (m + n);
	int res = total - rolls_sum;

	if (res > 6 * n || res < n) {
		return {};
	}

	int avg = res / n;
	int rem = res % n;

	vector<int> ans(n, avg);
	for (int i = 0; i < rem; ++i) {
		ans[i]++;
	}

	return ans;
}

int main() {

	// vector<int> rolls = {3, 2, 4, 3};
	// int mean = 4;
	// int n = 2;

	// vector<int> rolls = {1, 5, 6};
	// int mean = 3;
	// int n = 4;

	vector<int> rolls = {4, 5, 6, 2, 3, 6, 5, 4, 6, 4, 5, 1, 6, 3, 1, 4, 5, 5, 3, 2, 3, 5, 3, 2, 1, 5, 4, 3, 5, 1, 5};
	int mean = 4;
	int n = 40;

	auto res = missingRolls(rolls, mean, n);

	for (int x : res) {
		cout << x << " ";
	}
	cout << endl;
}