/*
https://atcoder.jp/contests/abc367/tasks/abc367_f
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

mt19937_64 mrand(random_device{}());

int main() {

	int n, q;
	cin >> n >> q;

	vector<ll> hsh(n + 1);
	for (int i = 1; i <= n; ++i) {
		hsh[i] = mrand();
	}

	vector<ll> a(n + 1), b(n + 1), pf_a(n + 1, 0), pf_b(n + 1, 0);;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pf_a[i] = pf_a[i - 1] + hsh[a[i]];
	}

	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		pf_b[i] = pf_b[i - 1] + hsh[b[i]];
	}

	while (q--) {
		int l, r, L, R;
		cin >> l >> r >> L >> R;

		ll sum_a = pf_a[r] - pf_a[l - 1];
		ll sum_b = pf_b[R] - pf_b[L - 1];

		if (sum_a == sum_b) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
}