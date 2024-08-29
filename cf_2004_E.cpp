//Author: Ashraful Dowla

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int mex(set<int>& s) {

	int res = 0;
	while (s.count(res)) {
		res++;
	}

	return res;
}

void brute(int mx) {

	vector<int> grundy(mx + 1);
	for (int x = 1; x <= mx; ++x) {
		set<int> s;
		for (int y = 1; y <= x; ++y) {
			if (__gcd(x, y) == 1) {
				s.insert(grundy[x - y]);
			}
		}
		grundy[x] = mex(s);
	}

	// for (int i = 1; i <= mx; ++i) {
	// 	cout << i << " " << grundy[i] << endl;
	// }

}

typedef long long ll;
const int N = 1e7 + 1;
vector<ll> grundy(N, 0);

void precompute() {

	grundy[1] = 1;

	for (ll i = 3, c = 2; i < N; i += 2) {

		if (grundy[i]) {
			continue;
		}

		grundy[i] = c++;

		for (ll j = i * i; j < N; j += 2 * i) {
			if (grundy[j] == 0) {
				grundy[j] = grundy[i];
			}
		}
	}

}

void solve() {

	int n;
	cin >> n;

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		ll curr = grundy[x];
		ans ^= curr;
	}

	cout << (ans ? "Alice" : "Bob") << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	// brute(100);
	precompute();

	while (t--) {
		solve();
	}
}