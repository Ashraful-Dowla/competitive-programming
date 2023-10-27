/*
https://atcoder.jp/contests/abc325/tasks/abc325_b
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n;
	cin >> n;

	vector<pair<int, int>> vec;

	for (int i = 0; i < n; ++i) {
		int w, x;
		cin >> w >> x;
		vec.push_back({w, x});
	}

	ll ans = 0;
	for (int i = 0; i <= 24; ++i) {

		ll res = 0;
		for (auto v : vec) {
			int st = (i + v.second) % 24;
			int nd = (i + v.second + 1) % 24;

			if (9 <= st && nd <= 18 && st < nd) {
				res += v.first;
			}
		}

		ans = max(ans, res);
	}

	cout << ans << endl;
}