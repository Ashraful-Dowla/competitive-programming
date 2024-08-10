/*
https://atcoder.jp/contests/abc365/tasks/abc365_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n;
	cin >> n;

	vector<ll> pf(n + 1, 0), v(n + 1);

	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
		pf[i] = pf[i - 1] ^ v[i];
	}

	vector<ll> one(31, 0), zero(31, 0);
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j < 31; ++j) {
			if (pf[i] & (1LL << j)) {
				one[j]++;
			}
			else {
				zero[j]++;
			}
		}
	}

	ll ans = 0;
	for (int i = 0; i < 31; ++i) {
		ans += zero[i] * one[i] * (1LL << i);
	}

	for (int i = 1; i <= n; ++i) {
		ans -= v[i];
	}

	cout << ans << endl;
}