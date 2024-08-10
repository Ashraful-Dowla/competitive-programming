#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(vector<ll>& v) {

	int n = v.size();
	vector<ll> pf(n + 1, 0);

	for (int i = 1; i <= n; ++i) {
		pf[i] = pf[i - 1] ^ v[i - 1];
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

	return ans;
}

int main() {

	// vector<ll> a = {1, 3, 7, 9, 8, 7};
	vector<ll> a = {3, 8, 13};
	cout << solve(a) << endl;
	return 0;
}
