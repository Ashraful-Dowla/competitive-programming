#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;
int n;
ll f[N], a[N];

void add(int l, int r, ll val) {

	if (l < 0 || r >= n || l > r) {
		return;
	}

	f[l] += val;
	if (r + 1 < n) {
		f[r + 1] -= val;
	}
}

ll solve() {

	set<pair<ll, int>> s;
	for (int i = 0; i < n; ++i) {
		s.insert({a[i], i});
	}

	set<int> alive;
	for (auto p : s) {
		int idx = p.second;

		int R = n;
		auto rit = alive.upper_bound(idx);
		if (rit != alive.end()) {
			R = *rit;
		}

		int L = -1;
		auto lit = alive.upper_bound(idx);
		if (lit != alive.begin()) {
			lit--;
			L = *lit;
		}

		ll A = idx - L;
		ll B = R - idx;
		ll x  = a[idx];


		// ....L.....i.....R....
		//  r1    r2  	r3   r4

		// region
		add(0, L - 1, A * B * x); // r1
		add(R + 1, n, A * B * x); // r4
		add(L + 1, idx - 1, (A - 1)*B * x); // r2
		add(idx + 1, R - 1, A * (B - 1)*x); // r3

		int RR = n;
		if (R < n) {
			rit++;
			if (rit != alive.begin()) {
				RR = *rit;
			}
		}

		int LL = -1;
		if (L >= 0) {
			lit--;
			if (lit != alive.begin()) {
				LL = *lit;
			}
		}

		// partition
		// ..LL....L.....i.....R....RR...
	   
		ll P = idx - LL - 1;
		ll Q = RR - idx - 1;

		add(L, L, P * B * x);
		add(R, R, A * Q * x);

		alive.insert(idx);
	}
}


int main() {

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}


	solve();

	for (int i = 1; i < n; ++i) {
		f[i] += f[i - 1];
	}

	for (int i = 0; i < n; ++i) {
		cout << f[i] << " ";
	}
}