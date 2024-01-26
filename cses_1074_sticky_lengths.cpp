/*
https://cses.fi/problemset/task/1074/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

ll v[N];

ll solve(int n, ll k) {

	ll res = 0;
	for (int i = 0; i < n; ++i) {
		res += abs(v[i] - k);
	}

	return res;
}

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	ll ans = 1e18;

	ll lo = 1, hi = 1e12;

	while (lo <= hi) {

		ll mid1 = lo + (hi - lo) / 3;
		ll mid2 = hi - (hi - lo) / 3;

		ll res1 = solve(n, mid1);
		ll res2 = solve(n, mid2);

		if (res1 < res2) {
			hi = mid2 - 1;
		}
		else {
			lo = mid1 + 1;
		}
	}

	cout << solve(n, hi) << endl;
}