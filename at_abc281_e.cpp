/*
https://atcoder.jp/contests/abc281/tasks/abc281_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> v(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}

	ll ans = 0;
	multiset<int> now;
	for (int i = 1; i <= m; ++i) {
		now.insert(v[i]);
		ans += v[i];
	}

	multiset<int> res;
	for (int i = 0; i < m - k; ++i) {
		int val = *now.rbegin();
		res.insert(val);
		now.erase(now.find(val));
		ans -= val;
	}

	cout << ans << " ";
	for (int i = m + 1; i <= n; ++i) {

		auto it = now.find(v[i - m]);

		if (it != now.end()) {
			now.erase(it);
			ans -= v[i - m];
		}
		else {
			res.erase(res.find(v[i - m]));
		}

		now.insert(v[i]);
		ans += v[i];

		if (now.size() == k) {
			if (res.size() > 0) {
				auto nw = (--now.end());
				auto rs = res.begin();

				if (*nw > *rs) {
					ans -= *nw;
					ans += *rs;

					now.insert(*rs);
					res.insert(*nw);

					now.erase(nw);
					res.erase(rs);
				}
			}
		}
		else {
			auto nw = (--now.end());
			ans -= *nw;
			res.insert(*nw);
			now.erase(nw);
		}

		cout << ans << " ";
	}
}