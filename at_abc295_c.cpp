/*
https://atcoder.jp/contests/abc295/tasks/abc295_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n;
	cin >> n;

	map<ll, int> mp;

	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;

		mp[x]++;
	}

	ll res = 0;
	for (auto p : mp) {
		res += p.second / 2;
	}

	cout << res << endl;
}