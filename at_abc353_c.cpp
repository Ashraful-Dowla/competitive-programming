/*
https://atcoder.jp/contests/abc353/tasks/abc353_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll M = 1e8;

int main() {

	int n;
	cin >> n;

	vector<ll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	int r = n;
	ll cnt = 0;
	for (int i = 0; i < n; ++i) {
		r = max(r, i + 1);
		while (r - 1 > i && a[r - 1] + a[i] >= M) {
			r--;
		}
		cnt += n - r;
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += a[i] * (n - 1);
	}

	ans -= cnt * M;
	cout << ans << endl;
}