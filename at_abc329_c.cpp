/*
https://atcoder.jp/contests/abc329/tasks/abc329_c
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<pair<char, int>> vec;

	for (int i = 0; i < n; ++i) {

		if (vec.empty() || vec.back().first != s[i]) {
			vec.push_back({s[i], 1});
		}
		else {
			vec.back().second++;
		}
	}


	int ans = 0;
	unordered_map<char, int> mp;
	for (auto p : vec) {

		char ch = p.first;
		int cnt = p.second;

		if (cnt > mp[ch]) {
			ans += (cnt - mp[ch]);
			mp[ch] = cnt;
		}
	}

	cout << ans << endl;
}