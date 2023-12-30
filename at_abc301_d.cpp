/*
https://atcoder.jp/contests/abc301/tasks/abc301_d
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	string s;
	ll n;

	cin >> s;
	cin >> n;

	int sz = s.size();
	ll res = 0;

	for (int i = 0; i < sz; ++i) {
		if (s[i] == '1') {
			res |= (1LL << (sz - i - 1));
		}
	}

	if (res > n) {
		cout << -1 << endl;
	}
	else {
		for (int i = 0; i < sz; ++i) {
			if (s[i] == '?' && (res | (1LL << (sz - i - 1))) <= n) {
				res |= (1LL << (sz - i - 1));
			}
		}
		cout << res << endl;
	}
}