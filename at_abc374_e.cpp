/*
https://atcoder.jp/contests/abc374/tasks/abc374_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18 + 1;

int main() {

	int n;
	ll yen;
	cin >> n >> yen;

	ll a[n], p[n], b[n], q[n];

	for (int i = 0; i < n; ++i) {

		cin >> a[i] >> p[i] >> b[i] >> q[i];

		if (b[i]*p[i] > a[i]*q[i]) {
			swap(a[i], b[i]);
			swap(p[i], q[i]);
		}
	}

	ll lo = 0, hi = 2e9 + 1;
	while (hi - lo > 1) {

		ll mid = (lo + hi) / 2;

		ll sum = 0;

		for (int i = 0; i < n; ++i) {
			ll mn_yen = INF;
			for (int j = 0; j < 101; ++j) {

				ll rem = mid - j * b[i];
				ll curr_yen = j * q[i];

				if (rem > 0) {
					ll k = (rem + a[i] - 1) / a[i];
					curr_yen += k * p[i];
				}

				mn_yen = min(mn_yen, curr_yen);
			}
			sum += mn_yen;
			sum = min(sum, INF);
		}

		if (sum <= yen) {
			lo = mid;
		}
		else {
			hi = mid;
		}
	}

	cout << lo << endl;

}