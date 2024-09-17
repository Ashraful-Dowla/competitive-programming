/*
https://atcoder.jp/contests/abc369/tasks/abc369_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	map<char, int> mp;

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		char ch;
		cin >> a >> ch;

		if (mp.find(ch) == mp.end()) {
			mp[ch] = a;
		}
		else {
			ans += abs(mp[ch] - a);
			mp[ch] = a;
		}
	}

	cout << ans << endl;
}