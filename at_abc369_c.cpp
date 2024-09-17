/*
https://atcoder.jp/contests/abc369/tasks/abc369_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(ll n) {
	return (n * (n + 1)) / 2;
}

int main() {

	int n;
	cin >> n;

	vector<ll> v(n);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	ll ans = n;
	int pdx = 0;
	for (int i = 1; i < n - 1; ++i) {
		if (v[i] - v[i - 1] != v[i + 1] - v[i]) {
			ans += f(i - pdx);
			pdx = i;
		}
	}

	ans += f(n - 1 - pdx);
	cout << ans << endl;
	return 0;
}
