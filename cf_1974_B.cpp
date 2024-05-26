//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1974/problem/B
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

	vector<char>v;
	for (char ch : s) {
		v.push_back(ch);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	int l = 0, r = v.size() - 1;

	unordered_map<char, char>mp;

	while (l <= r) {
		mp[v[l]] = v[r];
		mp[v[r]] = v[l];

		l++, r--;
	}

	for (char ch : s) {
		cout << mp[ch];
	}
	cout << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}