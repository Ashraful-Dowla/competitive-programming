/*
https://atcoder.jp/contests/abc375/tasks/abc375_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	string s;
	cin >> s;

	int n = s.size();
	s = '_' + s;

	vector<vector<int>> pf(n + 2, vector<int>(26, 0));
	vector<vector<int>> sf(n + 2, vector<int>(26, 0));


	for (int i = 1; i <= n; ++i) {
		pf[i][s[i] - 'A']++;
	}

	for (int i = n; i >= 1; --i) {
		sf[i][s[i] - 'A']++;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 26; ++j) {
			pf[i][j] += pf[i - 1][j];
		}
	}

	for (int i = n; i >= 1; --i) {
		for (int j = 0; j < 26; ++j) {
			sf[i][j] += sf[i + 1][j];
		}
	}

	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 26; ++j) {
			ans += pf[i - 1][j] * 1LL * sf[i + 1][j];
		}
	}

	cout << ans << endl;
}