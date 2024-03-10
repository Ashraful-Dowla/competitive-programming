/*
https://atcoder.jp/contests/abc289/tasks/abc289_d
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 12;
const int M = 1e5 + 10;

int a[N], dp[M];
bool trap[M];
int n, m;

bool solve(int x) {

	if (x == 0) {
		return true;
	}
	if (dp[x] != -1) {
		return dp[x];
	}

	bool isPossible = false;
	for (int i = 0; i < n; ++i) {
		if (x >= a[i] && !trap[x - a[i]]) {
			isPossible |= solve(x - a[i]);
		}
	}

	return dp[x] = isPossible;
}

int main() {

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	cin >> m;
	for (int i = 0; i < m; ++i) {
		int b;
		cin >> b;
		trap[b] = true;
	}

	int x;
	cin >> x;

	for (int i = 0; i <= x; ++i) {
		dp[i] = -1;
	}

	cout << (solve(x) ? "Yes" : "No") << endl;
}