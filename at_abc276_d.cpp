/*
https://atcoder.jp/contests/abc276/tasks/abc276_d
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> v(n);
	int gcd = 0;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		gcd = __gcd(gcd, v[i]);
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {

		v[i] /= gcd;
		while (v[i] % 2 == 0) {
			v[i] /= 2;
			ans++;
		}

		int three = 0;
		while (v[i] % 3 == 0) {
			v[i] /= 3;
			ans++;
		}

		if (v[i] != 1) {
			cout << -1 << endl;
			return 0;
		}
	}

	cout << ans << endl;
}