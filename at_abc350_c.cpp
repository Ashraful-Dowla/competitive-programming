/*
https://atcoder.jp/contests/abc350/tasks/abc350_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> v(n + 2);
	map<int, int> mp;

	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
		mp[v[i]] = i;
	}

	vector<pair<int, int>> ans;
	for (int i = 1; i <= n; ++i) {
		if (i != v[i]) {
			int idx = mp[i];
			swap(v[i], v[idx]);
			mp[v[idx]] = idx;
			ans.push_back({i, idx});
		}
	}

	cout << ans.size() << endl;
	for (auto p : ans) {
		cout << p.first << " " << p.second << endl;
	}
}