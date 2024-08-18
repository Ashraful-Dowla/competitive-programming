/*
https://atcoder.jp/contests/abc367/tasks/abc367_e
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int up[N][70];

int main() {

	int n;
	long long k;
	cin >> n >> k;

	for (int i = 1; i <= n; ++i) {
		cin >> up[i][0];
	}

	for (int j = 1; j <= 60; ++j) {
		for (int i = 1; i <= n; ++i) {
			up[i][j] = up[up[i][j - 1]][j - 1];
		}
	}

	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; ++i) {
		int u = i;
		for (int j = 60; j >= 0; --j) {
			if (k & (1LL << j)) {
				u = up[u][j];
			}
		}
		cout << a[u] << " ";
	}
	cout << endl;
}