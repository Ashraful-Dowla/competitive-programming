/*
https://atcoder.jp/contests/abc280/tasks/abc280_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	long long a[n], ans[n];

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		ans[i] = a[i];
	}

	for (int i = 1; i < n; ++i) {
		ans[i] = a[i] - a[i - 1];
	}

	for (int i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
}