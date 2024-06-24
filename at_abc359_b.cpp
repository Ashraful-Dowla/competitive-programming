/*
https://atcoder.jp/contests/abc359/tasks/abc359_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> v(2 * n);

	for (int i = 0; i < 2 * n; ++i) {
		cin >> v[i];
	}

	int ans = 0;
	for (int i = 0; i + 2 < 2 * n; ++i) {
		if (v[i] == v[i + 2]) {
			ans++;
		}
	}

	cout << ans << endl;
}