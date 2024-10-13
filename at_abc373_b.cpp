/*
https://atcoder.jp/contests/abc373/tasks/abc373_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	vector<pair<char, int>> v;
	for (int i = 0; i < s.size(); ++i) {
		v.push_back({s[i], i});
	}

	sort(v.begin(), v.end());

	int ans = 0;
	for (int i = 1; i < v.size(); ++i) {
		ans += abs(v[i].second - v[i - 1].second);
	}
	cout << ans << endl;
}