//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1971/problem/B
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {

	string s;
	cin >> s;

	for (int i = 0; i < s.size(); ++i) {
		for (int j = i + 1; j < s.size(); ++j) {
			if (s[i] != s[j]) {
				swap(s[i], s[j]);
				cout << "YES" << endl;
				cout << s << endl;
				return ;
			}
		}
	}

	cout << "NO" << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}