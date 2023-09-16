/*
https://leetcode.com/problems/lexicographical-numbers/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

void dfs(int sum, int n) {

	if (sum >= n) return;

	for (int i = 0; i < 10; ++i) {
		if (sum * 10 + i <= n) {
			ans.push_back(sum * 10 + i);
			dfs(sum * 10 + i, n);
		}
	}
}


vector<int> lexicalOrder(int n) {

	int sum = 0;
	for (int i = 1; i < 10; ++i) {
		if (sum * 10 + i <= n) {
			ans.push_back(sum * 10 + i);
			dfs(sum * 10 + i, n);
		}
	}

	return ans;
}

int main() {

	int n = 13;
	// int n = 2;
	// int n = 100;
	auto v = lexicalOrder(n);

	for (int x : v) {
		cout << x << endl;
	}
}