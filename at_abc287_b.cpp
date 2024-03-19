/*
https://atcoder.jp/contests/abc287/tasks/abc287_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<string> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	map<string, bool> mp;
	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s;
		
		mp[s] = true;
	}

	int ans = 0;
	for (string s : v) {
		ans += mp[s.substr(3, 3)];
	}

	cout << ans << endl;
}