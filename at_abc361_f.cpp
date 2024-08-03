/*
https://atcoder.jp/contests/abc361/tasks/abc361_f
*/
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
const int N = 1e6;

int main() {

	ll n;
	cin >> n;

	ll ans = sqrtl(n);

	set<ll> s;
	for (int i = 2; i <= N; ++i) {
		s.insert(i);
	}

	for (ll i = 2; i * i * i <= n; ++i) {

		if (s.find(i) == s.end()) {
			continue;
		}

		ll curr = i, pw = 1;
		while (curr <= n) {

			if (pw >= 3 && (pw & 1LL)) {
				ans++;
			}

			if (curr > n / i) {
				break;
			}

			curr *= i;
			pw++;
			s.erase(curr);
		}
	}

	cout << ans << endl;
}