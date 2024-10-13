/*
https://atcoder.jp/contests/abc371/tasks/abc371_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n;
	cin >> n;

	map<int, vector<int>> mp;

	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		mp[a].push_back(i);
	}

	ll total = (n * 1LL * (n + 1)) / 2;
	ll ans = 0;

	for (auto x : mp) {

		vector<int> v = x.second;
		v.push_back(n);

		int p = -1;
		ll cnt = 0;
		for (int j = 0; j < v.size(); ++j) {
			ll d = v[j] - p - 1;
			cnt += (d * (d + 1)) / 2;
			p = v[j];
		}

		ans += total - cnt;
	}

	cout << ans << endl;
}
