/*
https://leetcode.com/problems/grumpy-bookstore-owner/description/?envType=daily-question&envId=2024-06-21
*/
#include <bits/stdc++.h>
using namespace std;

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

	int n = customers.size();

	vector<int> pf(n + 1, 0), pfz(n + 1, 0);

	for (int i = 1; i <= n; ++i) {

		pf[i] = pf[i - 1] + customers[i - 1];

		if (grumpy[i - 1]) {
			pfz[i] = pfz[i - 1];
		}
		else {
			pfz[i] = pfz[i - 1] + customers[i - 1];
		}
	}

	int ans = 0;

	for (int i = minutes; i <= n; ++i) {
		ans = max(ans, pf[i] - pf[i - minutes] + pfz[n] - pfz[i] + pfz[i - minutes]);
	}

	return ans;
}

int main() {

	vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
	vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
	int minutes = 3;

	cout << maxSatisfied(customers, grumpy, minutes) << endl;
}