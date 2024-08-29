/*
https://atcoder.jp/contests/abc368/tasks/abc368_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n;
	cin >> n;

	vector<ll> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	ll ans = 0;
	queue<ll> q;
	for (int i = 0; i < n; ++i) {

		while (!q.empty()) {
			ll x = q.front();
			q.pop();

			v[i] -= x;
			ans++;
			if (v[i] <= 0) {
				i++;
			}
		}

		ll t = v[i] / 5;
		ans += 3 * t;

		ll rem = v[i] % 5;
		if (rem > 2) {
			ans += 3;
		}
		else {
			ans += rem;
			if (rem == 1) {
				q.push(1);
				q.push(3);
			}
			else if (rem == 2) {
				q.push(3);
			}
		}
	}

	cout << ans << endl;
}