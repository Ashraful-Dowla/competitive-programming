/*
https://atcoder.jp/contests/abc294/tasks/abc294_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	int a[n + 1], b[m + 1];

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	a[n] = INT_MAX;

	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	b[m] = INT_MAX;

	int ai[n], bi[m];

	for (int i = 0, j = 0, k = 1; k <= n + m; ++k) {
		if (a[i] < b[j]) {
			ai[i++] = k;
		}
		else {
			bi[j++] = k;
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << ai[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < m; ++i) {
		cout << bi[i] << " ";
	}
	cout << endl;
}