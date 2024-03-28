/*
https://atcoder.jp/contests/abc346/tasks/abc346_e
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;

int main() {

	int h, w, m;
	cin >> h >> w >> m;

	int t[m], a[m], x[m];

	for (int i = 0; i < m; ++i) {
		cin >> t[i] >> a[i] >> x[i];
	}

	vector<ll> cnt(N);
	vector<bool> row(N), col(N);
	for (int i = m - 1; i >= 0; --i) {

		if (t[i] == 1) {
			if (!row[a[i]]) {
				h--;
				row[a[i]] = true;
				cnt[x[i]] += w;
			}
		}
		else {
			if (!col[a[i]]) {
				w--;
				col[a[i]] = true;
				cnt[x[i]] += h;
			}
		}
	}

	cnt[0] += h * 1LL * w;

	vector<pair<int, ll>> ans;
	for (int i = 0; i < N; ++i) {
		if (cnt[i]) {
			ans.push_back({i, cnt[i]});
		}
	}

	cout << ans.size() << endl;
	for (auto p : ans) {
		cout << p.first << " " << p.second << endl;
	}
}