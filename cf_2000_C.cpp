//Author: Ashraful Dowla
/*
https://codeforces.com/contest/2000/problem/C
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {

	int n;
	cin >> n;

	vector<int>v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	int q;
	cin >> q;

	while (q--) {
		map<char, int> mp;

		string s;
		cin >> s;

		if (s.size() != n) {
			cout << "NO" << endl;
			continue;
		}

		bool ok = true;
		for (int i = 0; i < n; ++i) {
			char ch = s[i];

			if (mp.find(ch) == mp.end()) {
				mp[ch] = v[i];
			}
			else if (mp[ch] != v[i]) {
				ok = false;
				break;
			}
		}

		if (!ok) {
			cout << "NO" << endl;
			continue;
		}

		ok = true;
		map<int, char> mp2;
		for (int i = 0; i < n; ++i) {
			if (mp2.find(v[i]) == mp2.end()) {
				mp2[v[i]] = s[i];
			}
			else if (mp2[v[i]] != s[i]) {
				ok = false;
				break;
			}
		}

		cout << (ok ? "YES" : "NO") << endl;
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