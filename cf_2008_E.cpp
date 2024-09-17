//Author: Ashraful Dowla
/*
https://codeforces.com/problemset/problem/2008/E
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long ll;

void solve() {

	int n;
	cin >> n;

	string s;
	cin >> s;


	if (n % 2 == 0) {

		map<char, int> e, o;
		int mxe = 0, mxo = 0;

		for (int i = 0; i < n; ++i) {
			if (i % 2 == 0) {
				e[s[i]]++;
				mxe = max(mxe, e[s[i]]);
			}
			else {
				o[s[i]]++;
				mxo = max(mxo, o[s[i]]);
			}
		}

		cout << n - mxe - mxo << endl;
	}
	else {

		vector<vector<int>> pfe(n + 1, vector<int>(26, 0));
		vector<vector<int>> pfo(n + 1, vector<int>(26, 0));

		s = '_' + s;

		for (int i = 1; i <= n; ++i) {
			if (i % 2 == 0) {
				pfe[i][s[i] - 'a']++;
			}
			else {
				pfo[i][s[i] - 'a']++;
			}
		}

		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < 26; ++j) {
				pfe[i][j] += pfe[i - 1][j];
				pfo[i][j] += pfo[i - 1][j];
			}
		}

		int ans = n;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < 26; ++j) {
				int mxe = pfe[i - 1][j] + pfo[n][j] - pfo[i][j];
				for (int k = 0; k < 26; ++k) {
					int mxo = pfo[i - 1][k] + pfe[n][k] - pfe[i][k];
					ans = min(ans, n - mxe - mxo);
				}
			}
		}

		cout << ans << endl;
	}
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}