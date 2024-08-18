//Author: Ashraful Dowla
/*
https://codeforces.com/contest/2000/problem/E
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long ll;

bool cmp(ll a, ll b) {
	return a > b;
}

void solve() {

	int n, m, k;
	cin >> n >> m >> k;

	int w;
	cin >> w;

	vector<ll>a(w);
	for (int i = 0; i < w; ++i) {
		cin >> a[i];
	}

	vector<vector<ll>>v(n + 2, vector<ll>(m + 2, 0));
	for (int i = 1; i + k - 1 <= n; ++i) {
		for (int j = 1; j + k - 1 <= m; ++j) {
			v[i][j]++;
			v[i + k][j]--;
			v[i][j + k]--;
			v[i + k][j + k]++;
		}
	}

	vector<ll> q;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			v[i][j] += v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
			q.push_back(v[i][j]);
		}
	}

	sort(q.begin(), q.end(), cmp);
	sort(a.begin(), a.end(), cmp);

	ll ans = 0;
	for (int i = 0; i < w; ++i) {
		ans += a[i] * q[i];
	}

	cout << ans << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}