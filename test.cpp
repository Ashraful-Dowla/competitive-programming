#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int pf[30][N];

void clr(int n) {
	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j <= n; ++j) {
			pf[i][j] = 0;
		}
	}
}

void solve() {

	string s;
	cin >> s;

	int n = s.size();
	s = "_" + s;

	clr(n);

	unordered_map<char, int> mp;

	for (int i = 1; i <= n; ++i) {
		pf[s[i] - 'a'][i]++;
		mp[s[i]]++;
	}

	for (int i = 0; i < 26; ++i) {
		for (int j = 1; j <= n; ++j) {
			pf[i][j] += pf[i][j - 1];
		}
	}

	int ans = 1e6;
	for (char ch = 'a'; ch <= 'z'; ++ch) {
		if (mp[ch] > 0) {
			int k = mp[ch];
			for (int i = k; i <= n; ++i) {
				int len = pf[ch - 'a'][i] - pf[ch - 'a'][i - k];
				ans = min(ans, k - len);
			}
		}
	}

	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}
