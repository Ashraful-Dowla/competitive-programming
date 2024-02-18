/*
https://atcoder.jp/contests/abc339/tasks/abc339_f
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll M1 = 998244353;
const ll M2 = 998242355;
const int N = 1005;

ll v1[N], v2[N];
map<ll, ll> mp1, mp2;

void solve(int i, string s) {

	ll res1 = 0, res2 = 0;

	for (char ch : s) {
		res1 = res1 * 10 + (ch - '0');
		res1 %= M1;

		res2 = res2 * 10 + (ch - '0');
		res2 %= M2;
	}

	v1[i] = res1;
	v2[i] = res2;

	mp1[res1]++;
	mp2[res2]++;
}

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		solve(i, s);
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ll p1 = (v1[i] * v1[j]) % M1;
			ll p2 = (v2[i] * v2[j]) % M2;
			ans += min(mp1[p1], mp2[p2]);
		}
	}

	cout << ans << endl;
}