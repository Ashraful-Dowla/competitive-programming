/*
https://atcoder.jp/contests/abc357/tasks/abc357_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<int> h(n);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (m >= h[i]) {
			m -= h[i];
			ans++;
		}
		else break;
	}

	cout << ans << endl;
}