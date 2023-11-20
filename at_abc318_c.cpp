/*
https://atcoder.jp/contests/abc318/tasks/abc318_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n, d;
	ll p;

	cin >> n >> d >> p;

	multiset<ll> ms;

	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		sum += x;
		ms.insert(x);
	}

	int t = 0;

	ll ans = sum;
	while (t < n) {

		t += d;
		sum += p;

		for (int i = 0; i < d && ms.size() > 0; ++i) {
			sum -= *(--ms.end());
			ms.erase(--ms.end());
		}

		ans = min(ans, sum);
	}

	cout << ans << endl;
}