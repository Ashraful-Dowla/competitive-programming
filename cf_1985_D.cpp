//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1985/problem/D
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {

	int n, m;
	cin >> n >> m;

	char ch[n + 1][m + 1];

	int mnx = INT_MAX, mxx = 0, mny = INT_MAX, mxy = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> ch[i][j];

			if (ch[i][j] == '#') {
				mnx = min(mnx, i);
				mxx = max(mxx, i);

				mny = min(mny, j);
				mxy = max(mxy, j);
			}
		}
	}

	cout << (mnx + mxx) / 2 << " " << (mny + mxy) / 2 << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}