//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1999/problem/D
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {

	string s, t;
	cin >> s;
	cin >> t;

	int j = 0;
	for (int i = 0; i < s.size() && j < t.size(); ++i) {
		if (s[i] == '?' || s[i] == t[j]) {
			s[i] = t[j++];
		}
	}

	if (j != t.size()) {
		cout << "NO" << endl;
		return ;
	}

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '?') {
			s[i] = 'a';
		}
	}

	cout << "YES" << endl;
	cout << s << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}