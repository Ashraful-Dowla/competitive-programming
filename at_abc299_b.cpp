/*
https://atcoder.jp/contests/abc299/tasks/abc299_b
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

bool cmp(pii a, pii b) {
	return a.first > b.first;
}

int main() {

	int n, t;
	cin >> n >> t;

	int c[n], r[n];

	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}

	map<int, vector<pii>> mp;

	for (int i = 0; i < n; ++i) {
		cin >> r[i];
		mp[c[i]].push_back({r[i], i + 1});
	}

	if (mp[t].size()) {
		sort(mp[t].begin(), mp[t].end(), cmp);
		cout << mp[t][0].second << endl;
	}
	else {
		sort(mp[c[0]].begin(), mp[c[0]].end(), cmp);
		cout << mp[c[0]][0].second << endl;
	}
}