/*
https://atcoder.jp/contests/abc315/tasks/abc315_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

bool cmp(pll a, pll b) {
	return a.second > b.second;
}

int main() {

	int n;
	cin >> n;

	unordered_map<ll, ll> mx, sec_mx;
	vector<pll> vec;

	for (int i = 0; i < n; ++i) {
		ll f, s;
		cin >> f >> s;
		vec.push_back({f, s});
	}

	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < n; ++i) {

		ll f = vec[i].first;
		ll s = vec[i].second;

		if (mx[f] == 0) {
			mx[f] = s;
		}
		else {
			sec_mx[f] = max(sec_mx[f], s / 2);
		}
	}


	ll f = vec[0].first, ans = 0;

	for (int i = 1; i < n; ++i) {
		if (vec[i].first == f) continue;
		ans = max(ans, vec[i].second + mx[f]);
	}

	ans = max(ans, mx[f] + sec_mx[f]);
	cout << ans << endl;
}