/*
https://leetcode.com/problems/counting-bits/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> countBits(int n) {

	vector<int> ans(n + 1);
	for (int i = 0; i <= n; ++i) {
		ans[i] = ans[i / 2] + i % 2;
	}

	return ans;
}

int main() {

	int n = 5;

	auto res = countBits(n);

	for (int x : res) {
		cout << x << " ";
	}
}