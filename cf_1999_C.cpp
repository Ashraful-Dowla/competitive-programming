//Author: Ashraful Dowla

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {
	int n, s, m;
	cin >> n >> s >> m;

	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].first >> v[i].second;
	}

	int mx = v[0].first;
	for (int i = 1; i < n; ++i) {
		mx = max(mx, v[i].first - v[i - 1].second);
	}
	mx = max(mx, m - v[n - 1].second);
	cout << (s <= mx ? "YES" : "NO") << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}