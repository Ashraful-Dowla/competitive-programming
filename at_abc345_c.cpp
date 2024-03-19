/*
https://atcoder.jp/contests/abc345/tasks/abc345_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	string s;
	cin >> s;

	unordered_map<char, int> ct;

	ll ans = 0;
	for (char ch : s) {
		ct[ch]++;
		if (ct[ch] > 1) {
			ans = 1;
		}
	}

	for (int i = 0; i < s.size(); ++i) {
		for (char ch = 'a'; ch <= 'z'; ++ch) {
			if (s[i] != ch) {
				ans += ct[ch];
			}
		}
		ct[s[i]]--;
	}


	cout << ans << endl;
}