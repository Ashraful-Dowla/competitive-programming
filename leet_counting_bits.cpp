/*
https://leetcode.com/problems/counting-bits/description/
*/
#include <bits/stdc++.h>
using namespace std;

int solve(int n) {

	int cnt = 0;
	while (n) {
		if (n & 1) cnt++;
		n >>= 1;
	}

	return cnt;
}

vector<int> countBits(int n) {

	vector<int> ans;
	for (int i = 0; i <= n; ++i) {
		ans.push_back(solve(i));
	}

	return ans;
}

int main() {

	int n = 10;

	auto res = countBits(n);

	for (int x : res) {
		cout << x << " ";
	}
}