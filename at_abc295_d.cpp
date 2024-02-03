/*
https://atcoder.jp/contests/abc295/tasks/abc295_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	string s;
	cin >> s;

	vector<int> cnt(10, 0);
	map<vector<int>, ll>mp;

	mp[cnt]++;

	for (char ch : s) {
		cnt[ch - '0']++;
		cnt[ch - '0'] %= 2;
		mp[cnt]++;
	}

	ll ans = 0;
	for (auto p : mp) {
		ans += p.second * (p.second - 1) / 2;
	}

	cout << ans << endl;
}