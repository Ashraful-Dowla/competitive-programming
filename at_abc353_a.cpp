/*
https://atcoder.jp/contests/abc353/tasks/abc353_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int ans = -1;
	for (int i = 1; i < n; ++i) {
		if (a[0] < a[i]) {
			ans = i + 1;
			break;
		}
	}
	cout << ans << endl;
}