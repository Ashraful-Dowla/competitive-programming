//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1997/problem/B
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {

	int n;
	cin >> n;

	char ch[2][n];
	vector<int> ct(n);
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> ch[i][j];
			if (ch[i][j] == '.') {
				ct[j]++;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i + 1 < n; ++i) {
		if (ct[i] == 2 && ct[i - 1] == 1 && ct[i + 1] == 1) {
			if ((ch[0][i - 1] == 'x' && ch[0][i + 1] == 'x') ||
			        ch[1][i - 1] == 'x' && ch[1][i + 1] == 'x') {
				ans++;
			}
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