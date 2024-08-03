/*
https://atcoder.jp/contests/agc005/tasks/agc005_b
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(vector<int>& a) {

	int n = a.size();
	set<pair<int, int>> s;

	for (int i = 0; i < n; ++i) {
		s.insert({a[i], i});
	}

	vector<int> nse(n), pse(n);
	set<int> alive;

	for (auto p : s) {
		int idx = p.second;
		auto it = alive.upper_bound(idx);

		if (it != alive.end()) {
			nse[idx] = *it;
		}
		else {
			nse[idx] = n;
		}

		if (it != alive.begin()) {
			--it;
			pse[idx] = *it;
		}
		else {
			pse[idx] = -1;
		}

		alive.insert(idx);
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += a[i] * 1LL * (i - pse[i]) * 1LL * (nse[i] - i);
	}

	return ans;
}

int main() {

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	cout << solve(a) << endl;
}