//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1993/problem/A
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {

	int n;
	cin >> n;

	string s;
	cin >> s;

	map<char, int> mp;
	for (char ch : s) {
		mp[ch]++;
	}

	string p = "ABCD";
	int ans = 0;
	for (char ch : p) {
		if (mp[ch] > 0) {
			ans += min(n, mp[ch]);
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