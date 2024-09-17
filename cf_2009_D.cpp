//Author: Ashraful Dowla
/*
https://codeforces.com/contest/2009/problem/D
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long ll;

void solve() {

	int n;
	cin >> n;
	vector<vector<bool>> v(n + 5, vector<bool>(2, false));

	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;

		v[x][y] = true;
	}

	ll ans = 0;
	for (int i = 0; i <= n; ++i) {
		if (v[i][0] && v[i][1]) {
			ans += n - 2;
		}
		if (v[i][0] && v[i + 1][1] && v[i + 2][0]) {
			ans++;
		}
		if (i > 0 && v[i][0] && v[i - 1][1] && v[i + 1][1]) {
			ans++;
		}
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