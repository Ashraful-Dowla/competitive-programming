/*
https://atcoder.jp/contests/abc281/tasks/abc281_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n;
	ll t;
	cin >> n >> t;

	vector<ll> v(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		ll x;
		cin >> x;
		v[i] = v[i - 1] + x;
	}

	t %= v[n];

	int idx = lower_bound(v.begin(), v.end(), t) - v.begin();
	if (idx == 0) {
		cout << n << " " << 0 << endl;
	}
	else {
		cout << idx << " " << t - v[idx - 1] << endl;
	}
}