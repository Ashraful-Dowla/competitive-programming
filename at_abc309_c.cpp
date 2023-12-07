/*
https://atcoder.jp/contests/abc309/tasks/abc309_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3e5 + 10;
ll a[N], b[N], k;
int n;

ll solve(ll d) {

	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] >= d) {
			sum += b[i];
		}
	}

	return sum;
}

int main() {

	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
	}

	ll lo = 1, hi = 1e9 + 5, ans = 1e10;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;

		if (solve(mid) <= k) {
			ans = min(ans, mid);
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}

	cout << ans << endl;
}