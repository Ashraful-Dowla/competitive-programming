/*
https://atcoder.jp/contests/abc286/tasks/abc286_c
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e18;

int main() {

	int n;
	ll a, b;
	cin >> n >> a >> b;

	string s;
	cin >> s;

	s += s;

	ll ans = INF;
	for (int i = 0; i < n; ++i) {

		int lo = i, hi = i + n - 1;
		ll len = 0;

		while (lo < hi) {
			if (s[lo] != s[hi]) {
				len += b;
			}
			lo++, hi--;
		}

		ans = min(ans, a * i + len);
	}

	cout << ans << endl;
}