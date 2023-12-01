/*
https://atcoder.jp/contests/abc311/tasks/abc311_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	string s;
	cin >> s;

	unordered_map<char, bool> mp;

	for (int i = 0; i < n; ++i) {

		mp[s[i]] = true;

		if (mp['A'] && mp['B'] && mp['C']) {
			cout << i + 1 << endl;
			break;
		}
	}
}