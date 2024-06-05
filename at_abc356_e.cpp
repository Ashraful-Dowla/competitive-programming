/*
https://atcoder.jp/contests/abc356/tasks/abc356_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e6 + 10;
vector<ll> ct(N);

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		ct[x]++;
	}

	for (int i = 1; i < N; ++i) {
		ct[i] += ct[i - 1];
	}

	ll ans = 0;

	for (ll ai = 1; ai < N; ++ai) {

		ll p = ct[ai] - ct[ai - 1];

		ans += (p * (p - 1)) / 2;

		for (ll k = 1; (k + 1)* ai - 1 < N; ++k) {

			ll cnt = ct[(k + 1) * ai - 1] - ct[k * ai - 1];

			if (k == 1) {
				cnt -= p;
			}
			ans += cnt * p * k;
		}
	}

	cout << ans << endl;

}