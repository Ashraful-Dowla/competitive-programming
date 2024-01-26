/*
https://cses.fi/problemset/task/1629/
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

bool cmp(pii a, pii b) {
	return a.second < b.second;
}

int main() {

	int n;
	cin >> n;

	vector<pii> v(n);

	for (int i = 0; i < n; ++i) {
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end(), cmp);

	int ans = 1, nd = v[0].second;
	for (int i = 1; i < n; ++i) {
		if (nd <= v[i].first) {
			nd = v[i].second;
			ans++;
		}
		else {
			nd = min(nd, v[i].second);
		}
	}

	cout << ans << endl;
}